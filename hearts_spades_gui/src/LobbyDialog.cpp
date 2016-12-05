#include "LobbyDialog.hpp"
#include "MainFrame.hpp"

LobbyDialog::LobbyDialog( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style) : wxDialog(parent, id, title, pos, size, style), m_createHeartsGameDialog(NULL, "Create Hearts Game"), m_createSpadesGameDialog(NULL, "Create Spades Game")
{
	wxInitAllImageHandlers();
  wxBoxSizer* bs = new wxBoxSizer(wxVERTICAL);
	bs->Add( 0, 1, 1, wxEXPAND, 5 ); //spacer
	
	wxStaticText* m_staticText8 = new wxStaticText( this, wxID_ANY, wxT("Choose a game"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText8->Wrap( -1 );
	bs->Add( m_staticText8, 0, wxALL|wxALIGN_CENTER_HORIZONTAL, 5 );
	
	wxGridSizer* gSizer1;
	gSizer1 = new wxGridSizer( 0, 2, 0, 0 );

	wxStaticBitmap* m_bitmap1 = new wxStaticBitmap( this, wxID_ANY, wxBitmap( wxT("../img/heart.png"), wxBITMAP_TYPE_ANY ), wxDefaultPosition, wxDefaultSize, 0 );
	gSizer1->Add( m_bitmap1, 0, wxALL|wxALIGN_CENTER_HORIZONTAL, 5 );
	
	wxStaticBitmap* m_bitmap2 = new wxStaticBitmap( this, wxID_ANY, wxBitmap( wxT("../img/spade.png"), wxBITMAP_TYPE_ANY ), wxDefaultPosition, wxDefaultSize, 0 );
	gSizer1->Add( m_bitmap2, 0, wxALL|wxALIGN_CENTER_HORIZONTAL, 5 );
	
	
	bs->Add( gSizer1, 1, wxEXPAND, 5 );
	
	wxGridSizer* gSizer2;
	gSizer2 = new wxGridSizer( 0, 2, 0, 0 );
	
	wxBoxSizer* bSizer3;
	bSizer3 = new wxBoxSizer( wxVERTICAL );
	
	m_joinPrivateHeartsBtn = new wxButton( this, wxID_ANY, wxT("Join Private Game"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer3->Add( m_joinPrivateHeartsBtn, 0, wxALL|wxEXPAND, 5 );
	
	m_joinPublicHeartsBtn = new wxButton( this, wxID_ANY, wxT("Join Public Game"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer3->Add( m_joinPublicHeartsBtn, 0, wxALL|wxEXPAND, 5 );
	
	wxButton* m_createNewSpadesBtn = new wxButton( this, wxID_ANY, wxT("Create New Game"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer3->Add( m_createNewSpadesBtn, 0, wxALL|wxEXPAND, 5 );
	
	
	gSizer2->Add( bSizer3, 1, wxEXPAND, 5 );
	
	wxBoxSizer* bSizer4;
	bSizer4 = new wxBoxSizer( wxVERTICAL );
	
	m_joinPrivateSpadesBtn = new wxButton( this, wxID_ANY, wxT("Join Private Game"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer4->Add( m_joinPrivateSpadesBtn, 0, wxALL|wxEXPAND, 5 );
	
 	m_joinPublicSpadesBtn = new wxButton( this, wxID_ANY, wxT("Join Public Game"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer4->Add( m_joinPublicSpadesBtn, 0, wxALL|wxEXPAND, 5 );
	
	wxButton* m_createNewHeartsBtn = new wxButton( this, wxID_ANY, wxT("Create New Game"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer4->Add( m_createNewHeartsBtn, 0, wxALL|wxEXPAND, 5 );
	
	gSizer2->Add( bSizer4, 1, wxEXPAND, 5 );
	
	bs->Add( gSizer2, 1, wxEXPAND, 5 );

	bs->Add( 0, 1, 1, wxEXPAND, 5 ); //spacer

	this->SetSizer(bs);	
	this->Layout();
	this->Center();

	//connect events
	//m_joinPrivateHeartsBtn->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( LobbyDialog::joinPrivateHeartsGame ), NULL, this );
	//m_joinPrivateSpadesBtn->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( LobbyDialog::joinPrivateSpadesGame ), NULL, this );
	//m_joinPublicHeartsBtn->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( LobbyDialog::joinPublicHeartsGame ), NULL, this );
	//m_joinPublicSpadesBtn->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( LobbyDialog::joinPublicSpadesGame ), NULL, this );
	m_createNewSpadesBtn->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( LobbyDialog::createNewHeartsGame ), NULL, this );
	m_createNewHeartsBtn->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( LobbyDialog::createNewSpadesGame ), NULL, this );

  this->Connect( wxEVT_CLOSE_WINDOW, wxCloseEventHandler( MainFrame::OnDialogClose ) , NULL, parent);
} 
void LobbyDialog::createNewSpadesGame(wxCommandEvent& event) {
  m_createSpadesGameDialog.Show();
}
void LobbyDialog::createNewHeartsGame(wxCommandEvent& event) {
  m_createHeartsGameDialog.Show();
}
