#include "ServerDialog.hpp"
#include "MainFrame.hpp"
#include <iostream>

ServerDialog::ServerDialog( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : wxDialog( parent, id, title, pos, size, style )
{
	//this->SetSizeHints( wxDefaultSize, wxDefaultSize );
	
	wxBoxSizer* bSizerServerSettings;
	bSizerServerSettings = new wxBoxSizer( wxVERTICAL );

	m_staticTextIP = new wxStaticText( this, wxID_ANY, wxT("IP Adress:"), wxDefaultPosition, wxSize(200,25), 0 );
	m_staticTextIP->Wrap( -1 );
	bSizerServerSettings->Add( m_staticTextIP, 0, wxALL, 5 );
	
	m_textCtrlIP = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxSize(200,25), 0 );
	bSizerServerSettings->Add( m_textCtrlIP, 0, wxALL|wxEXPAND, 5 );
	
	m_staticTextPort = new wxStaticText( this, wxID_ANY, wxT("Port:"), wxDefaultPosition, wxSize(200,25), 0 );
	m_staticTextPort->Wrap( -1 );
	bSizerServerSettings->Add( m_staticTextPort, 0, wxALL, 5 );
	
	m_textCtrlPort = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxSize(200,25), 0 );
	bSizerServerSettings->Add( m_textCtrlPort, 0, wxALL|wxEXPAND, 5 );
	
	m_submitBtn = new wxButton(this, wxID_ANY, wxT("Submit"));
	m_submitBtn->Connect( wxID_ANY, wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( ServerDialog::OnClose ), NULL, this );
	bSizerServerSettings->Add( m_submitBtn, 0, wxALIGN_CENTER|wxALL, 5 );

	this->SetSizer( bSizerServerSettings );
	this->Layout();
	bSizerServerSettings->Fit( this );
	
	this->Center();

  this->Connect( wxEVT_CLOSE_WINDOW, wxCloseEventHandler( MainFrame::OnDialogClose ) , NULL, parent);
}
void ServerDialog::OnClose(wxCommandEvent& event)
{
	m_ip =  m_textCtrlIP->GetValue();	
	m_port = atoi(m_textCtrlPort->GetValue().c_str());	
	std::cout << "IP: " << m_ip << "\t PORT: " << m_port << std::endl;
	std::cout.flush();
	this->Show(false);	
}
