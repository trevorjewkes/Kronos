#include "LoginDialog.hpp"
#include "LoginLayout.hpp"

LoginDialog::LoginDialog( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : wxDialog( parent, id, title, pos, size, style), m_createUserDialog(NULL), userName("Jim"), password("password")
{
	this->SetSizer(new LoginLayout(this));	
	this->Layout();
	this->Center();
}

void LoginDialog::OnLoginBtn(wxCommandEvent& event)
{
	std::cout << "login btn\n";	
  this->Show(false);
}
void LoginDialog::OnCreateAccountBtn(wxCommandEvent& event)
{
	std::cout << "create account btn\n";	
  m_createUserDialog.Show(true);
}
