#ifndef GAURD_MAINFRAME_h
#define GAURD_MAINFRAME_h
#include <wx/wx.h>
#include <vector>
#include <string>
#include <wx/bmpbuttn.h>
#include "type_interactions.h" //Pokemon calss, Type class, and vector<string> type_names
#include <wx/wrapsizer.h>

class MainFrame: public wxFrame
{
public:
    MainFrame(const wxString& title, const wxPoint& pos, const wxSize& size);
    Pokemon poke;
private:
    
    wxPanel* panel = new wxPanel(this);
    //auto panel = new wxScrolled<wxPanel>(this, wxID_ANY);
    //panel->SetScrollRate(0, FromDIP(10));
    void OnChoiceMade1(wxCommandEvent& evt); // this MUST return void
    void OnChoiceMade2(wxCommandEvent& evt); // this MUST return void
    
    int first_type_selection = 0;
    int second_type_selection = 0; 
    bool first_type_selection_was_0 = false;
    Type typeA;
    Type typeB;
    wxSizerFlags typeFlag = wxSizerFlags().CenterVertical().Top().Border(wxALL, 5);

    std::vector<wxBitmapButton*> fourX; //damage
    std::vector<wxBitmapButton*> twoX;  // damage
    std::vector<wxBitmapButton*> oneX;
    std::vector<wxBitmapButton*> halfX;
    std::vector<wxBitmapButton*> quarterX;
    std::vector<wxBitmapButton*> zeroX; // damage

    std::vector<std::string> fileNames = {"", "Bug.png", "Dark.png", "Dragon.png", "Electric.png", "Fighting.png", "Fire.png", "Flying.png", "Ghost.png",
                                        "Grass.png", "Ground.png", "Ice.png", "Normal.png", "Poison.png", "Psychic.png", "Rock.png", "Steel.png", "water.png"};

    void populate_fourX();
    void populate_twoX();
    void populate_oneX();
    void populate_halfX();
    void populate_quarterX();
    void populate_zeroX();

    
    wxWrapSizer* fourXWrap = new wxWrapSizer(wxHORIZONTAL);
    wxWrapSizer* twoXWrap = new wxWrapSizer(wxHORIZONTAL);
    wxWrapSizer* oneXWrap = new wxWrapSizer(wxHORIZONTAL);
    wxWrapSizer* halfXWrap = new wxWrapSizer(wxHORIZONTAL);
    wxWrapSizer* quarterXWrap = new wxWrapSizer(wxHORIZONTAL);
    wxWrapSizer* zeroXWrap = new wxWrapSizer(wxHORIZONTAL);

    wxBitmapButton* hold_img;
    int count_hold_img = 0;

    void depopulate_vector_bitmapbutton(std::vector<wxBitmapButton*>&);
    void populate_WrapSizers();
    void depopulate_WrapSizers();
    wxDECLARE_EVENT_TABLE();
};

std::vector<std::string>::size_type getIndex(std::vector<std::string>&, std::string);


#endif