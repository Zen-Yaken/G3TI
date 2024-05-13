#ifndef GUARD_G3TI_h
#define GAURD_G3TI_h

#include <wx/wx.h>
#include <wx/sizer.h>
#include "MainFrame.h"


class MyApp: public wxApp
{
public:
    virtual bool OnInit();    


private:
    
    wxFrame *frame;
    
};






#endif