#include "GameFrame.h"

wxBEGIN_EVENT_TABLE(GameFrame, wxFrame)
    EVT_MENU(ID_Hello,   GameFrame::OnHello)
    EVT_MENU(wxID_EXIT,  GameFrame::OnExit)
    EVT_MENU(wxID_ABOUT, GameFrame::OnAbout)
wxEND_EVENT_TABLE()

GameFrame::GameFrame(const wxString& title, const wxPoint& pos, const wxSize& size)
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
																		wxBitmap(bmDeck[BLANK] ,
																		wxBITMAP_TYPE_ANY ),
																		wxDefaultPosition,
																		wxDefaultSize,
																		0 );
			m_centerCards.push_back(tmpCard);	
			fgSizer1->Add(tmpCard, 0, wxTOP|wxBOTTOM, 5);
		}
		//last card needs to be full size
		tmpCard = new wxStaticBitmap( this, wxID_ANY, wxBitmap(bmDeck[BLANK_F], wxBITMAP_TYPE_ANY), wxDefaultPosition, wxDefaultSize, 0 );
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
tmpCard->Connect( wxEVT_LEFT_DCLICK, wxMouseEventHandler( GameFrame::cardEvent0), NULL, this );
tmpCard = new wxStaticBitmap( this,
wxID_ANY,
wxBitmap( bmDeck[D02],
wxBITMAP_TYPE_ANY ),
wxDefaultPosition,
wxDefaultSize,
0 );
m_cardHand.push_back(tmpCard);
fgSizer2->Add(tmpCard, 0, wxTOP|wxBOTTOM, 5);
tmpCard->Connect( wxEVT_LEFT_DCLICK, wxMouseEventHandler( GameFrame::cardEvent1), NULL, this );
tmpCard = new wxStaticBitmap( this,
wxID_ANY,
wxBitmap( bmDeck[D03],
wxBITMAP_TYPE_ANY ),
wxDefaultPosition,
wxDefaultSize,
0 );
m_cardHand.push_back(tmpCard);
fgSizer2->Add(tmpCard, 0, wxTOP|wxBOTTOM, 5);
tmpCard->Connect( wxEVT_LEFT_DCLICK, wxMouseEventHandler( GameFrame::cardEvent2), NULL, this );
tmpCard = new wxStaticBitmap( this,
wxID_ANY,
wxBitmap( bmDeck[D04],
wxBITMAP_TYPE_ANY ),
wxDefaultPosition,
wxDefaultSize,
0 );
m_cardHand.push_back(tmpCard);
fgSizer2->Add(tmpCard, 0, wxTOP|wxBOTTOM, 5);
tmpCard->Connect( wxEVT_LEFT_DCLICK, wxMouseEventHandler( GameFrame::cardEvent3), NULL, this );
tmpCard = new wxStaticBitmap( this,
wxID_ANY,
wxBitmap( bmDeck[D05],
wxBITMAP_TYPE_ANY ),
wxDefaultPosition,
wxDefaultSize,
0 );
m_cardHand.push_back(tmpCard);
fgSizer2->Add(tmpCard, 0, wxTOP|wxBOTTOM, 5);
tmpCard->Connect( wxEVT_LEFT_DCLICK, wxMouseEventHandler( GameFrame::cardEvent4), NULL, this );
tmpCard = new wxStaticBitmap( this,
wxID_ANY,
wxBitmap( bmDeck[D06],
wxBITMAP_TYPE_ANY ),
wxDefaultPosition,
wxDefaultSize,
0 );
m_cardHand.push_back(tmpCard);
fgSizer2->Add(tmpCard, 0, wxTOP|wxBOTTOM, 5);
tmpCard->Connect( wxEVT_LEFT_DCLICK, wxMouseEventHandler( GameFrame::cardEvent5), NULL, this );
tmpCard = new wxStaticBitmap( this,
wxID_ANY,
wxBitmap( bmDeck[D07],
wxBITMAP_TYPE_ANY ),
wxDefaultPosition,
wxDefaultSize,
0 );
m_cardHand.push_back(tmpCard);
fgSizer2->Add(tmpCard, 0, wxTOP|wxBOTTOM, 5);
tmpCard->Connect( wxEVT_LEFT_DCLICK, wxMouseEventHandler( GameFrame::cardEvent6), NULL, this );
tmpCard = new wxStaticBitmap( this,
wxID_ANY,
wxBitmap( bmDeck[D08],
wxBITMAP_TYPE_ANY ),
wxDefaultPosition,
wxDefaultSize,
0 );
m_cardHand.push_back(tmpCard);
fgSizer2->Add(tmpCard, 0, wxTOP|wxBOTTOM, 5);
tmpCard->Connect( wxEVT_LEFT_DCLICK, wxMouseEventHandler( GameFrame::cardEvent7), NULL, this );
tmpCard = new wxStaticBitmap( this,
wxID_ANY,
wxBitmap( bmDeck[D09],
wxBITMAP_TYPE_ANY ),
wxDefaultPosition,
wxDefaultSize,
0 );
m_cardHand.push_back(tmpCard);
fgSizer2->Add(tmpCard, 0, wxTOP|wxBOTTOM, 5);
tmpCard->Connect( wxEVT_LEFT_DCLICK, wxMouseEventHandler( GameFrame::cardEvent8), NULL, this );
tmpCard = new wxStaticBitmap( this,
wxID_ANY,
wxBitmap( bmDeck[D10],
wxBITMAP_TYPE_ANY ),
wxDefaultPosition,
wxDefaultSize,
0 );
m_cardHand.push_back(tmpCard);
fgSizer2->Add(tmpCard, 0, wxTOP|wxBOTTOM, 5);
tmpCard->Connect( wxEVT_LEFT_DCLICK, wxMouseEventHandler( GameFrame::cardEvent9), NULL, this );
tmpCard = new wxStaticBitmap( this,
wxID_ANY,
wxBitmap( bmDeck[D11],
wxBITMAP_TYPE_ANY ),
wxDefaultPosition,
wxDefaultSize,
0 );
m_cardHand.push_back(tmpCard);
fgSizer2->Add(tmpCard, 0, wxTOP|wxBOTTOM, 5);
tmpCard->Connect( wxEVT_LEFT_DCLICK, wxMouseEventHandler( GameFrame::cardEvent10), NULL, this );
tmpCard = new wxStaticBitmap( this,
wxID_ANY,
wxBitmap( bmDeck[D12],
wxBITMAP_TYPE_ANY ),
wxDefaultPosition,
wxDefaultSize,
0 );
m_cardHand.push_back(tmpCard);
fgSizer2->Add(tmpCard, 0, wxTOP|wxBOTTOM, 5);
tmpCard->Connect( wxEVT_LEFT_DCLICK, wxMouseEventHandler( GameFrame::cardEvent11), NULL, this );
// end of code generation

		//last card needs to be full size
		tmpCard = new wxStaticBitmap( this, wxID_ANY, wxBitmap( bmDeck[H11F], wxBITMAP_TYPE_ANY ), wxDefaultPosition, wxDefaultSize, 0 );
		tmpCard->Connect( wxEVT_LEFT_DCLICK, wxMouseEventHandler( GameFrame::cardEvent12 ), NULL, this );
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
void GameFrame::OnExit(wxCommandEvent& event)
{
    Close( true );
}
void GameFrame::OnAbout(wxCommandEvent& event)
{
    wxMessageBox( "This is a wxWidgets' Hello world sample",
                  "About Hello World", wxOK | wxICON_INFORMATION );
		std::vector<Card_ID> newHand = {C01,C02,C03,C03,C04,C05,C05,C10,C12,D06,H02,D02,C02F};
		setCardHand(newHand);
}
void GameFrame::OnHello(wxCommandEvent& event)
{
    wxLogMessage("Hello world from wxWidgets!");
}

//code generation from clickHelper.py
void GameFrame::cardEvent0(wxMouseEvent& event)
{
m_centerCards[(int)turn]->SetBitmap(m_cardHand[0]->GetBitmap());
SetStatusText("card 0 clicked");
}

void GameFrame::cardEvent1(wxMouseEvent& event)
{
m_centerCards[(int)turn]->SetBitmap(m_cardHand[1]->GetBitmap());
SetStatusText("card 1 clicked");
}

void GameFrame::cardEvent2(wxMouseEvent& event)
{
m_centerCards[(int)turn]->SetBitmap(m_cardHand[2]->GetBitmap());
SetStatusText("card 2 clicked");
}

void GameFrame::cardEvent3(wxMouseEvent& event)
{
m_centerCards[(int)turn]->SetBitmap(m_cardHand[3]->GetBitmap());
SetStatusText("card 3 clicked");
}

void GameFrame::cardEvent4(wxMouseEvent& event)
{
m_centerCards[(int)turn]->SetBitmap(m_cardHand[4]->GetBitmap());
SetStatusText("card 4 clicked");
}

void GameFrame::cardEvent5(wxMouseEvent& event)
{
m_centerCards[(int)turn]->SetBitmap(m_cardHand[5]->GetBitmap());
SetStatusText("card 5 clicked");
}

void GameFrame::cardEvent6(wxMouseEvent& event)
{
m_centerCards[(int)turn]->SetBitmap(m_cardHand[6]->GetBitmap());
SetStatusText("card 6 clicked");
}

void GameFrame::cardEvent7(wxMouseEvent& event)
{
m_centerCards[(int)turn]->SetBitmap(m_cardHand[7]->GetBitmap());
SetStatusText("card 7 clicked");
}

void GameFrame::cardEvent8(wxMouseEvent& event)
{
m_centerCards[(int)turn]->SetBitmap(m_cardHand[8]->GetBitmap());
SetStatusText("card 8 clicked");
}

void GameFrame::cardEvent9(wxMouseEvent& event)
{
m_centerCards[(int)turn]->SetBitmap(m_cardHand[9]->GetBitmap());
SetStatusText("card 9 clicked");
}

void GameFrame::cardEvent10(wxMouseEvent& event)
{
m_centerCards[(int)turn]->SetBitmap(m_cardHand[10]->GetBitmap());
SetStatusText("card 10 clicked");
}

void GameFrame::cardEvent11(wxMouseEvent& event)
{
m_centerCards[(int)turn]->SetBitmap(m_cardHand[11]->GetBitmap());
SetStatusText("card 11 clicked");
}

void GameFrame::cardEvent12(wxMouseEvent& event)
{
m_centerCards[(int)turn]->SetBitmap(m_cardHand[12]->GetBitmap());
SetStatusText("card 12 clicked");
}
//end of code generation
void GameFrame::setCardHand(std::vector<Card_ID> cardIds)
{
	for (int i = 0; i < 13; ++i) {
		m_cardHand[i]->SetBitmap(wxBitmap( bmDeck[cardIds[i]], wxBITMAP_TYPE_ANY ));
	}
}
