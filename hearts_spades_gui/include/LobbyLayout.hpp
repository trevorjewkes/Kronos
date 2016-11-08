#ifndef LOBBYLAYOUT_HPP
#define LOBBYLAYOUT_HPP

#include <wx/wxprec.h>
#ifndef WX_PRECOMP
    #include <wx/wx.h>
#endif
#include "MainFrame.hpp"

class LobbyLayout : public wxBoxSizer
{
	public:
		LobbyLayout(MainFrame* parent, int orient = wxVERTICAL);
		//good size wxSize(350,350);
};

#endif /* ifndef LOBBYLAYOUT_HPP */
