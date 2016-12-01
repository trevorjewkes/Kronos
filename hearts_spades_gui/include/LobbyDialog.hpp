#ifndef LOBBYDIALOG_HPP
#define LOBBYDIALOG_HPP

#include <wx/wxprec.h>
#ifndef WX_PRECOMP
    #include <wx/wx.h>
#endif

class LobbyDialog : public wxDialog
{
public:	
	LobbyDialog( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = wxEmptyString, const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxDefaultSize, long style = wxDEFAULT_DIALOG_STYLE ); 
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
		//m_parent->m_createGameDialog.Show();	
		//cannot do this need somehow to call parent stuff
	}
	void createNewHeartsGame(wxCommandEvent& event) {
		std::cout << "Create new Hearts game!\n";
		std::cout.flush();
	}

	private:
		wxWindow* m_parent;
};

#endif /* ifndef LOBBYDIALOG_HPP */
