#include <wx/wx.h>
#include "MainFrame.h"
#include <iostream>
#include <wx/bmpbuttn.h>
#include <wx/wrapsizer.h>
#include "types.h"
#include <wx/stdpaths.h>
#include <wx/filename.h>

using std::cout; using std::endl;
using std::vector; using std::string;

int button_size_x = 60;
int button_size_y = 30;

enum IDs // used for event handling
{
    CHOICE_TYPE1_ID = 2,
    CHOICE_TYPE2_ID = 3  
};

wxBEGIN_EVENT_TABLE(MainFrame, wxFrame)
    EVT_CHOICE(CHOICE_TYPE1_ID, MainFrame::OnChoiceMade1)
    EVT_CHOICE(CHOICE_TYPE2_ID, MainFrame::OnChoiceMade2)
wxEND_EVENT_TABLE()

std::vector<std::string> type_names1 = {"", "Bug", "Dark", "Dragon", "Electric", "Fighting", "Fire", "Flying", "Ghost", "Grass", "Ground", "Ice", "Normal",
                                       "Poison", "Psychic", "Rock", "Steel", "Water"};


MainFrame::MainFrame(const wxString& title, const wxPoint& pos, const wxSize& size):wxFrame(nullptr, wxID_ANY, title, pos, size)
{
    
    //wxPanel* panel = new wxPanel(this);
    wxArrayString types = {"NONE", "BUG", "DARK", "DRAGON", "ELECTRIC", "FIGHTING", "FIRE", "FLYING", "GHOST", "GRASS", "GROUND", "ICE", "NORMAL",
                           "POISON", "PSYCHIC", "ROCK", "STEEL", "WATER"};
    
    wxFont damageFont(wxFontInfo(wxSize(0, 18)).Bold());
    //CreateStatusBar();

    // Box and Wrap sizers for all damage types
    wxBoxSizer* mainBoxSizer = new wxBoxSizer(wxVERTICAL);
    wxBoxSizer* typeBoxSizer = new wxBoxSizer(wxHORIZONTAL);
    wxBoxSizer* fourXTextSizer = new wxBoxSizer(wxHORIZONTAL);   
    wxBoxSizer* twoXTextSizer = new wxBoxSizer(wxHORIZONTAL);   
    wxBoxSizer* oneXTextSizer = new wxBoxSizer(wxHORIZONTAL);   
    wxBoxSizer* halfXTextSizer = new wxBoxSizer(wxHORIZONTAL);   
    wxBoxSizer* quarterXTextSizer = new wxBoxSizer(wxHORIZONTAL);   
    wxBoxSizer* zeroXTextSizer = new wxBoxSizer(wxHORIZONTAL);   

    //typeBoxSizer components
    wxChoice* type1 = new wxChoice(panel, CHOICE_TYPE1_ID, wxDefaultPosition, wxSize(100,-1), types);
    wxChoice* type2 = new wxChoice(panel, CHOICE_TYPE2_ID, wxDefaultPosition, wxSize(100, -1), types);
    type1->Select(0);
    type2->Select(0);
    wxSizerFlags flags = wxSizerFlags().CenterVertical().Top().Border(wxALL, 25);
    typeBoxSizer->Add(type1,flags);
    typeBoxSizer->Add(type2,  flags);

    // fourXTextSizer components
    wxStaticText* fourXText = new wxStaticText(panel, wxID_ANY, "4x Damage");
    fourXTextSizer->Add(fourXText);

    // 2XTextSizer components
    wxStaticText* twoXText = new wxStaticText(panel, wxID_ANY, "2x Damage");
    twoXTextSizer->Add(twoXText);

    // oneXTextSizer components
    wxStaticText* oneXText = new wxStaticText(panel, wxID_ANY, "1x Damage");
    oneXTextSizer->Add(oneXText);

    // halfXTextSizer components
    wxStaticText* halfXText = new wxStaticText(panel, wxID_ANY, "1/2x Damage");
    halfXTextSizer->Add(halfXText);

    // quarterXTextSizer components
    wxStaticText* quarterXText = new wxStaticText(panel, wxID_ANY, "1/4x Damage");
    quarterXTextSizer->Add(quarterXText);

    wxStaticText* zeroXText = new wxStaticText(panel, wxID_ANY, "0x Damage");
    zeroXTextSizer->Add(zeroXText);

    // add layout to mainBoxSizer
    mainBoxSizer->Add(typeBoxSizer);
    mainBoxSizer->Add(fourXTextSizer);
    mainBoxSizer->Add(fourXWrap);
    mainBoxSizer->Add(twoXTextSizer);
    mainBoxSizer->Add(twoXWrap);
    mainBoxSizer->Add(oneXTextSizer);
    mainBoxSizer->Add(oneXWrap);
    mainBoxSizer->Add(halfXTextSizer);
    mainBoxSizer->Add(halfXWrap);
    mainBoxSizer->Add(quarterXTextSizer);
    mainBoxSizer->Add(quarterXWrap);
    mainBoxSizer->Add(zeroXTextSizer);
    mainBoxSizer->Add(zeroXWrap);
    //panel->SetSizerAndFit(mainBoxSizer);
    panel->SetSizer(mainBoxSizer);
    mainBoxSizer->SetSizeHints(this);
    mainBoxSizer->Layout();

    

}

void MainFrame::OnChoiceMade1(wxCommandEvent& evt)
{
    first_type_selection = evt.GetSelection();
    if(first_type_selection == 0 && second_type_selection != 0)
    {
        first_type_selection = second_type_selection;
        poke.set_type2(types[0]); // types[0] = None
        poke.set_type1(types[first_type_selection]);
    }
    else
    {
        poke.set_type1(types[first_type_selection]);
        poke.set_type2(types[second_type_selection]);
    }
    
    poke.calc_immunities(); // always call this one first
    poke.calc_weaknesses();
    poke.calc_resistances();
    poke.calc_neutral();  

    this->populate_fourX();
    this->populate_twoX();
    this->populate_oneX();
    this->populate_halfX();
    this->populate_quarterX();
    this->populate_zeroX();

    this->depopulate_WrapSizers();
    panel->Refresh();                          // Is this line needed?
    this->populate_WrapSizers();
    panel->Layout();
}

void MainFrame::OnChoiceMade2(wxCommandEvent& evt)
{

    second_type_selection = evt.GetSelection();
    if(first_type_selection ==0 && second_type_selection !=0)
    {
        first_type_selection = second_type_selection;
        poke.set_type2(types[0]); // Type = None
        poke.set_type1(types[first_type_selection]);
    }
    else
    {
        poke.set_type2(types[second_type_selection]);
        poke.set_type1(types[first_type_selection]);
    }
    
    poke.calc_immunities(); // always call this one first
    poke.calc_weaknesses();
    poke.calc_resistances();
    poke.calc_neutral();  

    this->populate_fourX();
    this->populate_twoX();
    this->populate_oneX();
    this->populate_halfX();
    this->populate_quarterX();
    this->populate_zeroX();

    this->depopulate_WrapSizers();
    panel->Refresh();                       // Is this line needed?
    this->populate_WrapSizers();
    panel->Layout();
}

// return -1 if element not found
vector<string>::size_type getIndex(vector<string>& v, string s)
{
    vector<string>::iterator it = find(v.begin(), v.end(), s);

    //element found
    if(it != v.end())
    {
        vector<string>::size_type index = it - v.begin();
        return index;
    }

    return -1;
}

void MainFrame::populate_fourX()
{   
    depopulate_vector_bitmapbutton(fourX);
    fourX.clear();

    wxString fpath = wxStandardPaths::Get().GetDataDir();
    wxLogStatus(fpath);
    for(vector<string>::iterator it = poke.FourXWeakness.begin(); it!= poke.FourXWeakness.end(); it++)
    {   
        //string name = *it;
        vector<string>::size_type index = getIndex(type_names1, *it);
        if (fileNames[index] == "")
            continue;
        //string file = "TypeIcons\\" + fileNames[index];
        wxString file = fpath + "\\TypeIcons\\" + fileNames[index];
        wxLogStatus(file);
        wxImage* temp_img = new wxImage(file, wxBITMAP_TYPE_PNG);
        (*temp_img).Rescale(button_size_x, button_size_y, wxIMAGE_QUALITY_NORMAL);
        wxBitmapButton* temp_button = new wxBitmapButton(panel, wxID_ANY, wxBitmap(*temp_img, -1));
        fourX.push_back(temp_button);
    }
    fourXWrap->Layout();
}

void MainFrame::populate_twoX()
{   
    depopulate_vector_bitmapbutton(twoX);
    twoX.clear();
    wxString fpath = wxStandardPaths::Get().GetDataDir();
    wxLogStatus(fpath);
    for(vector<string>::iterator it = poke.TwoXWeakness.begin(); it!= poke.TwoXWeakness.end(); it++)
    {   
        //string name = *it;
        vector<string>::size_type index = getIndex(type_names1, *it);
        if (fileNames[index] == "")
            continue;
        //string file = "TypeIcons\\" + fileNames[index];
        wxString file = fpath + "\\TypeIcons\\" + fileNames[index];
        wxLogStatus(file);
        wxImage* temp_img = new wxImage(file, wxBITMAP_TYPE_PNG);
        (*temp_img).Rescale(button_size_x, button_size_y, wxIMAGE_QUALITY_NORMAL);
        wxBitmapButton* temp_button = new wxBitmapButton(panel, wxID_ANY, wxBitmap(*temp_img, -1));
        twoX.push_back(temp_button);
    }
    if (count_hold_img == 0)
    {
        hold_img = twoX[0];
        count_hold_img++;
    }
     
    twoXWrap->Layout();

}

void MainFrame::populate_oneX()
{   
    depopulate_vector_bitmapbutton(oneX);
    oneX.clear();

    wxString fpath = wxStandardPaths::Get().GetDataDir();
    wxLogStatus(fpath);
    for(vector<string>::iterator it = poke.OneXDamage.begin(); it!= poke.OneXDamage.end(); it++)
    {   
        //string name = *it;
        vector<string>::size_type index = getIndex(type_names1, *it);
        if (fileNames[index] == "")
            continue;
        //string file = "TypeIcons\\" + fileNames[index];
        wxString file = fpath + "\\TypeIcons\\" + fileNames[index];
        wxLogStatus(file);
        wxImage* temp_img = new wxImage(file, wxBITMAP_TYPE_PNG);
        (*temp_img).Rescale(button_size_x, button_size_y, wxIMAGE_QUALITY_NORMAL);
        wxBitmapButton* temp_button = new wxBitmapButton(panel, wxID_ANY, wxBitmap(*temp_img, -1));
        oneX.push_back(temp_button);
    }
    oneXWrap->Layout();
}

void MainFrame::populate_halfX()
{   
    depopulate_vector_bitmapbutton(halfX);
    halfX.clear();

    wxString fpath = wxStandardPaths::Get().GetDataDir();
    wxLogStatus(fpath);
    for(vector<string>::iterator it = poke.HalfResist.begin(); it!= poke.HalfResist.end(); it++)
    {   
        //string name = *it;
        vector<string>::size_type index = getIndex(type_names1, *it);
        if (fileNames[index] == "")
            continue;
        //string file = "TypeIcons\\" + fileNames[index];
        wxString file = fpath + "\\TypeIcons\\" + fileNames[index];
        wxLogStatus(file);
        wxImage* temp_img = new wxImage(file, wxBITMAP_TYPE_PNG);
        (*temp_img).Rescale(button_size_x, button_size_y, wxIMAGE_QUALITY_NORMAL);
        wxBitmapButton* temp_button = new wxBitmapButton(panel, wxID_ANY, wxBitmap(*temp_img, -1));
        halfX.push_back(temp_button);
    }
    halfXWrap->Layout();
}

void MainFrame::populate_quarterX()
{   
    depopulate_vector_bitmapbutton(quarterX);
    quarterX.clear();

    wxString fpath = wxStandardPaths::Get().GetDataDir();
    wxLogStatus(fpath);
    for(vector<string>::iterator it = poke.QuarterResist.begin(); it!= poke.QuarterResist.end(); it++)
    {   
        //string name = *it;
        vector<string>::size_type index = getIndex(type_names1, *it);
        if (fileNames[index] == "")
            continue;
        //string file = "TypeIcons\\" + fileNames[index];
        wxString file = fpath + "\\TypeIcons\\" + fileNames[index];
        wxLogStatus(file);
        wxImage* temp_img = new wxImage(file, wxBITMAP_TYPE_PNG);
        (*temp_img).Rescale(button_size_x, button_size_y, wxIMAGE_QUALITY_NORMAL);
        wxBitmapButton* temp_button = new wxBitmapButton(panel, wxID_ANY, wxBitmap(*temp_img, -1));
        quarterX.push_back(temp_button);
    }
    quarterXWrap->Layout();
}

void MainFrame::populate_zeroX()
{   
    //depopulate_vector_bitmapbutton(zeroX);
    
    zeroX.clear();

    wxString fpath = wxStandardPaths::Get().GetDataDir();
    wxLogStatus(fpath);
    for(vector<string>::iterator it = poke.Immunities.begin(); it!= poke.Immunities.end(); it++)
    {   
        //string name = *it;
        vector<string>::size_type index = getIndex(type_names1, *it);
        if (fileNames[index] == "")
            continue;
        //string file = "TypeIcons\\" + fileNames[index];
        wxString file = fpath + "\\TypeIcons\\" + fileNames[index];
        wxLogStatus(file);
        wxImage* temp_img = new wxImage(file, wxBITMAP_TYPE_PNG);
        (*temp_img).Rescale(button_size_x, button_size_y, wxIMAGE_QUALITY_NORMAL);
        wxBitmapButton* temp_button = new wxBitmapButton(panel, wxID_ANY, wxBitmap(*temp_img, -1));
        zeroX.push_back(temp_button);
    }
    zeroXWrap->Layout();
}

void MainFrame::populate_WrapSizers()
{   
    for(vector<wxBitmapButton*>::iterator it = fourX.begin(); it != fourX.end(); it++)
    {
        fourXWrap->Add(*it);
    }

    for(vector<wxBitmapButton*>::iterator it = twoX.begin(); it != twoX.end(); it++)
    {
        twoXWrap->Add(*it);
    }
    
    for(vector<wxBitmapButton*>::iterator it = oneX.begin(); it != oneX.end(); it++)
    {
        oneXWrap->Add(*it);
    }

    for(vector<wxBitmapButton*>::iterator it = halfX.begin(); it != halfX.end(); it++)
    {
        halfXWrap->Add(*it);
    }

    for(vector<wxBitmapButton*>::iterator it = quarterX.begin(); it != quarterX.end(); it++)
    {
        quarterXWrap->Add(*it);
    }

    for(vector<wxBitmapButton*>::iterator it = zeroX.begin(); it != zeroX.end(); it++)
    {
        zeroXWrap->Add(*it);
    }

}

void MainFrame::depopulate_WrapSizers()
{
    fourXWrap->Clear(true);
    twoXWrap->Clear(true);
    oneXWrap->Clear(true);
    halfXWrap->Clear(true);
    quarterXWrap->Clear(true);
    zeroXWrap->Clear(true);

    fourXWrap->Layout();
    twoXWrap->Layout();
    oneXWrap->Layout();
    halfXWrap->Layout();
    quarterXWrap->Layout();
    zeroXWrap->Layout();
    
}

void MainFrame::depopulate_vector_bitmapbutton(std::vector<wxBitmapButton*>& v)
{
    
    for(vector<wxBitmapButton*>::iterator it = v.begin(); it != v.end(); it++)
    {
        (*it)->Destroy();
    }
    
    /*
   for(vector<wxBitmapButton*>::size_type i = 0; i != v.size(); i++)
   {
        v[i]->Destroy();
   }
   */
}

    // make button
    //wxImage* bug_img = new wxImage("TypeIcons\\Bug.png", wxBITMAP_TYPE_PNG);
    //(*bug_img).Rescale(60,30, wxIMAGE_QUALITY_NORMAL);
    //wxBitmapButton* bug_button = new wxBitmapButton(panel, wxID_ANY, wxBitmap(*bug_img, -1), wxPoint(25,100), wxSize(60, 30), wxBORDER_NONE);

