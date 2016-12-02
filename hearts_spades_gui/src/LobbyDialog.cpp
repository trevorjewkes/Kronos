#include "LobbyDialog.hpp"
#include "LobbyLayout.hpp"

LobbyDialog::LobbyDialog( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style) : wxDialog(parent, id, title, pos, size, style), m_createHeartsGameDialog(NULL, "Create Hearts Game"), m_createSpadesGameDialog(NULL, "Create Spades Game")
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
	int res = wxMessageBox("Join public Spades game?", "Confirm", wxYES_NO, this);
	if (res == wxYES) 
    this->Show(false);
}
void LobbyDialog::joinPublicHeartsGame(wxCommandEvent& event) {
  std::cout << "Join public Hearts game!\n";
  std::cout.flush();
	int res = wxMessageBox("Join public Hearts game?", "Confirm", wxYES_NO, this);
	if (res == wxYES) 
    this->Show(false);
}
void LobbyDialog::createNewSpadesGame(wxCommandEvent& event) {
  std::cout << "Create new Spades game!\n";
  std::cout.flush();
  m_createSpadesGameDialog.Show();
}
void LobbyDialog::createNewHeartsGame(wxCommandEvent& event) {
  std::cout << "Create new Hearts game!\n";
  std::cout.flush();
  m_createHeartsGameDialog.Show();
}
