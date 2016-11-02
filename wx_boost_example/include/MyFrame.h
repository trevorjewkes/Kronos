#ifndef MYFRAME_H
#define MYFRAME_H

#include "wxDeck.h"
#include <wx/wxprec.h>
#ifndef WX_PRECOMP
    #include <wx/wx.h>
#endif
#include <cassert>
#include <vector>

enum
{
    ID_Hello = 1
};

class MyFrame: public wxFrame
{
public:
    MyFrame(const wxString& title, const wxPoint& pos, const wxSize& size);
private:
		std::vector<wxStaticBitmap*> m_cardHand;
		std::vector<wxStaticBitmap*> m_centerCards;
		wxDeck bmDeck;
		Turn turn = SECOND;
		wxStaticText* m_player1Text;
		wxStaticText* m_player2Text;
		wxStaticText* m_player3Text;
		wxStaticText* m_userText;
    void OnHello(wxCommandEvent& event);
    void OnExit(wxCommandEvent& event);
    void OnAbout(wxCommandEvent& event);
		void setCardHand(std::vector<Card_ID> cardIds);
		void cardEvent0(wxMouseEvent& event);
		void cardEvent1(wxMouseEvent& event);
		void cardEvent2(wxMouseEvent& event);
		void cardEvent3(wxMouseEvent& event);
		void cardEvent4(wxMouseEvent& event);
		void cardEvent5(wxMouseEvent& event);
		void cardEvent6(wxMouseEvent& event);
		void cardEvent7(wxMouseEvent& event);
		void cardEvent8(wxMouseEvent& event);
		void cardEvent9(wxMouseEvent& event);
		void cardEvent10(wxMouseEvent& event);
		void cardEvent11(wxMouseEvent& event);
		void cardEvent12(wxMouseEvent& event);
    wxDECLARE_EVENT_TABLE();
};

#endif /* ifndef MYFRAME_H */
