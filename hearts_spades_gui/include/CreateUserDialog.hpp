#ifndef CREATEUSERDIALOG_HPP
#define CREATEUSERDIALOG_HPP

#include <wx/wxprec.h>
#ifndef WX_PRECOMP
    #include <wx/wx.h>
#endif
#include <string>
#include <unordered_map>

class CreateUserDialog : public wxDialog
{
public:
	CreateUserDialog( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = "Create New User", const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxDefaultSize, long style = wxDEFAULT_DIALOG_STYLE|wxRESIZE_BORDER ); 
	void OnCreateUserBtn(wxCommandEvent& event);
  bool verifyUser(std::string const& username, std::string const& password);

private:
  void addUser(std::string const& username, std::string const& password);
  std::unordered_map<std::string, std::string> pw_hash;
  wxTextCtrl* m_textCtrlPassword1;
  wxTextCtrl* m_textCtrlPassword2;
  wxTextCtrl* m_textCtrlUsername;
};

#endif /* ifndef CREATEUSERDIALOG_HPP */
