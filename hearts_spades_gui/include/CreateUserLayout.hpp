#ifndef CREATEUSERLAYOUT_HPP
#define CREATEUSERLAYOUT_HPP

#include <wx/wxprec.h>
#ifndef WX_PRECOMP
    #include <wx/wx.h>
#endif
#include "CreateUserLayout.hpp"
#include "CreateUserDialog.hpp"

class CreateUserLayout : public wxBoxSizer
{
	public:
		CreateUserLayout(CreateUserDialog* parent, int orient = wxVERTICAL);
		//good size is wxSize(350,350)
};

#endif /* ifndef CREATEUSERLAYOUT_HPP */
