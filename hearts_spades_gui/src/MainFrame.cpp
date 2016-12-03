#include "MainFrame.hpp"
#include "RulesWindow.hpp"
#include <sstream>
#include <fstream>
#include <string>
#include <vector>

wxBEGIN_EVENT_TABLE(MainFrame, wxFrame)
    EVT_MENU(wxID_EXIT,  MainFrame::OnExit)
    EVT_MENU(wxID_ABOUT, MainFrame::OnAbout)
wxEND_EVENT_TABLE()

MainFrame::MainFrame(const wxString& title, const wxPoint& pos, const wxSize& size)
        : wxFrame(NULL, wxID_ANY, title, pos, size), m_serverDialog(NULL), m_loginDialog(NULL), m_lobbyDialog(NULL){
	CreateStatusBar();
    SetStatusText( "Welcome to Hearts and Spades!" );

	m_menubar = new wxMenuBar( 0 );

	//File menu
	m_menuFile = new wxMenu();
	m_menuFile->Append(wxID_EXIT);

	m_menubar->Append(m_menuFile, wxT("File"));

	//Test menu
	m_menuTest = new wxMenu();
	wxMenuItem* m_menuItemLoadHand;
	m_menuItemLoadHand = new wxMenuItem( m_menuTest, wxID_ANY, wxString( wxT("Load Hand") ) + wxT('\t') + wxT("CTRL-ALT-K"), wxEmptyString, wxITEM_NORMAL );
	m_menuTest->Append( m_menuItemLoadHand );
	
	wxMenuItem* m_menuItemLoadCenter;
	m_menuItemLoadCenter = new wxMenuItem( m_menuTest, wxID_ANY, wxString( wxT("Load Center") ) + wxT('\t') + wxT("CTRL-ALT-J") , wxEmptyString, wxITEM_NORMAL );
	m_menuTest->Append( m_menuItemLoadCenter );

	wxMenuItem* m_menuItemStartGame;
	m_menuItemStartGame = new wxMenuItem( m_menuTest, wxID_ANY, wxString( wxT("Start Game") ) + wxT('\t') + wxT("CTRL-ALT-N") , wxEmptyString, wxITEM_NORMAL );
	m_menuTest->Append( m_menuItemStartGame );
	
	m_menubar->Append( m_menuTest, wxT("Test") ); 
	
	//Server menu
	m_menuServer = new wxMenu();
	wxMenuItem* m_menuItemServerSettings;
	m_menuItemServerSettings = new wxMenuItem( m_menuServer, wxID_ANY, wxString( wxT("Server Settings") ) , wxEmptyString, wxITEM_NORMAL );
	m_menuServer->Append( m_menuItemServerSettings );
	
	wxMenuItem* m_menuItemConnectToServer;
	m_menuItemConnectToServer = new wxMenuItem( m_menuServer, wxID_ANY, wxString( wxT("Connect to Server") ) , wxEmptyString, wxITEM_NORMAL );
	m_menuServer->Append( m_menuItemConnectToServer );
	
	m_menubar->Append( m_menuServer, wxT("Server") ); 
	
	//Help menu
	m_menuHelp = new wxMenu();
	m_menuFile->Append(wxID_ABOUT);
	
	m_menuGameRules = new wxMenu();
	wxMenuItem* m_menuGameRulesItem = new wxMenuItem( m_menuHelp, wxID_ANY, wxT("Game Rules"), wxEmptyString, wxITEM_NORMAL, m_menuGameRules );
	wxMenuItem* m_menuItemSpadesRules;
	m_menuItemSpadesRules = new wxMenuItem( m_menuGameRules, wxID_ANY, wxString( wxT("Spades Rules") ) , wxEmptyString, wxITEM_NORMAL );
	m_menuGameRules->Append( m_menuItemSpadesRules );
	
	wxMenuItem* m_menuItemHeartsRules;
	m_menuItemHeartsRules = new wxMenuItem( m_menuGameRules, wxID_ANY, wxString( wxT("Hearts Rules") ) , wxEmptyString, wxITEM_NORMAL );
	m_menuGameRules->Append( m_menuItemHeartsRules );
	
	m_menuHelp->Append( m_menuGameRulesItem );
	
	m_menubar->Append( m_menuHelp, wxT("Help") ); 
	
	this->SetMenuBar( m_menubar );
	
	this->Centre( wxBOTH );

	//add a layout to the starting screen
  this->SetBackgroundColour(wxColour(40,150,40));

  wxBoxSizer* bs = new wxBoxSizer(wxVERTICAL);

	playerText[0] = new wxStaticText( this, wxID_ANY, wxT("Player2\nTricks: 3\nScore: 4"), wxDefaultPosition, wxDefaultSize, 0 );
	playerText[0]->Wrap( -1 );
  playerText[0]->SetForegroundColour(wxColor(255,255,255));
  wxFont font = playerText[0]->GetFont();
  font.SetPointSize(16);
  font.SetWeight(wxFONTWEIGHT_BOLD);
  playerText[0]->SetFont(font);
	bs->Add( playerText[0], 0, wxALL|wxALIGN_CENTER_HORIZONTAL, 5 );
	
	wxGridSizer* gSizer1;
	gSizer1 = new wxGridSizer( 0, 3, 0, 0 );
	
	playerText[1] = new wxStaticText( this, wxID_ANY, wxT("Player1\nTricks: 2 \nScore: 4"), wxDefaultPosition, wxDefaultSize, 0 );
	playerText[1]->Wrap( -1 );
  playerText[1]->SetForegroundColour(wxColor(255,255,255));
  font = playerText[1]->GetFont();
  font.SetPointSize(16);
  font.SetWeight(wxFONTWEIGHT_BOLD);
  playerText[1]->SetFont(font);
	gSizer1->Add( playerText[1], 0, wxALL|wxALIGN_CENTER_HORIZONTAL, 5 );
	
	wxFlexGridSizer* fgSizer1;
	fgSizer1 = new wxFlexGridSizer( 0, 4, 0, 0 );
	fgSizer1->SetFlexibleDirection( wxBOTH );
	fgSizer1->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );
	
  //create center hand cards in the vector
  wxStaticBitmap* tempBitmap;
  for (int i = 0; i < 3; ++i) {
    tempBitmap = new wxStaticBitmap( this, wxID_ANY, wxBitmap( wxT("../img/slice/blank.png"), wxBITMAP_TYPE_ANY ), wxDefaultPosition, wxDefaultSize, 0 );
    m_center_cards.push_back(tempBitmap);
  }
  tempBitmap = new wxStaticBitmap( this, wxID_ANY, wxBitmap( wxT("../img/scaled/blank.png"), wxBITMAP_TYPE_ANY ), wxDefaultPosition, wxDefaultSize, 0 );
  m_center_cards.push_back(tempBitmap);
  //add the cards to the sizer
  for (int i = 0; i < 4; ++i) {
	  fgSizer1->Add( m_center_cards[i], 0, wxTOP|wxBOTTOM, 5 );
  }

	gSizer1->Add( fgSizer1, 1, wxEXPAND, 5 );
	
	playerText[2] = new wxStaticText( this, wxID_ANY, wxT("Player3\nTricks: 2\nScore: 5"), wxDefaultPosition, wxDefaultSize, 0 );
	playerText[2]->Wrap( -1 );
  playerText[2]->SetForegroundColour(wxColor(255,255,255));
  font = playerText[2]->GetFont();
  font.SetPointSize(16);
  font.SetWeight(wxFONTWEIGHT_BOLD);
  playerText[2]->SetFont(font);
	gSizer1->Add( playerText[2], 0, wxALL|wxALIGN_CENTER_HORIZONTAL, 5 );
	
	
	bs->Add( gSizer1, 1, wxEXPAND, 5 );
	
	wxBoxSizer* bSizer3;
	bSizer3 = new wxBoxSizer( wxVERTICAL );
	
	wxFlexGridSizer* fgSizer4;
	fgSizer4 = new wxFlexGridSizer( 0, 16, 0, 0 );
	fgSizer4->SetFlexibleDirection( wxBOTH );
	fgSizer4->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );
	
	
	fgSizer4->Add( 40, 0, 1, wxEXPAND, 5 );

  //create player hand vector
  //pass in i to the id in the wxStaticBitmap
  for (int i = 0; i < 12; ++i) {
    tempBitmap = new wxStaticBitmap( this, i, wxBitmap( wxT("../img/slice/back.png"), wxBITMAP_TYPE_ANY ), wxDefaultPosition, wxDefaultSize, 0 );
    m_player_hand.push_back(tempBitmap);
  }
  //add the last card as full
  tempBitmap = new wxStaticBitmap( this, 12, wxBitmap( wxT("../img/scaled/back.png"), wxBITMAP_TYPE_ANY ), wxDefaultPosition, wxDefaultSize, 0 );
  m_player_hand.push_back(tempBitmap);
  //add the player cards to the sizer
  for (int i = 0; i < 13; ++i) {
	  fgSizer4->Add( m_player_hand[i], 0, wxTOP|wxBOTTOM, 5 );
  }
	
  //spacer
	fgSizer4->Add( 40, 0, 1, wxEXPAND, 5 );
	
	playerText[3] = new wxStaticText( this, wxID_ANY, wxT("Your Name\nTricks: 3\nScore: 8"), wxDefaultPosition, wxDefaultSize, 0 );
	playerText[3]->Wrap( -1 );
  playerText[3]->SetForegroundColour(wxColor(255,255,255));
  font = playerText[3]->GetFont();
  font.SetPointSize(16);
  font.SetWeight(wxFONTWEIGHT_BOLD);
  playerText[3]->SetFont(font);
	fgSizer4->Add( playerText[3], 0, wxALL|wxALIGN_CENTER_HORIZONTAL, 5 );
	
	
	bSizer3->Add( fgSizer4, 1, wxEXPAND, 5 );
	
	bs->Add( bSizer3, 1, wxEXPAND, 5 );
	
  // Connect events for player hand
  for (int i = 0; i < 13; ++i) {
    m_player_hand[i]->Connect( wxEVT_LEFT_UP, wxMouseEventHandler( MainFrame::cardClicked ), NULL, this );
  }

	this->SetSizer(bs);
	this->Layout();
	this->Center();

	// Connect Events
	this->Connect( m_menuItemLoadHand->GetId(), wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( MainFrame::loadPlayerHand ) );
	this->Connect( m_menuItemLoadCenter->GetId(), wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( MainFrame::loadCenterCards ) );
	this->Connect( m_menuItemServerSettings->GetId(), wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( MainFrame::serverSettingsDialog ) );
	this->Connect( m_menuItemConnectToServer->GetId(), wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( MainFrame::connectToServer ) );
	this->Connect( m_menuItemSpadesRules->GetId(), wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( MainFrame::showSpadesRules ) );
	this->Connect( m_menuItemHeartsRules->GetId(), wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( MainFrame::showHeartsRules ) );
  this->Connect( m_menuItemStartGame->GetId(), wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( MainFrame::startGame ) );

  this->Show( true );
  this->m_lobbyDialog.Show( true );
  this->m_loginDialog.Show( true );
  this->m_serverDialog.Show( true  );
  for (int i = 0; i < 4; i++)
  {
	  
	  if (i == 0)
	  {
		  Player tmp(i, "PLAYER");
		  players.push_back(tmp);
	  }
	  else
	  {
		  Player tmp(i*-1, "AI");
		  if (i == 1) tmp.setName("Sally");
		  else if (i == 2) tmp.setName("Bob");
		  else if (i == 3) tmp.setName("Kenneth");
		  players.push_back(tmp);
	  }
  }

  //this->m_serverDialog.Show( true  );
}
void MainFrame::loadPlayerHand( wxCommandEvent& event )
{
	SetStatusText("Load Player Hand");
	m_loginDialog.Show();
}
void MainFrame::loadCenterCards( wxCommandEvent& event )
{
	SetStatusText("Load Center Cards");
	m_lobbyDialog.Show();
}
void MainFrame::serverSettingsDialog( wxCommandEvent& event )
{
	m_serverDialog.Show();
}
void MainFrame::connectToServer( wxCommandEvent& event )
{
	std::ostringstream oss;
	oss << "IP: " << m_serverDialog.getIP() << "\t PORT: " << m_serverDialog.getPort();
	std::cout << oss.str() << std::endl;
	std::cout.flush();
	SetStatusText(oss.str());
}
std::string MainFrame::getHeartsRules()
{
	std::ifstream fin("../rules/HeartsRules.txt");	
	std::string content( (std::istreambuf_iterator<char>(fin) ), (std::istreambuf_iterator<char>() ) );
	fin.close();
	return content;
}
void MainFrame::showHeartsRules( wxCommandEvent& event )
{
	static std::string rules = getHeartsRules();
	//std::cout << rules << std::endl;
	//std::cout.flush();

	wxBoxSizer* sizer = new wxBoxSizer(wxHORIZONTAL);
	wxFrame* frame = new wxFrame((wxFrame *)NULL, -1,  wxT("Hearts Rules"), wxPoint(50,50), wxSize(450,450));
	RulesWindow* window = new RulesWindow(frame, wxID_ANY, rules);
	sizer->Add(window, 1, wxEXPAND);
	frame->SetSizer(sizer);

	frame->Show();
}
std::string MainFrame::getSpadesRules()
{
	std::ifstream fin("../rules/SpadesRules.txt");	
	std::string content( (std::istreambuf_iterator<char>(fin) ), (std::istreambuf_iterator<char>() ) );
	fin.close();
	return content;
}
void MainFrame::showSpadesRules( wxCommandEvent& event )
{
	static std::string rules = getSpadesRules();
	//std::cout << rules << std::endl;
	//std::cout.flush();

	wxBoxSizer* sizer = new wxBoxSizer(wxHORIZONTAL);
	wxFrame* frame = new wxFrame((wxFrame *)NULL, -1,  wxT("Spades Rules"), wxPoint(50,50), wxSize(450,450));
	RulesWindow* window = new RulesWindow(frame, wxID_ANY, rules);
	sizer->Add(window, 1, wxEXPAND);
	frame->SetSizer(sizer);

	frame->Show();
}
void MainFrame::startGame( wxCommandEvent& event ) {
	int res = wxMessageBox("Start Game?", "Confirm", wxYES_NO, this);
	if (res == wxYES) {
    std::cout << "Start game!\n";
    SetStatusText("You have started the Game!");
	gameHearts = new HeartsGame(players);
	Status state = gameHearts->play_Hearts();
	//UPDATE STATE HERE
	m_state = PASSING;
	SetStatusText("Select Cards to Pass");
  }

}
void MainFrame::OnExit(wxCommandEvent& event)
{
	int res = wxMessageBox("Exit program?", "Confirm", wxYES_NO, this);
	if (res == wxYES) 
		Close( true );
}
void MainFrame::OnAbout(wxCommandEvent& event)
{
    wxMessageBox( "This is a multiplayer Hearts and Spades",
                  "About Hearts and Spades", wxOK | wxICON_INFORMATION );
}
