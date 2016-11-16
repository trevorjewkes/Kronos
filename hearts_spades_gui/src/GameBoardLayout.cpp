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
	
	m_bitmap6 = new wxStaticBitmap( m_parent, wxID_ANY, wxBitmap( wxT("../img/slice/hearts/4.png"), wxBITMAP_TYPE_ANY ), wxDefaultPosition, wxDefaultSize, 0 );
	fgSizer1->Add( m_bitmap6, 0, wxTOP|wxBOTTOM|wxLEFT, 5 );
	
	m_bitmap7 = new wxStaticBitmap( m_parent, wxID_ANY, wxBitmap( wxT("../img/slice/hearts/4.png"), wxBITMAP_TYPE_ANY ), wxDefaultPosition, wxDefaultSize, 0 );
	fgSizer1->Add( m_bitmap7, 0, wxTOP|wxBOTTOM, 5 );
	
	m_bitmap8 = new wxStaticBitmap( m_parent, wxID_ANY, wxBitmap( wxT("../img/slice/hearts/4.png"), wxBITMAP_TYPE_ANY ), wxDefaultPosition, wxDefaultSize, 0 );
	fgSizer1->Add( m_bitmap8, 0, wxTOP|wxBOTTOM, 5 );
	
	m_bitmap9 = new wxStaticBitmap( m_parent, wxID_ANY, wxBitmap( wxT("../img/scaled/spades/1.png"), wxBITMAP_TYPE_ANY ), wxDefaultPosition, wxDefaultSize, 0 );
	fgSizer1->Add( m_bitmap9, 0, wxTOP|wxBOTTOM, 5 );
	
	
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
	
	m_bitmap42 = new wxStaticBitmap( m_parent, wxID_ANY, wxBitmap( wxT("../img/slice/hearts/11.png"), wxBITMAP_TYPE_ANY ), wxDefaultPosition, wxDefaultSize, 0 );
	fgSizer4->Add( m_bitmap42, 0, wxTOP|wxBOTTOM|wxLEFT, 5 );
	
	m_bitmap43 = new wxStaticBitmap( m_parent, wxID_ANY, wxBitmap( wxT("../img/slice/hearts/11.png"), wxBITMAP_TYPE_ANY ), wxDefaultPosition, wxDefaultSize, 0 );
	fgSizer4->Add( m_bitmap43, 0, wxTOP|wxBOTTOM, 5 );
	
	m_bitmap44 = new wxStaticBitmap( m_parent, wxID_ANY, wxBitmap( wxT("../img/slice/hearts/11.png"), wxBITMAP_TYPE_ANY ), wxDefaultPosition, wxDefaultSize, 0 );
	fgSizer4->Add( m_bitmap44, 0, wxTOP|wxBOTTOM, 5 );
	
	m_bitmap45 = new wxStaticBitmap( m_parent, wxID_ANY, wxBitmap( wxT("../img/slice/hearts/11.png"), wxBITMAP_TYPE_ANY ), wxDefaultPosition, wxDefaultSize, 0 );
	fgSizer4->Add( m_bitmap45, 0, wxTOP|wxBOTTOM, 5 );
	
	m_bitmap46 = new wxStaticBitmap( m_parent, wxID_ANY, wxBitmap( wxT("../img/slice/hearts/11.png"), wxBITMAP_TYPE_ANY ), wxDefaultPosition, wxDefaultSize, 0 );
	fgSizer4->Add( m_bitmap46, 0, wxTOP|wxBOTTOM, 5 );
	
	m_bitmap47 = new wxStaticBitmap( m_parent, wxID_ANY, wxBitmap( wxT("../img/slice/hearts/11.png"), wxBITMAP_TYPE_ANY ), wxDefaultPosition, wxDefaultSize, 0 );
	fgSizer4->Add( m_bitmap47, 0, wxTOP|wxBOTTOM, 5 );
	
	m_bitmap48 = new wxStaticBitmap( m_parent, wxID_ANY, wxBitmap( wxT("../img/slice/hearts/11.png"), wxBITMAP_TYPE_ANY ), wxDefaultPosition, wxDefaultSize, 0 );
	fgSizer4->Add( m_bitmap48, 0, wxTOP|wxBOTTOM, 5 );
	
	m_bitmap49 = new wxStaticBitmap( m_parent, wxID_ANY, wxBitmap( wxT("../img/slice/hearts/11.png"), wxBITMAP_TYPE_ANY ), wxDefaultPosition, wxDefaultSize, 0 );
	fgSizer4->Add( m_bitmap49, 0, wxTOP|wxBOTTOM, 5 );
	
	m_bitmap50 = new wxStaticBitmap( m_parent, wxID_ANY, wxBitmap( wxT("../img/slice/hearts/11.png"), wxBITMAP_TYPE_ANY ), wxDefaultPosition, wxDefaultSize, 0 );
	fgSizer4->Add( m_bitmap50, 0, wxTOP|wxBOTTOM, 5 );
	
	m_bitmap51 = new wxStaticBitmap( m_parent, wxID_ANY, wxBitmap( wxT("../img/slice/hearts/11.png"), wxBITMAP_TYPE_ANY ), wxDefaultPosition, wxDefaultSize, 0 );
	fgSizer4->Add( m_bitmap51, 0, wxTOP|wxBOTTOM, 5 );
	
	m_bitmap52 = new wxStaticBitmap( m_parent, wxID_ANY, wxBitmap( wxT("../img/slice/hearts/11.png"), wxBITMAP_TYPE_ANY ), wxDefaultPosition, wxDefaultSize, 0 );
	fgSizer4->Add( m_bitmap52, 0, wxTOP|wxBOTTOM, 5 );
	
	m_bitmap53 = new wxStaticBitmap( m_parent, wxID_ANY, wxBitmap( wxT("../img/slice/hearts/11.png"), wxBITMAP_TYPE_ANY ), wxDefaultPosition, wxDefaultSize, 0 );
	fgSizer4->Add( m_bitmap53, 0, wxTOP|wxBOTTOM, 5 );

	m_bitmap54 = new wxStaticBitmap( m_parent, wxID_ANY, wxBitmap( wxT("../img/scaled/diamonds/2.png"), wxBITMAP_TYPE_ANY ), wxDefaultPosition, wxDefaultSize, 0 );
	fgSizer4->Add( m_bitmap54, 0, wxTOP|wxBOTTOM|wxRIGHT, 5 );
	
	
	
	fgSizer4->Add( 40, 0, 1, wxEXPAND, 5 );
	
	m_staticText6 = new wxStaticText( m_parent, wxID_ANY, wxT("Your Name\nTricks: 3\nScore: 8"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText6->Wrap( -1 );
	fgSizer4->Add( m_staticText6, 0, wxALL|wxALIGN_CENTER_HORIZONTAL, 5 );
	
	
	bSizer3->Add( fgSizer4, 1, wxEXPAND, 5 );
	
	this->Add( bSizer3, 1, wxEXPAND, 5 );
	
	// Connect Events
	m_bitmap42->Connect( wxEVT_LEFT_DCLICK, wxMouseEventHandler( MainFrame::cardClicked ), NULL, m_parent );
}
