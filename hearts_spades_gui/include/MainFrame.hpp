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
#include "CreateGameDialog.hpp"

class MainFrame: public wxFrame
{
public:
	MainFrame(const wxString& title, const wxPoint& pos, const wxSize& size);
  void cardClicked( wxMouseEvent& event )
  {
    std::cout << "Left Double Click: " << event.LeftDClick() << std::endl;
  }
private:
	ServerDialog m_serverDialog;
	LoginDialog m_loginDialog;
	LobbyDialog m_lobbyDialog;
	CreateGameDialog m_createGameDialog;
	wxMenuBar* m_menubar;
	wxMenu* m_menuFile;
	wxMenu* m_menuTest;
	wxMenu* m_menuServer;
	wxMenu* m_menuHelp;
	wxMenu* m_menuGameRules;

	void loadPlayerHand( wxCommandEvent& event );
	void loadCenterCards( wxCommandEvent& event );
	void serverSettingsDialog( wxCommandEvent& event );
	void connectToServer( wxCommandEvent& event );
	void showHeartsRules( wxCommandEvent& event );
	std::string getHeartsRules();
	void showSpadesRules( wxCommandEvent& event );
	std::string getSpadesRules();
	void OnExit(wxCommandEvent& event);
	void OnAbout(wxCommandEvent& event);
	wxDECLARE_EVENT_TABLE();
};

#endif /* ifndef MAINFRAME_HPP */

