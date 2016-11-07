#ifndef MAINFRAME_HPP
#define MAINFRAME_HPP

#include <wx/wxprec.h>
#ifndef WX_PRECOMP
    #include <wx/wx.h>
#endif
#include <iostream>
#include "ServerDialog.hpp"

class MainFrame: public wxFrame
{
public:
	MainFrame(const wxString& title, const wxPoint& pos, const wxSize& size);
	void joinPrivateSpadesGame(wxCommandEvent& event) {
		std::cout << "Join private Spades game!\n";
		std::cout.flush();
	}
	void joinPrivateHeartsGame(wxCommandEvent& event) {
		std::cout << "Join private Hearts game!\n";
		std::cout.flush();
	}
	void joinPublicSpadesGame(wxCommandEvent& event) {
		std::cout << "Join public Spades game!\n";
		std::cout.flush();
	}
	void joinPublicHeartsGame(wxCommandEvent& event) {
		std::cout << "Join public Hearts game!\n";
		std::cout.flush();
	}
	void createNewSpadesGame(wxCommandEvent& event) {
		std::cout << "Create new Spades game!\n";
		std::cout.flush();
	}
	void createNewHeartsGame(wxCommandEvent& event) {
		std::cout << "Create new Hearts game!\n";
		std::cout.flush();
	}
private:
	ServerDialog m_serverDialog;
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

