#include "LobbyDialog.hpp"
#include "LobbyLayout.hpp"

LobbyDialog::LobbyDialog( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style) : wxDialog(parent, id, title, pos, size, style), m_createHeartsGameDialog(NULL, "Create Hearts Game"), m_createSpadesGameDialog(NULL, "Create Spades Game")
{
	wxInitAllImageHandlers();
	this->SetSizer(new LobbyLayout(this));	
	this->Layout();
	this->Center();

  this->Connect( wxEVT_CLOSE_WINDOW, wxCloseEventHandler( MainFrame::OnDialogClose ) , NULL, parent);
} 

void LobbyDialog::joinPrivateSpadesGame(wxCommandEvent& event) {
  wxTextEntryDialog input(this, "Enter name of private game:", "Join Private Spades Game");
  if (input.ShowModal() == wxID_OK) {
    if ((std::string)input.GetValue() == "private") {
      this->Show(false);
      //set state to private game
    } else {
      wxMessageBox("There is not private game with that name."); 
    }
  }
}
void LobbyDialog::joinPrivateHeartsGame(wxCommandEvent& event) {
  wxTextEntryDialog input(this, "Enter name of private game:", "Join Private Hearts Game");
  if (input.ShowModal() == wxID_OK) {
    if ((std::string)input.GetValue() == "private") {
      this->Show(false);
      //set state to private game
    } else {
      wxMessageBox("There is not private game with that name."); 
    }
  }
}
void LobbyDialog::joinPublicSpadesGame(wxCommandEvent& event) {
	int res = wxMessageBox("Join public Spades game?", "Confirm", wxYES_NO, this);
	if (res == wxYES) 
    this->Show(false);
}
void LobbyDialog::joinPublicHeartsGame(wxCommandEvent& event) {
	int res = wxMessageBox("Join public Hearts game?", "Confirm", wxYES_NO, this);
	if (res == wxYES) 
    this->Show(false);
}
void LobbyDialog::createNewSpadesGame(wxCommandEvent& event) {
  m_createSpadesGameDialog.Show();
}
void LobbyDialog::createNewHeartsGame(wxCommandEvent& event) {
  m_createHeartsGameDialog.Show();
}
