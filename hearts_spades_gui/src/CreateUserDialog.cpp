#include "CreateUserDialog.hpp"

CreateUserDialog::CreateUserDialog( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : wxDialog( parent, id, title, pos, size, style)
{
  addUser("Joe", "pw");
  addUser("Trevor", "pw");
  addUser("Brandon", "pw");
  addUser("Nieka", "pw");
  addUser("Ryan", "pw");

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
	
	m_textCtrlPassword1 = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxSize( 200,25 ), wxTE_PASSWORD );
	bs->Add( m_textCtrlPassword1, 0, wxALIGN_CENTER|wxALL|wxSHAPED, 5 );

  //confirm password creation
	wxStaticText* m_staticText8 = new wxStaticText( this, wxID_ANY, wxT("Confirm Password"), wxDefaultPosition, wxSize( 200,17 ), 0 );
	m_staticText7->Wrap( -1 );
	bs->Add( m_staticText8, 0, wxALIGN_CENTER|wxALL|wxSHAPED, 5 );
	
	m_textCtrlPassword2 = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxSize( 200,25 ), wxTE_PASSWORD );
	bs->Add( m_textCtrlPassword2, 0, wxALIGN_CENTER|wxALL|wxSHAPED, 5 );
	
	wxButton* createUserBtn = new wxButton( this, wxID_ANY, wxT("Create New User"), wxDefaultPosition, wxDefaultSize, 0 );
	bs->Add( createUserBtn, 0, wxALIGN_CENTER|wxALL|wxSHAPED, 5 );

	bs->Add( 0, 1, 1, wxEXPAND, 5 ); //spacer

	createUserBtn->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( CreateUserDialog::OnCreateUserBtn ), NULL, this );

  this->SetSizer(bs);
  this->Layout();
  this->Center();
}

void CreateUserDialog::OnCreateUserBtn(wxCommandEvent& event)
{
  //check if both passwords match
  if (m_textCtrlPassword1->GetValue() == m_textCtrlPassword2->GetValue()) {
    this->Show(false);
    std::cout << "Account for " << m_textCtrlUsername->GetValue() << " has been created." << std::endl;
    std::cout.flush();
    std::string name = (std::string)m_textCtrlUsername->GetValue();
    std::string password = (std::string)m_textCtrlPassword1->GetValue();
    addUser(name, password);
    wxMessageBox(wxT("User created"));
    std::cout << "verified: " << verifyUser(name, password) << std::endl;
  } else {
    wxMessageBox(wxT("Your passwords do not match!"));
  }
}

bool CreateUserDialog::verifyUser(std::string const& username, std::string const& password){
  if (username == "" || password == "")
    return false;
  return pw_hash[username] == password;  
}

void CreateUserDialog::addUser(std::string const& username, std::string const& password){
  pw_hash.emplace(username, password);
}
