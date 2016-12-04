#ifndef MAINFRAME_HPP
#define MAINFRAME_HPP

#include <wx/wxprec.h>
#ifndef WX_PRECOMP
    #include <wx/wx.h>
#endif
#include <iostream>
#include <chrono>
#include <thread>
#include "ServerDialog.hpp"
#include "LoginDialog.hpp"
#include "LobbyDialog.hpp"
#include "HeartsGame.hpp"
#include "SpadesGame.hpp"
#include "CreateGameDialog.hpp"

enum State
{
	PASSING,
	PLAYING,
	BIDDING,
	WAITING
};

enum GameState
{
	H,
	S
};

class MainFrame: public wxFrame
{
public:
	MainFrame(const wxString& title, const wxPoint& pos, const wxSize& size);
	ServerDialog m_serverDialog;
	LoginDialog m_loginDialog;
	LobbyDialog m_lobbyDialog;
	void cardClicked(wxMouseEvent& event);
  
  void OnDialogClose( wxCloseEvent& event ) {
    wxMessageBox("Nope! You must'nt close this window");
  }
  void OnLogin() {
    SetStatusText(m_loginDialog.getUsername());
  }
  void updateScreen(Status status);
  void updateScreen2();
  void updatePlayerHand(std::vector<Card> hand);
  void updateCenterCards(std::vector<Card> cards);
  void updateStats(std::vector<int> scores, std::vector<int> tricks, std::vector<int> bids);
private:
	wxMenuBar* m_menubar;
	wxMenu* m_menuFile;
	wxMenu* m_menuTest;
	wxMenu* m_menuServer;
	wxMenu* m_menuHelp;
	wxMenu* m_menuGameRules;
	std::vector<Player> players;
	HeartsGame* gameHearts;
	SpadesGame* gameSpades;
	State m_state = WAITING;
	GameState m_gameState;
  wxStaticText* playerText[4];
  std::vector<wxStaticBitmap*> m_center_cards;
  std::vector<wxStaticBitmap*> m_player_hand;

	void loadPlayerHand( wxCommandEvent& event );
	void loadCenterCards( wxCommandEvent& event );
  std::string getSuitString(Suit suit) {
    switch (suit) {
      case 0:
        return "clubs";
        break;
      case 1:
        return "hearts";
        break;
      case 2:
        return "spades";
        break;
      case 3:
        return "diamonds";
        break;
      default:
        return "invalid";
    }
  };
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

