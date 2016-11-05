#ifndef RULESWINDOW_HPP
#define RULESWINDOW_HPP

#include <wx/wxprec.h>
#ifndef WX_PRECOMP
    #include <wx/wx.h>
#endif
#include <string>

class RulesWindow : public wxScrolledWindow
{
public:
	RulesWindow(wxWindow* parent, wxWindowID id, std::string rules);

private:
	std::string m_rules;
};

#endif /* ifndef RULESWINDOW_HPP */
