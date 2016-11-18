#include "GameBoardLayout.hpp"
#include "MainFrame.hpp"
#include <iostream>

GameBoardLayout::GameBoardLayout( wxWindow* parent, int orient): wxBoxSizer(orient), m_parent(parent)
{
  //put all the layout in here
  //form wxFormBuilder
  //wxBoxSizer* this;
	//this = new wxBoxSizer( wxVERTICAL );
	
	m_player2Text = new wxStaticText( m_parent, wxID_ANY, wxT("Player2\nTricks: 3\nScore: 4"), wxDefaultPosition, wxDefaultSize, 0 );
	m_player2Text->Wrap( -1 );
	this->Add( m_player2Text, 0, wxALL|wxALIGN_CENTER_HORIZONTAL, 5 );
	
	wxGridSizer* gSizer1;
	gSizer1 = new wxGridSizer( 0, 3, 0, 0 );
	
	m_player1Text = new wxStaticText( m_parent, wxID_ANY, wxT("Player1\nTricks: 2 \nScore: 4"), wxDefaultPosition, wxDefaultSize, 0 );
	m_player1Text->Wrap( -1 );
	gSizer1->Add( m_player1Text, 0, wxALL|wxALIGN_CENTER_HORIZONTAL, 5 );
	
	wxFlexGridSizer* fgSizer1;
	fgSizer1 = new wxFlexGridSizer( 0, 4, 0, 0 );
	fgSizer1->SetFlexibleDirection( wxBOTH );
	fgSizer1->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );
	
  //create center hand cards in the vector
  wxStaticBitmap* tempBitmap;
  for (int i = 0; i < 3; ++i) {
    tempBitmap = new wxStaticBitmap( m_parent, wxID_ANY, wxBitmap( wxT("../img/slice/hearts/4.png"), wxBITMAP_TYPE_ANY ), wxDefaultPosition, wxDefaultSize, 0 );
    m_center_cards.push_back(tempBitmap);
  }
  tempBitmap = new wxStaticBitmap( m_parent, wxID_ANY, wxBitmap( wxT("../img/scaled/hearts/4.png"), wxBITMAP_TYPE_ANY ), wxDefaultPosition, wxDefaultSize, 0 );
  m_center_cards.push_back(tempBitmap);
  //add the cards to the sizer
  for (int i = 0; i < 4; ++i) {
	  fgSizer1->Add( m_center_cards[i], 0, wxTOP|wxBOTTOM, 5 );
  }

	gSizer1->Add( fgSizer1, 1, wxEXPAND, 5 );
	
	m_Player3Text = new wxStaticText( m_parent, wxID_ANY, wxT("Player3\nTricks: 2\nScore: 5"), wxDefaultPosition, wxDefaultSize, 0 );
	m_Player3Text->Wrap( -1 );
	gSizer1->Add( m_Player3Text, 0, wxALL|wxALIGN_CENTER_HORIZONTAL, 5 );
	
	
	this->Add( gSizer1, 1, wxEXPAND, 5 );
	
	wxBoxSizer* bSizer3;
	bSizer3 = new wxBoxSizer( wxVERTICAL );
	
	wxFlexGridSizer* fgSizer4;
	fgSizer4 = new wxFlexGridSizer( 0, 16, 0, 0 );
	fgSizer4->SetFlexibleDirection( wxBOTH );
	fgSizer4->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );
	
	
	fgSizer4->Add( 40, 0, 1, wxEXPAND, 5 );

  //create player hand vector
  //pass in i to the id in the wxStaticBitmap
  for (int i = 0; i < 12; ++i) {
    tempBitmap = new wxStaticBitmap( m_parent, i, wxBitmap( wxT("../img/slice/hearts/4.png"), wxBITMAP_TYPE_ANY ), wxDefaultPosition, wxDefaultSize, 0 );
    m_player_hand.push_back(tempBitmap);
  }
  //add the last card as full
  tempBitmap = new wxStaticBitmap( m_parent, 12, wxBitmap( wxT("../img/scaled/hearts/4.png"), wxBITMAP_TYPE_ANY ), wxDefaultPosition, wxDefaultSize, 0 );
  m_player_hand.push_back(tempBitmap);
  //add the player cards to the sizer
  for (int i = 0; i < 13; ++i) {
	  fgSizer4->Add( m_player_hand[i], 0, wxTOP|wxBOTTOM, 5 );
  }
	
  //spacer
	fgSizer4->Add( 40, 0, 1, wxEXPAND, 5 );
	
	m_userText = new wxStaticText( m_parent, wxID_ANY, wxT("Your Name\nTricks: 3\nScore: 8"), wxDefaultPosition, wxDefaultSize, 0 );
	m_userText->Wrap( -1 );
	fgSizer4->Add( m_userText, 0, wxALL|wxALIGN_CENTER_HORIZONTAL, 5 );
	
	
	bSizer3->Add( fgSizer4, 1, wxEXPAND, 5 );
	
	this->Add( bSizer3, 1, wxEXPAND, 5 );
	
  // Connect events for player hand
  for (int i = 0; i < 13; ++i) {
    m_player_hand[i]->Connect( wxEVT_LEFT_DCLICK, wxMouseEventHandler( MainFrame::cardClicked ), NULL, m_parent );
  }
}
