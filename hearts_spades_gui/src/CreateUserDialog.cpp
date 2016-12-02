#include "CreateUserDialog.hpp"
#include "CreateUserLayout.hpp"

CreateUserDialog::CreateUserDialog( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : wxDialog( parent, id, title, pos, size, style)
{
  this->SetSizer(new CreateUserLayout(this));
  this->Layout();
  this->Center();
}

void CreateUserDialog::OnCreateUserBtn(wxCommandEvent& event)
{
  std::cout << "create new user!\n";
  std::cout.flush();
  this->Show(false);
}

