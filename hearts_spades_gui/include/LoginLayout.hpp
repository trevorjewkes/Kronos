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
		LoginLayout(MainFrame* parent, int orient = wxVERTICAL);
};

#endif /* ifndef LOGINLAYOUT_HPP */
