#ifndef SERVERDIALOG_HPP
#define SERVERDIALOG_HPP

#include <wx/wxprec.h>
#ifndef WX_PRECOMP
    #include <wx/wx.h>
#endif
#include <string>

class ServerDialog : public wxDialog 
{
public:
	ServerDialog( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = "Server Settings", const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxDefaultSize, long style = wxDEFAULT_DIALOG_STYLE ); 
	std::string getIP() { return m_ip; };
	int getPort() { return m_port; };
private:

protected:
	std::string m_ip;
	int m_port;
	wxWindow* m_parent;
	wxStaticText* m_staticTextIP;
	wxTextCtrl* m_textCtrlIP;
	wxStaticText* m_staticTextPort;
	wxTextCtrl* m_textCtrlPort;
	wxButton* m_submitBtn;
	void OnClose(wxCommandEvent& event);
};

#endif /* ifndef SERVERDIALOG_HPP */
