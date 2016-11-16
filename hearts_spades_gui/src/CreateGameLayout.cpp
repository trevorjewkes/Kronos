#include "CreateGameLayout.hpp"
#include "MainFrame.hpp"
#include <wx/wxprec.h>
#ifndef WX_PRECOMP
    #include <wx/wx.h>
#endif
#include <iostream>

CreateGameLayout::CreateGameLayout( CreateGameDialog* parent, int orient): wxBoxSizer(orient)
{
	wxGridSizer* gSizer3;
	gSizer3 = new wxGridSizer( 0, 2, 0, 0 );
	
	wxRadioButton* m_radioBtn1 = new wxRadioButton( parent, wxID_ANY, wxT("Private"), wxDefaultPosition, wxDefaultSize, 0 );
	gSizer3->Add( m_radioBtn1, 0, wxALL, 5 );
	
	wxRadioButton* m_radioBtn2 = new wxRadioButton( parent, wxID_ANY, wxT("Public"), wxDefaultPosition, wxDefaultSize, 0 );
	gSizer3->Add( m_radioBtn2, 0, wxALL, 5 );
	
	
	this->Add( gSizer3, 1, wxEXPAND, 5 );
	
	wxStaticText* m_staticText19 = new wxStaticText( parent, wxID_ANY, wxT("Name of Private Game:"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText19->Wrap( -1 );
	this->Add( m_staticText19, 0, wxALL|wxEXPAND, 5 );
	
	wxTextCtrl* m_textCtrl7 = new wxTextCtrl( parent, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	this->Add( m_textCtrl7, 0, wxALL|wxEXPAND, 5 );
	
	wxGridSizer* gSizer4;
	gSizer4 = new wxGridSizer( 0, 2, 0, 0 );
	
	wxStaticText* m_staticText4 = new wxStaticText( parent, wxID_ANY, wxT("Player 2"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText4->Wrap( -1 );
	gSizer4->Add( m_staticText4, 0, wxALL, 5 );
	
	wxComboBox* m_comboBox3 = new wxComboBox( parent, wxID_ANY, wxT("AI Easy"), wxDefaultPosition, wxDefaultSize, 0, NULL, 0 );
	m_comboBox3->Append( wxT("Human") );
	m_comboBox3->Append( wxT("AI Easy") );
	m_comboBox3->Append( wxT("AI Medium") );
	m_comboBox3->Append( wxT("AI Hard") );
	m_comboBox3->SetSelection( 1 );
	gSizer4->Add( m_comboBox3, 0, wxALL, 5 );
	
	
	this->Add( gSizer4, 1, wxEXPAND, 5 );
	
	wxGridSizer* gSizer41;
	gSizer41 = new wxGridSizer( 0, 2, 0, 0 );
	
	wxStaticText* m_staticText41 = new wxStaticText( parent, wxID_ANY, wxT("Player 3"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText41->Wrap( -1 );
	gSizer41->Add( m_staticText41, 0, wxALL, 5 );
	
	wxComboBox* m_comboBox31 = new wxComboBox( parent, wxID_ANY, wxT("AI Easy"), wxDefaultPosition, wxDefaultSize, 0, NULL, 0 );
	m_comboBox31->Append( wxT("Human") );
	m_comboBox31->Append( wxT("AI Easy") );
	m_comboBox31->Append( wxT("AI Medium") );
	m_comboBox31->Append( wxT("AI Hard") );
	m_comboBox31->SetSelection( 1 );
	gSizer41->Add( m_comboBox31, 0, wxALL, 5 );
	
	
	this->Add( gSizer41, 1, wxEXPAND, 5 );
	
	wxGridSizer* gSizer42;
	gSizer42 = new wxGridSizer( 0, 2, 0, 0 );
	
	wxStaticText* m_staticText42 = new wxStaticText( parent, wxID_ANY, wxT("Player 4"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText42->Wrap( -1 );
	gSizer42->Add( m_staticText42, 0, wxALL, 5 );
	
	wxComboBox* m_comboBox32 = new wxComboBox( parent, wxID_ANY, wxT("AI Easy"), wxDefaultPosition, wxDefaultSize, 0, NULL, 0 );
	m_comboBox32->Append( wxT("Human") );
	m_comboBox32->Append( wxT("AI Easy") );
	m_comboBox32->Append( wxT("AI Medium") );
	m_comboBox32->Append( wxT("AI Hard") );
	m_comboBox32->SetSelection( 1 );
	gSizer42->Add( m_comboBox32, 0, wxALL, 5 );
	
	
	this->Add( gSizer42, 1, wxEXPAND, 5 );
	
	wxButton* m_button10 = new wxButton( parent, wxID_ANY, wxT("Create Game"), wxDefaultPosition, wxDefaultSize, 0 );
	this->Add( m_button10, 0, wxALL|wxALIGN_CENTER_HORIZONTAL, 5 );

	//connect events
	m_button10->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( CreateGameDialog::createGameBtn ), NULL, parent );
}
