#ifndef LOGINLAYOUT_HPP
#define LOGINLAYOUT_HPP

#include <wx/wxprec.h>
#ifndef WX_PRECOMP
    #include <wx/wx.h>
#endif

class LoginLayout : public wxBoxSizer
{
	public:
		LoginLayout(wxWindow* parent, wxString msg, int orient = wxVERTICAL);
};

#endif /* ifndef LOGINLAYOUT_HPP */
