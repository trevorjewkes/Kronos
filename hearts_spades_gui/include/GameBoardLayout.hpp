#ifndef GAMEBOARDLAYOUT_HPP
#define GAMEBOARDLAYOUT_HPP

#include <wx/wxprec.h>
#ifndef WX_PRECOMP
    #include <wx/wx.h>
#endif

class GameBoardLayout : public wxBoxSizer
{
  public:
		GameBoardLayout(wxWindow* parent, int orient = wxVERTICAL);
  private:
    wxWindow* m_parent;
		wxStaticText* m_Player3Text;
    wxStaticText* m_player2Text;
		wxStaticText* m_player1Text;
		wxStaticBitmap* m_bitmap6;
		wxStaticBitmap* m_bitmap7;
		wxStaticBitmap* m_bitmap8;
		wxStaticBitmap* m_bitmap9;
		wxStaticBitmap* m_bitmap42;
		wxStaticBitmap* m_bitmap43;
		wxStaticBitmap* m_bitmap44;
		wxStaticBitmap* m_bitmap45;
		wxStaticBitmap* m_bitmap46;
		wxStaticBitmap* m_bitmap47;
		wxStaticBitmap* m_bitmap48;
		wxStaticBitmap* m_bitmap49;
		wxStaticBitmap* m_bitmap50;
		wxStaticBitmap* m_bitmap51;
		wxStaticBitmap* m_bitmap52;
		wxStaticBitmap* m_bitmap53;
		wxStaticBitmap* m_bitmap54;
		wxStaticText* m_staticText6;
};

#endif /* ifndef GAMEBOARDLAYOUT_HPP */
