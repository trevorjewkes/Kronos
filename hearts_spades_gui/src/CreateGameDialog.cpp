#include "CreateGameDialog.hpp"
#include "CreateGameLayout.hpp"

CreateGameDialog::CreateGameDialog( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style) : wxDialog(parent, id, title, pos, size, style)
{
	this->SetSizer(new CreateGameLayout(this));	
	this->Layout();
	this->Center();
} 

void CreateGameDialog::createGameBtn(wxCommandEvent& event) {
  std::cout << "create new game!\n";
  std::cout.flush();
  this->Show(false);
}
