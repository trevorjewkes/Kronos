#ifndef LOBBYDIALOG_HPP
#define LOBBYDIALOG_HPP

#include "CreateGameDialog.hpp"
#include <wx/wxprec.h>
#ifndef WX_PRECOMP
    #include <wx/wx.h>
#endif

class LobbyDialog : public wxDialog
{
public:	
	LobbyDialog( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = "Game Lobby", const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxDefaultSize, long style = wxDEFAULT_DIALOG_STYLE|wxRESIZE_BORDER ); 
	CreateGameDialog m_createHeartsGameDialog;
	CreateGameDialog m_createSpadesGameDialog;
  wxButton* m_joinPrivateHeartsBtn;
  wxButton* m_joinPublicHeartsBtn;
  wxButton* m_joinPrivateSpadesBtn;
  wxButton* m_joinPublicSpadesBtn;
	void createNewSpadesGame(wxCommandEvent& event);
	void createNewHeartsGame(wxCommandEvent& event);
};

#endif /* ifndef LOBBYDIALOG_HPP */
