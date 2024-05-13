#include "G3TI.h"
#include "MainFrame.h"


wxIMPLEMENT_APP(MyApp);

bool MyApp::OnInit()
{
    wxInitAllImageHandlers();

    wxBoxSizer* sizer = new wxBoxSizer(wxHORIZONTAL); //added this from image sample
    MainFrame *frame = new MainFrame("Gen 3 Type Interactions", wxPoint(100, 100), wxSize(400, 600));
    frame->SetClientSize(400, 600);
    frame->Show(true);

    
    return true;
};

// make button
//wxImage* bug_img = new wxImage("TypeIcons\\Bug.png", wxBITMAP_TYPE_PNG);
//(*bug_img).Rescale(60,30, wxIMAGE_QUALITY_NORMAL);
//wxBitmapButton* bug_button = new wxBitmapButton(panel, wxID_ANY, wxBitmap(*bug_img, -1), wxPoint(25,100), wxSize(60, 30), wxBORDER_NONE);
