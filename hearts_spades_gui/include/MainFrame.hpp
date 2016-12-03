#ifndef MAINFRAME_HPP
#define MAINFRAME_HPP

#include <wx/wxprec.h>
#ifndef WX_PRECOMP
    #include <wx/wx.h>
#endif
#include <iostream>
#include "ServerDialog.hpp"
#include "LoginDialog.hpp"
#include "LobbyDialog.hpp"
#include "HeartsGame.hpp"
#include "CreateGameDialog.hpp"

enum State
{
	PASSING,
	PLAYING,
	WAITING
};

class MainFrame: public wxFrame
{
public:
	MainFrame(const wxString& title, const wxPoint& pos, const wxSize& size);
	ServerDialog m_serverDialog;
	LoginDialog m_loginDialog;
	LobbyDialog m_lobbyDialog;
  void cardClicked( wxMouseEvent& event )
  {
	  if (m_state == PASSING)
	  {
		  wxMessageBox("Passing Card");
		  if (gameHearts->pass(event.GetId()))
		  {
			  m_state = PLAYING;
			  SetStatusText("Play a card");
		  }
		  //UPDATESTATUS
	  }
	  else if (m_state == PLAYING)
	  {
		  wxMessageBox("Playing Card");
	  }
    std::cout << "Left Double Click: " << event.GetId() << std::endl;
  }
  void OnDialogClose( wxCloseEvent& event ) {
    wxMessageBox("Nope! You must'nt close this window");
  }
  void OnLogin() {
    SetStatusText(m_loginDialog.getUsername());
  }
private:
	wxMenuBar* m_menubar;
	wxMenu* m_menuFile;
	wxMenu* m_menuTest;
	wxMenu* m_menuServer;
	wxMenu* m_menuHelp;
	wxMenu* m_menuGameRules;
	std::vector<Player> players;
	HeartsGame* gameHearts;
	State m_state = WAITING;
  wxStaticText* playerText[4];
  std::vector<wxStaticBitmap*> m_center_cards;
  std::vector<wxStaticBitmap*> m_player_hand;

	void loadPlayerHand( wxCommandEvent& event );
	void loadCenterCards( wxCommandEvent& event );
	void serverSettingsDialog( wxCommandEvent& event );
	void connectToServer( wxCommandEvent& event );
	void showHeartsRules( wxCommandEvent& event );
	std::string getHeartsRules();
	void showSpadesRules( wxCommandEvent& event );
	std::string getSpadesRules();
	void startGame( wxCommandEvent& event );
	void OnExit(wxCommandEvent& event);
	void OnAbout(wxCommandEvent& event);
	wxDECLARE_EVENT_TABLE();
};

#endif /* ifndef MAINFRAME_HPP */

