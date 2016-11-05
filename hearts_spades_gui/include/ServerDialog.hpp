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
	ServerDialog( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = "Set Server IP and PORT", const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxDefaultSize, long style = wxDEFAULT_DIALOG_STYLE|wxRESIZE_BORDER|wxSTAY_ON_TOP); 
	std::string getIP() { return m_ip; };
	int getPort() { return m_port; };

private:
	std::string m_ip = "0.0.0.0";
	int m_port = 8080;
	wxStaticText* m_staticTextIP;
	wxTextCtrl* m_textCtrlIP;
	wxStaticText* m_staticTextPort;
	wxTextCtrl* m_textCtrlPort;
	wxButton* m_submitBtn;
	void OnClose(wxCommandEvent& event);
};

#endif /* ifndef SERVERDIALOG_HPP */
