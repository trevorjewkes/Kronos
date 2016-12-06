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
	wxMenuItem* m_menuItemLogin;
	m_menuItemLogin = new wxMenuItem( m_menuTest, wxID_ANY, wxString( wxT("Login as new user") ) + wxT('\t') + wxT("CTRL-ALT-K"), wxEmptyString, wxITEM_NORMAL );
	m_menuTest->Append( m_menuItemLogin );
	
	wxMenuItem* m_menuItemLobby;
	m_menuItemLobby = new wxMenuItem( m_menuTest, wxID_ANY, wxString( wxT("Game Lobby") ) + wxT('\t') + wxT("CTRL-ALT-J") , wxEmptyString, wxITEM_NORMAL );
	m_menuTest->Append( m_menuItemLobby );

  wxMenuItem* m_menuEndGame;
	m_menuEndGame = new wxMenuItem( m_menuTest, wxID_ANY, wxString( wxT("End Game") ) + wxT('\t') + wxT("CTRL-ALT-E") , wxEmptyString, wxITEM_NORMAL );
	m_menuTest->Append( m_menuEndGame );

	m_menubar->Append( m_menuTest, wxT("Util") ); 
	
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

	playerText[2] = new wxStaticText( this, wxID_ANY, wxT("Player2\nTricks: 3\nScore: 4"), wxDefaultPosition, wxDefaultSize, 0 );
	playerText[2]->Wrap( -1 );
  playerText[2]->SetForegroundColour(wxColor(255,255,255));
  wxFont font = playerText[2]->GetFont();
  font.SetPointSize(16);
  font.SetWeight(wxFONTWEIGHT_BOLD);
  playerText[2]->SetFont(font);
	bs->Add( playerText[2], 0, wxALL|wxALIGN_CENTER_HORIZONTAL, 5 );
	
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
    tempBitmap = new wxStaticBitmap( this, wxID_ANY, wxBitmap( wxT("../img/slice/back.png"), wxBITMAP_TYPE_ANY ), wxDefaultPosition, wxDefaultSize, 0 );
    m_center_cards.push_back(tempBitmap);
  }
  tempBitmap = new wxStaticBitmap( this, wxID_ANY, wxBitmap( wxT("../img/scaled/back.png"), wxBITMAP_TYPE_ANY ), wxDefaultPosition, wxDefaultSize, 0 );
  m_center_cards.push_back(tempBitmap);
  //add the cards to the sizer
  for (int i = 0; i < 4; ++i) {
	  fgSizer1->Add( m_center_cards[i], 0, wxTOP|wxBOTTOM, 5 );
  }

	gSizer1->Add( fgSizer1, 1, wxEXPAND, 5 );
	
	playerText[3] = new wxStaticText( this, wxID_ANY, wxT("Player3\nTricks: 2\nScore: 5"), wxDefaultPosition, wxDefaultSize, 0 );
	playerText[3]->Wrap( -1 );
  playerText[3]->SetForegroundColour(wxColor(255,255,255));
  font = playerText[3]->GetFont();
  font.SetPointSize(16);
  font.SetWeight(wxFONTWEIGHT_BOLD);
  playerText[3]->SetFont(font);
	gSizer1->Add( playerText[3], 0, wxALL|wxALIGN_CENTER_HORIZONTAL, 5 );
	
	
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
	
	playerText[0] = new wxStaticText( this, wxID_ANY, wxT("Your Name\nTricks: 3\nScore: 8"), wxDefaultPosition, wxDefaultSize, 0 );
	playerText[0]->Wrap( -1 );
  playerText[0]->SetForegroundColour(wxColor(255,255,255));
  font = playerText[0]->GetFont();
  font.SetPointSize(16);
  font.SetWeight(wxFONTWEIGHT_BOLD);
  playerText[0]->SetFont(font);
	fgSizer4->Add( playerText[0], 0, wxALL|wxALIGN_CENTER_HORIZONTAL, 5 );
	
	
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
	this->Connect( m_menuEndGame->GetId(), wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( MainFrame::showEndGamePopup ) );
	this->Connect( m_menuItemLogin->GetId(), wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( MainFrame::menuLogin ) );
	this->Connect( m_menuItemLobby->GetId(), wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( MainFrame::menuLobby ) );
	this->Connect( m_menuItemServerSettings->GetId(), wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( MainFrame::serverSettingsDialog ) );
	this->Connect( m_menuItemConnectToServer->GetId(), wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( MainFrame::connectToServer ) );
	this->Connect( m_menuItemSpadesRules->GetId(), wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( MainFrame::showSpadesRules ) );
	this->Connect( m_menuItemHeartsRules->GetId(), wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( MainFrame::showHeartsRules ) );
	m_loginDialog.loginBtn->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( MainFrame::OnLogin ), NULL, this );
  //Connect lobby events
	m_lobbyDialog.m_joinPrivateHeartsBtn->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( MainFrame::joinPrivateHeartsGame ), NULL, this );
	m_lobbyDialog.m_joinPrivateSpadesBtn->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( MainFrame::joinPrivateSpadesGame ), NULL, this );
	m_lobbyDialog.m_joinPublicHeartsBtn->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( MainFrame::joinPublicHeartsGame ), NULL, this );
	m_lobbyDialog.m_joinPublicSpadesBtn->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( MainFrame::joinPublicSpadesGame ), NULL, this );

 
  this->Show( true );
  //this->m_lobbyDialog.Show( true );
  this->m_loginDialog.Show( true );
  //this->m_serverDialog.Show( true  );
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
}

void MainFrame::cardClicked(wxMouseEvent &event) {
  if (m_state == PASSING) {
    if (m_gameState == H) {
      if (gameHearts->pass(event.GetId())) {
        m_state = PLAYING;
        SetStatusText("Play a card");
        updateScreen(gameHearts->updateStatus());
        gameHearts->play(true);
      }
      // UPDATESTATUS
      updateScreen(gameHearts->updateStatus());
    } else {
      gameSpades->doBids(0); // getbidhere
      m_state = PLAYING;
      SetStatusText("Play a card");
      updateScreen(gameSpades->updateStatus());
      gameSpades->play(true);
    }
  } else if (m_state == PLAYING) {
    if (m_gameState == H) {
      if (gameHearts->playCard(event.GetId())) {
        if(gameHearts->play(false))
			gameHearts->play(false);
	  }
      updateScreen(gameHearts->updateStatus());
    } else {
      if (gameSpades->playCard(event.GetId())) {
        gameSpades->play(false);
      }
      updateScreen(gameHearts->updateStatus());
    }
  }
}
void MainFrame::joinPublicHeartsGame(wxCommandEvent& event) {
	int res = wxMessageBox("Join public Hearts game?", "Confirm", wxYES_NO, this);
	if (res == wxYES)
	{
		m_lobbyDialog.Show(false);
    startHeartsGame();
	}
}
void MainFrame::joinPublicSpadesGame(wxCommandEvent& event) {
	int res = wxMessageBox("Join public Spades game?", "Confirm", wxYES_NO, this);
	if (res == wxYES)
	{
		m_lobbyDialog.Show(false);
    //Start spades game
		players[0].setName(m_loginDialog.getUsername());
    gameSpades = new SpadesGame(players);
    Status state = gameSpades->play_Spades();
    m_state = PLAYING;
    SetStatusText("Select Bid");
    updateScreen(gameSpades->updateStatus());
	}
}
void MainFrame::joinPrivateHeartsGame(wxCommandEvent& event) {
  wxTextEntryDialog input(this, "Enter name of private game:", "Join Private Hearts Game");
  m_lobbyDialog.Show(false);
  if (input.ShowModal() == wxID_OK) {
    if ((std::string)input.GetValue() == "private") {
      m_lobbyDialog.Show(false);
      startHeartsGame();
    } else {
      wxMessageBox("There is not private game with that name.", "Error", wxICON_ERROR);
      m_lobbyDialog.Show(true);
    }
  } else {
      m_lobbyDialog.Show(true);
  }
}
void MainFrame::joinPrivateSpadesGame(wxCommandEvent& event) {
  wxTextEntryDialog input(this, "Enter name of private game:", "Join Private Spades Game");
  if (input.ShowModal() == wxID_OK) {
    if ((std::string)input.GetValue() == "private") {
      m_lobbyDialog.Show(false);
	  players[0].setName(m_loginDialog.getUsername());
      //set state to private game
      //START Spades Game
      gameSpades = new SpadesGame(players);
      Status state = gameSpades->play_Spades();
      m_state = PLAYING;
      SetStatusText("Select Bid");
      updateScreen(gameSpades->updateStatus());
    } else {
      wxMessageBox("There is not private game with that name."); 
    }
  }
}

void MainFrame::updateScreen2() {
  Status status = gameHearts->updateStatus();
  if (status.isGameOver) {
    // do something here;
    return;
  }
  updatePlayerHand(status.hand);
  updateCenterCards(status.center);
  updateStats(status.scores, status.tricks, status.bids);
  if (status.passing) {
    m_state = PASSING;
    SetStatusText("Pass cards");
  }
  Update();
}

void MainFrame::updateScreen(Status status) {
	if (status.isGameOver)
	{
		//do something here;
    showEndGamePopup();
		return;
	}
  updatePlayerHand(status.hand);
  updateCenterCards(status.center);

  updateStats(status.scores, status.tricks, status.bids);
  if (status.passing)
  {
	  m_state = PASSING;
	  SetStatusText("Pass cards");
  }
}
void MainFrame::updatePlayerHand(std::vector<Card> hand) {
    int handSize = (int)hand.size();
    std::string suit;
    int value;
    
    for (int i = 0; i < (handSize -1) ; i++) {
      suit = getSuitString(hand[i].getSuit());
      value = (int)hand[i].getValue();
      m_player_hand[i]->SetBitmap(wxBitmap( wxT("../img/slice/" + suit + "/" + std::to_string(value) + ".png"), wxBITMAP_TYPE_ANY ));
      m_player_hand[i]->Show();
    }
    if (handSize > 0) {
      suit = getSuitString(hand[handSize-1].getSuit());
      value = (int)hand[handSize-1].getValue();
      m_player_hand[handSize-1]->SetBitmap(wxBitmap( wxT("../img/scaled/" + suit + "/" + std::to_string(value) + ".png"), wxBITMAP_TYPE_ANY ));
      m_player_hand[handSize-1]->Show();
    }

    for (int i = handSize; i < 13; ++i) {
      m_player_hand[i]->Hide();
    }
}
void MainFrame::updateCenterCards(std::vector<Card> cards) {
  int centerSize = (int)cards.size();
  std::string suit;
  int value;

  for (int i = 0; i < (centerSize - 1); i++) {
    suit = getSuitString(cards[i].getSuit());
    value = (int)cards[i].getValue();
    m_center_cards[i]->SetBitmap(wxBitmap( wxT("../img/slice/" + suit + "/" + std::to_string(value) + ".png"), wxBITMAP_TYPE_ANY ));
    m_center_cards[i]->Show();
  }
  if (centerSize > 0) {
    suit = getSuitString(cards[centerSize-1].getSuit());
    value = (int)cards[centerSize-1].getValue();
    m_center_cards[centerSize-1]->SetBitmap(wxBitmap( wxT("../img/scaled/" + suit + "/" + std::to_string(value) + ".png"), wxBITMAP_TYPE_ANY ));
    m_center_cards[centerSize-1]->Show();
  }

  for (int i = centerSize; i < 4; ++i) {
    m_center_cards[i]->Hide();
  }
}
void MainFrame::updateStats(std::vector<int> scores, std::vector<int> tricks, std::vector<int> bids) {
  for (int i = 0; i < 4; ++i) {
    std::string scoreStuff = players[i].getName() + "\n" + "Tricks: " +
                             std::to_string(tricks[i]) + "\n" + "Score: " +
                             std::to_string(scores[i]);
    if (bids.size() == 4) {
      scoreStuff += "\nBids: " + std::to_string(bids[i]);
	}
	playerText[i]->SetLabel(scoreStuff);
  }
}
void MainFrame::menuLogin( wxCommandEvent& event )
{
	SetStatusText("Login");
	m_loginDialog.Show();
}
void MainFrame::menuLobby( wxCommandEvent& event )
{
	SetStatusText("Lobby");
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

	wxBoxSizer* sizer = new wxBoxSizer(wxHORIZONTAL);
	wxFrame* frame = new wxFrame((wxFrame *)NULL, -1,  wxT("Spades Rules"), wxPoint(50,50), wxSize(450,450));
	RulesWindow* window = new RulesWindow(frame, wxID_ANY, rules);
	sizer->Add(window, 1, wxEXPAND);
	frame->SetSizer(sizer);

	frame->Show();
}

int MainFrame::getBid() {
  wxTextEntryDialog* input = new wxTextEntryDialog(this, "Enter a bid (0 - 13):", "Place Bid"); 
  input->ShowModal();
  int num = std::atoi(input->GetValue().ToAscii());
  input->Destroy();
  if (num < 0 || num > 13) {
    num = -1;
  }
  return num;
}
void MainFrame::showEndGamePopup() {
  std::string msg = "-- End of Game --\n\n";
	for (int i = 0; i < players.size(); i++)
	{
    msg += "\t" + players[i].getName() + " score: " 
        + std::to_string(players[i].getRoundScore()) +
        " (" + std::to_string(players[i].getTotalScore()) + ")\n"; 
	}
  int res = wxMessageBox(msg, "Game Over | Play Again?", wxYES_NO);
  if (res == wxYES) {
   //start the game over 
   startHeartsGame();
  } else {
   m_lobbyDialog.Show(); 
  } 
}
void MainFrame::startHeartsGame() {
  //START Hearts game
  m_gameState = H;
  players[0].setName(m_loginDialog.getUsername());
  if (gameHearts != NULL) delete gameHearts;
  gameHearts = new HeartsGame(players);
  Status state = gameHearts->play_Hearts();
  //UPDATE STATE HERE
  m_state = PASSING;
  SetStatusText("Select Cards to Pass");
  updateScreen(gameHearts->updateStatus());
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
