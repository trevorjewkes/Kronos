#include "LobbyDialog.hpp"
#include "LobbyLayout.hpp"

LobbyDialog::LobbyDialog( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style) : wxDialog(parent, id, title, pos, size, style), m_createGameDialog(NULL)
{
	this->SetSizer(new LobbyLayout(this));	
	this->Layout();
	this->Center();
} 

void LobbyDialog::joinPrivateSpadesGame(wxCommandEvent& event) {
  std::cout << "Join private Spades game!\n";
  std::cout.flush();
}
void LobbyDialog::joinPrivateHeartsGame(wxCommandEvent& event) {
  std::cout << "Join private Hearts game!\n";
  std::cout.flush();
}
void LobbyDialog::joinPublicSpadesGame(wxCommandEvent& event) {
  std::cout << "Join public Spades game!\n";
  std::cout.flush();
}
void LobbyDialog::joinPublicHeartsGame(wxCommandEvent& event) {
  std::cout << "Join public Hearts game!\n";
  std::cout.flush();
}
void LobbyDialog::createNewSpadesGame(wxCommandEvent& event) {
  std::cout << "Create new Spades game!\n";
  std::cout.flush();
  m_createGameDialog.Show();
  //m_parent->m_createGameDialog.Show();	
  //cannot do this need somehow to call parent stuff
}
void LobbyDialog::createNewHeartsGame(wxCommandEvent& event) {
  std::cout << "Create new Hearts game!\n";
  std::cout.flush();
  m_createGameDialog.Show();
}
