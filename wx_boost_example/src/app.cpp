#include "wxDeck.h"

// For compilers that support precompilation, includes "wx/wx.h".
#include <wx/wxprec.h>
#ifndef WX_PRECOMP
    #include <wx/wx.h>
#endif
#include <cassert>
#include <vector>
#include <iostream>

class MyApp: public wxApp
{
public:
    virtual bool OnInit();
};

class Button : public wxFrame {
  public:
    Button(const wxString& title);
    void OnQuit(wxCommandEvent & event);
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


enum
{
    ID_Hello = 1
};

wxBEGIN_EVENT_TABLE(MyFrame, wxFrame)
    EVT_MENU(ID_Hello,   MyFrame::OnHello)
    EVT_MENU(wxID_EXIT,  MyFrame::OnExit)
    EVT_MENU(wxID_ABOUT, MyFrame::OnAbout)
wxEND_EVENT_TABLE()

wxIMPLEMENT_APP(MyApp);

bool MyApp::OnInit()
{
    MyFrame *frame = new MyFrame( "Card Test", wxPoint(50, 50), wxSize(650, 440) );
    frame->Show( true );
    return true;
}
MyFrame::MyFrame(const wxString& title, const wxPoint& pos, const wxSize& size)
        : wxFrame(NULL, wxID_ANY, title, pos, size)
{
    wxMenu *menuFile = new wxMenu;
    menuFile->Append(ID_Hello, "&Hello...\tCtrl-H",
                     "Help string shown in status bar for this menu item");
    menuFile->AppendSeparator();
    menuFile->Append(wxID_EXIT);
    wxMenu *menuHelp = new wxMenu;
    menuHelp->Append(wxID_ABOUT);
    wxMenuBar *menuBar = new wxMenuBar;
    menuBar->Append( menuFile, "&File" );
    menuBar->Append( menuHelp, "&Help" );
    SetMenuBar( menuBar );
    CreateStatusBar();
    SetStatusText( "Welcome to wxWidgets!" );

		//-------------------------------------------------------------
		//The top player info
		wxBoxSizer* bSizer;
		bSizer = new wxBoxSizer( wxVERTICAL );
		m_player2Text = new wxStaticText( this, wxID_ANY, wxT("Player 2\nTricks: 2\nScore: 2"), wxDefaultPosition, wxDefaultSize, 0 );
		bSizer->Add(m_player2Text, 0, wxALL|wxALIGN_CENTER_HORIZONTAL, 5);

		//-------------------------------------------------------------
		//The middle row | Player1 | Center cards | Player 3 |

		//Player1
		wxGridSizer* gSizer1;
		gSizer1 = new wxGridSizer(0, 3, 0, 0); //3 columns

		m_player1Text = new wxStaticText( this, wxID_ANY, wxT("Player 1\nTricks: 1\nScore: 1"), wxDefaultPosition, wxDefaultSize, 0 );
		gSizer1->Add(m_player1Text, 0, wxALL|wxALIGN_CENTER_HORIZONTAL, 5);

		//the middle cards
		wxFlexGridSizer* fgSizer1;
		fgSizer1 = new wxFlexGridSizer( 0, 4, 0, 0 ); //4 items
		fgSizer1->SetFlexibleDirection( wxBOTH );
		fgSizer1->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );

		//initialize the cards
		wxStaticBitmap* tmpCard;
		for (int i = 0; i < 3; ++i) {
			tmpCard = new wxStaticBitmap( this,
																		wxID_ANY,
																		wxBitmap(bmDeck[D01] ,
																		wxBITMAP_TYPE_ANY ),
																		wxDefaultPosition,
																		wxDefaultSize,
																		0 );
			m_centerCards.push_back(tmpCard);	
			fgSizer1->Add(tmpCard, 0, wxTOP|wxBOTTOM, 5);
		}
		//last card needs to be full size
		tmpCard = new wxStaticBitmap( this, wxID_ANY, wxBitmap(bmDeck[D01F], wxBITMAP_TYPE_ANY), wxDefaultPosition, wxDefaultSize, 0 );
		m_centerCards.push_back(tmpCard);
		fgSizer1->Add( tmpCard, 0, wxTOP|wxBOTTOM, 5 );
		assert(m_centerCards.size() == 4);

		gSizer1->Add(fgSizer1, 0, wxALL, 5);

		//player3
		m_player3Text = new wxStaticText( this, wxID_ANY, wxT("Player 3\nTricks: 3\nScore: 3"), wxDefaultPosition, wxDefaultSize, 0 );
		gSizer1->Add(m_player3Text, 0, wxALL|wxALIGN_CENTER_HORIZONTAL, 5);

		bSizer->Add(gSizer1, 0, wxALL, 5);

		//-------------------------------------------------------------
		//The user hand and info layout 
		wxFlexGridSizer* fgSizer2;
		fgSizer2 = new wxFlexGridSizer( 0, 16, 0, 0 );
		fgSizer2->SetFlexibleDirection( wxBOTH );
		fgSizer2->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );

		fgSizer2->Add(40, 0, 1, wxEXPAND, 5); //spacer

		//initialize the cards in m_cardHand
		//code generated from clickHelper.py
tmpCard = new wxStaticBitmap( this,
wxID_ANY,
wxBitmap( bmDeck[D01],
wxBITMAP_TYPE_ANY ),
wxDefaultPosition,
wxDefaultSize,
0 );
m_cardHand.push_back(tmpCard);
fgSizer2->Add(tmpCard, 0, wxTOP|wxBOTTOM, 5);
tmpCard->Connect( wxEVT_LEFT_DCLICK, wxMouseEventHandler( MyFrame::cardEvent0), NULL, this );
tmpCard = new wxStaticBitmap( this,
wxID_ANY,
wxBitmap( bmDeck[D02],
wxBITMAP_TYPE_ANY ),
wxDefaultPosition,
wxDefaultSize,
0 );
m_cardHand.push_back(tmpCard);
fgSizer2->Add(tmpCard, 0, wxTOP|wxBOTTOM, 5);
tmpCard->Connect( wxEVT_LEFT_DCLICK, wxMouseEventHandler( MyFrame::cardEvent1), NULL, this );
tmpCard = new wxStaticBitmap( this,
wxID_ANY,
wxBitmap( bmDeck[D03],
wxBITMAP_TYPE_ANY ),
wxDefaultPosition,
wxDefaultSize,
0 );
m_cardHand.push_back(tmpCard);
fgSizer2->Add(tmpCard, 0, wxTOP|wxBOTTOM, 5);
tmpCard->Connect( wxEVT_LEFT_DCLICK, wxMouseEventHandler( MyFrame::cardEvent2), NULL, this );
tmpCard = new wxStaticBitmap( this,
wxID_ANY,
wxBitmap( bmDeck[D04],
wxBITMAP_TYPE_ANY ),
wxDefaultPosition,
wxDefaultSize,
0 );
m_cardHand.push_back(tmpCard);
fgSizer2->Add(tmpCard, 0, wxTOP|wxBOTTOM, 5);
tmpCard->Connect( wxEVT_LEFT_DCLICK, wxMouseEventHandler( MyFrame::cardEvent3), NULL, this );
tmpCard = new wxStaticBitmap( this,
wxID_ANY,
wxBitmap( bmDeck[D05],
wxBITMAP_TYPE_ANY ),
wxDefaultPosition,
wxDefaultSize,
0 );
m_cardHand.push_back(tmpCard);
fgSizer2->Add(tmpCard, 0, wxTOP|wxBOTTOM, 5);
tmpCard->Connect( wxEVT_LEFT_DCLICK, wxMouseEventHandler( MyFrame::cardEvent4), NULL, this );
tmpCard = new wxStaticBitmap( this,
wxID_ANY,
wxBitmap( bmDeck[D06],
wxBITMAP_TYPE_ANY ),
wxDefaultPosition,
wxDefaultSize,
0 );
m_cardHand.push_back(tmpCard);
fgSizer2->Add(tmpCard, 0, wxTOP|wxBOTTOM, 5);
tmpCard->Connect( wxEVT_LEFT_DCLICK, wxMouseEventHandler( MyFrame::cardEvent5), NULL, this );
tmpCard = new wxStaticBitmap( this,
wxID_ANY,
wxBitmap( bmDeck[D07],
wxBITMAP_TYPE_ANY ),
wxDefaultPosition,
wxDefaultSize,
0 );
m_cardHand.push_back(tmpCard);
fgSizer2->Add(tmpCard, 0, wxTOP|wxBOTTOM, 5);
tmpCard->Connect( wxEVT_LEFT_DCLICK, wxMouseEventHandler( MyFrame::cardEvent6), NULL, this );
tmpCard = new wxStaticBitmap( this,
wxID_ANY,
wxBitmap( bmDeck[D08],
wxBITMAP_TYPE_ANY ),
wxDefaultPosition,
wxDefaultSize,
0 );
m_cardHand.push_back(tmpCard);
fgSizer2->Add(tmpCard, 0, wxTOP|wxBOTTOM, 5);
tmpCard->Connect( wxEVT_LEFT_DCLICK, wxMouseEventHandler( MyFrame::cardEvent7), NULL, this );
tmpCard = new wxStaticBitmap( this,
wxID_ANY,
wxBitmap( bmDeck[D09],
wxBITMAP_TYPE_ANY ),
wxDefaultPosition,
wxDefaultSize,
0 );
m_cardHand.push_back(tmpCard);
fgSizer2->Add(tmpCard, 0, wxTOP|wxBOTTOM, 5);
tmpCard->Connect( wxEVT_LEFT_DCLICK, wxMouseEventHandler( MyFrame::cardEvent8), NULL, this );
tmpCard = new wxStaticBitmap( this,
wxID_ANY,
wxBitmap( bmDeck[D10],
wxBITMAP_TYPE_ANY ),
wxDefaultPosition,
wxDefaultSize,
0 );
m_cardHand.push_back(tmpCard);
fgSizer2->Add(tmpCard, 0, wxTOP|wxBOTTOM, 5);
tmpCard->Connect( wxEVT_LEFT_DCLICK, wxMouseEventHandler( MyFrame::cardEvent9), NULL, this );
tmpCard = new wxStaticBitmap( this,
wxID_ANY,
wxBitmap( bmDeck[D11],
wxBITMAP_TYPE_ANY ),
wxDefaultPosition,
wxDefaultSize,
0 );
m_cardHand.push_back(tmpCard);
fgSizer2->Add(tmpCard, 0, wxTOP|wxBOTTOM, 5);
tmpCard->Connect( wxEVT_LEFT_DCLICK, wxMouseEventHandler( MyFrame::cardEvent10), NULL, this );
tmpCard = new wxStaticBitmap( this,
wxID_ANY,
wxBitmap( bmDeck[D12],
wxBITMAP_TYPE_ANY ),
wxDefaultPosition,
wxDefaultSize,
0 );
m_cardHand.push_back(tmpCard);
fgSizer2->Add(tmpCard, 0, wxTOP|wxBOTTOM, 5);
tmpCard->Connect( wxEVT_LEFT_DCLICK, wxMouseEventHandler( MyFrame::cardEvent11), NULL, this );
// end of code generation

		//last card needs to be full size
		tmpCard = new wxStaticBitmap( this, wxID_ANY, wxBitmap( bmDeck[H11F], wxBITMAP_TYPE_ANY ), wxDefaultPosition, wxDefaultSize, 0 );
		tmpCard->Connect( wxEVT_LEFT_DCLICK, wxMouseEventHandler( MyFrame::cardEvent12 ), NULL, this );
		m_cardHand.push_back(tmpCard);
		fgSizer2->Add( tmpCard, 0, wxTOP|wxBOTTOM, 5 );
		assert(m_cardHand.size() == 13);
		//-------------------------------------------------------------

		fgSizer2->Add(40, 0, 1, wxEXPAND, 5); //spacer

		m_userText = new wxStaticText( this, wxID_ANY, wxT("Player 7\nTricks: 7\nScore: 7"), wxDefaultPosition, wxDefaultSize, 0 );
		fgSizer2->Add(m_userText, 0, wxALL|wxALIGN_CENTER_HORIZONTAL, 5);


		bSizer->Add(fgSizer2, 1, wxEXPAND, 5);

		this->SetSizer(bSizer);
		this->Layout();
		this->Center(wxBOTH);
}
void MyFrame::OnExit(wxCommandEvent& event)
{
    Close( true );
}
void MyFrame::OnAbout(wxCommandEvent& event)
{
    wxMessageBox( "This is a wxWidgets' Hello world sample",
                  "About Hello World", wxOK | wxICON_INFORMATION );
		std::vector<Card_ID> newHand = {C01,C02,C03,C03,C04,C05,C05,C10,C12,D06,H02,D02,C02F};
		setCardHand(newHand);
}
void MyFrame::OnHello(wxCommandEvent& event)
{
    wxLogMessage("Hello world from wxWidgets!");
}

//code generation from clickHelper.py
void MyFrame::cardEvent0(wxMouseEvent& event)
{
m_centerCards[(int)turn]->SetBitmap(m_cardHand[0]->GetBitmap());
SetStatusText("card 0 clicked");
}

void MyFrame::cardEvent1(wxMouseEvent& event)
{
m_centerCards[(int)turn]->SetBitmap(m_cardHand[1]->GetBitmap());
SetStatusText("card 1 clicked");
}

void MyFrame::cardEvent2(wxMouseEvent& event)
{
m_centerCards[(int)turn]->SetBitmap(m_cardHand[2]->GetBitmap());
SetStatusText("card 2 clicked");
}

void MyFrame::cardEvent3(wxMouseEvent& event)
{
m_centerCards[(int)turn]->SetBitmap(m_cardHand[3]->GetBitmap());
SetStatusText("card 3 clicked");
}

void MyFrame::cardEvent4(wxMouseEvent& event)
{
m_centerCards[(int)turn]->SetBitmap(m_cardHand[4]->GetBitmap());
SetStatusText("card 4 clicked");
}

void MyFrame::cardEvent5(wxMouseEvent& event)
{
m_centerCards[(int)turn]->SetBitmap(m_cardHand[5]->GetBitmap());
SetStatusText("card 5 clicked");
}

void MyFrame::cardEvent6(wxMouseEvent& event)
{
m_centerCards[(int)turn]->SetBitmap(m_cardHand[6]->GetBitmap());
SetStatusText("card 6 clicked");
}

void MyFrame::cardEvent7(wxMouseEvent& event)
{
m_centerCards[(int)turn]->SetBitmap(m_cardHand[7]->GetBitmap());
SetStatusText("card 7 clicked");
}

void MyFrame::cardEvent8(wxMouseEvent& event)
{
m_centerCards[(int)turn]->SetBitmap(m_cardHand[8]->GetBitmap());
SetStatusText("card 8 clicked");
}

void MyFrame::cardEvent9(wxMouseEvent& event)
{
m_centerCards[(int)turn]->SetBitmap(m_cardHand[9]->GetBitmap());
SetStatusText("card 9 clicked");
}

void MyFrame::cardEvent10(wxMouseEvent& event)
{
m_centerCards[(int)turn]->SetBitmap(m_cardHand[10]->GetBitmap());
SetStatusText("card 10 clicked");
}

void MyFrame::cardEvent11(wxMouseEvent& event)
{
m_centerCards[(int)turn]->SetBitmap(m_cardHand[11]->GetBitmap());
SetStatusText("card 11 clicked");
}

void MyFrame::cardEvent12(wxMouseEvent& event)
{
m_centerCards[(int)turn]->SetBitmap(m_cardHand[12]->GetBitmap());
SetStatusText("card 12 clicked");
}
//end of code generation
void MyFrame::setCardHand(std::vector<Card_ID> cardIds)
{
	for (int i = 0; i < 13; ++i) {
		m_cardHand[i]->SetBitmap(wxBitmap( bmDeck[cardIds[i]], wxBITMAP_TYPE_ANY ));
	}
}

Button::Button(const wxString& title)
       : wxFrame(NULL, wxID_ANY, title, wxDefaultPosition, wxSize(270, 150))
{
  wxPanel *panel = new wxPanel(this, wxID_ANY);

  wxButton *button = new wxButton(panel, wxID_EXIT, wxT("Quit"), 
      wxPoint(20, 20));
  Connect(wxID_EXIT, wxEVT_COMMAND_BUTTON_CLICKED, 
      wxCommandEventHandler(Button::OnQuit));
  button->SetFocus();
  Centre();
}

void Button::OnQuit(wxCommandEvent & WXUNUSED(event))
{
    Close(true);
}

