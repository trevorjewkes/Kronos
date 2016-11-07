#include "LoginLayout.hpp"
#include <wx/wxprec.h>
#ifndef WX_PRECOMP
    #include <wx/wx.h>
#endif

LoginLayout::LoginLayout( MainFrame* parent, int orient): wxBoxSizer(orient)
{
	
	this->Add( 0, 1, 1, wxEXPAND, 5 ); //spacer

	wxStaticText* m_staticText6 = new wxStaticText( parent, wxID_ANY, wxT("Username"), wxDefaultPosition, wxSize( 200,17 ), 0 );
	m_staticText6->Wrap( -1 );
	this->Add( m_staticText6, 0, wxALIGN_CENTER|wxALL|wxSHAPED, 5 );
	
	wxTextCtrl* username = new wxTextCtrl( parent, wxID_ANY, wxEmptyString, wxDefaultPosition, wxSize( 200,25 ), 0 );
	this->Add( username, 0, wxALIGN_CENTER|wxALL|wxSHAPED, 5 );
	
	wxStaticText* m_staticText7 = new wxStaticText( parent, wxID_ANY, wxT("Password"), wxDefaultPosition, wxSize( 200,17 ), 0 );
	m_staticText7->Wrap( -1 );
	this->Add( m_staticText7, 0, wxALIGN_CENTER|wxALL|wxSHAPED, 5 );
	
	wxTextCtrl* pass = new wxTextCtrl( parent, wxID_ANY, wxEmptyString, wxDefaultPosition, wxSize( 200,25 ), 0 );
	this->Add( pass, 0, wxALIGN_CENTER|wxALL|wxSHAPED, 5 );
	
	wxButton* loginBtn = new wxButton( parent, wxID_ANY, wxT("Login"), wxDefaultPosition, wxDefaultSize, 0 );
	this->Add( loginBtn, 0, wxALIGN_CENTER|wxALL|wxSHAPED, 5 );
	
	wxStaticText* m_staticText8 = new wxStaticText( parent, wxID_ANY, wxT("-  or  -"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText8->Wrap( -1 );
	this->Add( m_staticText8, 0, wxALIGN_CENTER|wxALL|wxSHAPED, 5 );
	
	wxButton* createAccountBtn = new wxButton( parent, wxID_ANY, wxT("Create Account"), wxDefaultPosition, wxDefaultSize, 0 );
	this->Add( createAccountBtn, 0, wxALIGN_CENTER|wxALL|wxSHAPED, 5 );
	
	this->Add( 0, 1, 1, wxEXPAND, 5 ); //spacer

	// Connect Events
	//loginBtn->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( MainFrame::login ), NULL, this );
	//createAccountBtn->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( MainFrame::createAcount ), NULL, this );
}
