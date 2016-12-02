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
	LoginDialog( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = "Login to Hearts and Spades", const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxDefaultSize, long style = wxDEFAULT_DIALOG_STYLE ); 
  CreateUserDialog m_createUserDialog;
	std::string getUsername() { return userName; }
	std::string getPassword() { return password; }
	void OnLoginBtn(wxCommandEvent& event);
	void OnCreateAccountBtn(wxCommandEvent& event);

private:
	std::string userName;
	std::string password;
};

#endif /* ifndef LOGINDIALOG_HPP */
