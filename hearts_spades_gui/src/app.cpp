#include "MainFrame.hpp"
#include <wx/wxprec.h>
#ifndef WX_PRECOMP
    #include <wx/wx.h>
#endif
class MyApp: public wxApp
{
public:
    virtual bool OnInit();
};

wxIMPLEMENT_APP(MyApp);
bool MyApp::OnInit()
{
    MainFrame *frame = new MainFrame( "Hearts and Spades", wxPoint(50, 50), wxSize(650,450) );
		// can use wxGetDisplaySize() to get the screen size
    frame->Show( true );
    return true;
}
