#include "wxDeck.h"
#include "MyFrame.h"

// For compilers that support precompilation, includes "wx/wx.h".
#include <wx/wxprec.h>
#ifndef WX_PRECOMP
    #include <wx/wx.h>
#endif
#include <cassert>
#include <vector>
#include <iostream>

class MyApp: public wxApp
{
public:
    virtual bool OnInit();
};

class Button : public wxFrame {
  public:
    Button(const wxString& title);
    void OnQuit(wxCommandEvent & event);
};

wxIMPLEMENT_APP(MyApp);

bool MyApp::OnInit()
{
    MyFrame *frame = new MyFrame( "Card Test", wxPoint(50, 50), wxSize(650, 540) );
    frame->Show( true );
    return true;
}

Button::Button(const wxString& title)
       : wxFrame(NULL, wxID_ANY, title, wxDefaultPosition, wxSize(270, 150))
{
  wxPanel *panel = new wxPanel(this, wxID_ANY);

  wxButton *button = new wxButton(panel, wxID_EXIT, wxT("Quit"), 
      wxPoint(20, 20));
  Connect(wxID_EXIT, wxEVT_COMMAND_BUTTON_CLICKED, 
      wxCommandEventHandler(Button::OnQuit));
  button->SetFocus();
  Centre();
}

void Button::OnQuit(wxCommandEvent & WXUNUSED(event))
{
    Close(true);
}

