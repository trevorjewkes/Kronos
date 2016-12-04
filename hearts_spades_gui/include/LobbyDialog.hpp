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
	void joinPrivateSpadesGame(wxCommandEvent& event);
	void joinPrivateHeartsGame(wxCommandEvent& event);
	void joinPublicSpadesGame(wxCommandEvent& event); 
	void joinPublicHeartsGame(wxCommandEvent& event); 
	void createNewSpadesGame(wxCommandEvent& event);
	void createNewHeartsGame(wxCommandEvent& event);
};

#endif /* ifndef LOBBYDIALOG_HPP */
