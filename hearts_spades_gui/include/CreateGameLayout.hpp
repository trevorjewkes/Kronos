#ifndef CREATEGAMELAYOUT_HPP
#define CREATEGAMELAYOUT_HPP

#include <wx/wxprec.h>
#ifndef WX_PRECOMP
    #include <wx/wx.h>
#endif
#include "MainFrame.hpp"

class CreateGameLayout : public wxBoxSizer
{
	public:
		CreateGameLayout(CreateGameDialog* parent, int orient = wxVERTICAL);
		//a good size is wxSize(250,350) when put inside a frame
};

#endif /* ifndef CREATEGAMELAYOUT_HPP */
