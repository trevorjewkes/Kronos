#include "LobbyDialog.hpp"
#include "LobbyLayout.hpp"

LobbyDialog::LobbyDialog( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style) : wxDialog(parent, id, title, pos, size, style), m_parent(parent)
{
	this->SetSizer(new LobbyLayout(this));	
	this->Layout();
	this->Center();
} 

