#ifndef LOGINLAYOUT_HPP
#define LOGINLAYOUT_HPP

#include <wx/wxprec.h>
#ifndef WX_PRECOMP
    #include <wx/wx.h>
#endif
#include "MainFrame.hpp"

class LoginLayout : public wxBoxSizer
{
	public:
		LoginLayout(LoginDialog* parent, int orient = wxVERTICAL);
		//good size is wxSize(350,350)
};

#endif /* ifndef LOGINLAYOUT_HPP */
