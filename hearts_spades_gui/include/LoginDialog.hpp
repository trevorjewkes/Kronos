#ifndef LOGINDIALOG_HPP
#define LOGINDIALOG_HPP

#include "CreateUserDialog.hpp"
#include <wx/wxprec.h>
#ifndef WX_PRECOMP
    #include <wx/wx.h>
#endif
#include <string>

class LoginDialog : public wxDialog
{
public:
	LoginDialog( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = "Login to Hearts and Spades", const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxDefaultSize, long style = wxDEFAULT_DIALOG_STYLE|wxRESIZE_BORDER ); 
  CreateUserDialog m_createUserDialog;
  wxButton* loginBtn;
	std::string getUsername() { return userName; }
	void OnCreateAccountBtn(wxCommandEvent& event);
  bool validLogin();

private:
	std::string userName;
	std::string password;
  wxTextCtrl* m_textCtrlUsername;
  wxTextCtrl* m_textCtrlPassword;
};

#endif