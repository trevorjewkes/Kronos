#ifndef CREATEUSERDIALOG_HPP
#define CREATEUSERDIALOG_HPP

#include <wx/wxprec.h>
#ifndef WX_PRECOMP
    #include <wx/wx.h>
#endif
#include <string>

class CreateUserDialog : public wxDialog
{
public:
	CreateUserDialog( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = "Create New User", const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxDefaultSize, long style = wxDEFAULT_DIALOG_STYLE ); 
	void OnCreateUserBtn(wxCommandEvent& event);
};

#endif /* ifndef CREATEUSERDIALOG_HPP */
