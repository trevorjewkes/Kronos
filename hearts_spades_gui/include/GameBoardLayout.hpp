#ifndef GAMEBOARDLAYOUT_HPP
#define GAMEBOARDLAYOUT_HPP

#include <wx/wxprec.h>
#ifndef WX_PRECOMP
    #include <wx/wx.h>
#endif
#include <vector>

class GameBoardLayout : public wxBoxSizer
{
  public:
		GameBoardLayout(wxWindow* parent, int orient = wxVERTICAL);
  private:
    wxWindow* m_parent;
		wxStaticText* m_player3Text;
    wxStaticText* m_player2Text;
		wxStaticText* m_player1Text;
    wxStaticText* m_userText;
    std::vector<wxStaticBitmap*> m_center_cards;
    std::vector<wxStaticBitmap*> m_player_hand;
};

#endif /* ifndef GAMEBOARDLAYOUT_HPP */
