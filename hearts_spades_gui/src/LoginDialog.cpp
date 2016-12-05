#include "LoginDialog.hpp"
#include "MainFrame.hpp"

LoginDialog::LoginDialog( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : wxDialog( parent, id, title, pos, size, style), m_createUserDialog(NULL), userName("Noname")
{
  wxBoxSizer* bs = new wxBoxSizer(wxVERTICAL);

	bs->Add( 0, 1, 1, wxEXPAND, 5 ); //spacer

	wxStaticText* m_staticText6 = new wxStaticText( this, wxID_ANY, wxT("Username"), wxDefaultPosition, wxSize( 200,17 ), 0 );
	m_staticText6->Wrap( -1 );
	bs->Add( m_staticText6, 0, wxALIGN_CENTER|wxALL|wxSHAPED, 5 );
	
	m_textCtrlUsername = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxSize( 200,25 ), 0 );
	bs->Add( m_textCtrlUsername, 0, wxALIGN_CENTER|wxALL|wxSHAPED, 5 );
	
	wxStaticText* m_staticText7 = new wxStaticText( this, wxID_ANY, wxT("Password"), wxDefaultPosition, wxSize( 200,17 ), 0 );
	m_staticText7->Wrap( -1 );
	bs->Add( m_staticText7, 0, wxALIGN_CENTER|wxALL|wxSHAPED, 5 );
	
	m_textCtrlPassword = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxSize( 200,25 ), wxTE_PASSWORD );
	bs->Add( m_textCtrlPassword, 0, wxALIGN_CENTER|wxALL|wxSHAPED, 5 );
	
	loginBtn = new wxButton( this, wxID_ANY, wxT("Login"), wxDefaultPosition, wxDefaultSize, 0 );
	bs->Add( loginBtn, 0, wxALIGN_CENTER|wxALL|wxSHAPED, 5 );
	
	wxStaticText* m_staticText8 = new wxStaticText( this, wxID_ANY, wxT("-  or  -"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText8->Wrap( -1 );
	bs->Add( m_staticText8, 0, wxALIGN_CENTER|wxALL|wxSHAPED, 5 );
	
	wxButton* createAccountBtn = new wxButton( this, wxID_ANY, wxT("Create Account"), wxDefaultPosition, wxDefaultSize, 0 );
	bs->Add( createAccountBtn, 0, wxALIGN_CENTER|wxALL|wxSHAPED, 5 );
	
	bs->Add( 0, 1, 1, wxEXPAND, 5 ); //spacer

	// Connect Events
	createAccountBtn->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( LoginDialog::OnCreateAccountBtn ), NULL, this );
  this->Connect( wxEVT_CLOSE_WINDOW, wxCloseEventHandler( MainFrame::OnDialogClose ) , NULL, parent );

	this->SetSizer(bs);	
	this->Layout();
	this->Center();
}
void LoginDialog::OnCreateAccountBtn(wxCommandEvent& event)
{
	std::cout << "create account btn\n";	
  m_createUserDialog.Show(true);
}
bool LoginDialog::validLogin() {
  userName = m_textCtrlUsername->GetValue();
  password = m_textCtrlPassword->GetValue();
  if (m_createUserDialog.verifyUser(userName, password)) {
    return true;
  } else {
    return false;
  }
}
