#include "MainFrame.hpp"
#include "RulesWindow.hpp"
#include "LoginLayout.hpp"
#include <sstream>
#include <fstream>
#include <string>
#include <vector>

wxBEGIN_EVENT_TABLE(MainFrame, wxFrame)
    EVT_MENU(wxID_EXIT,  MainFrame::OnExit)
    EVT_MENU(wxID_ABOUT, MainFrame::OnAbout)
wxEND_EVENT_TABLE()

MainFrame::MainFrame(const wxString& title, const wxPoint& pos, const wxSize& size)
        : wxFrame(NULL, wxID_ANY, title, pos, size), m_serverDialog(NULL)
{
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
	std::vector<wxBoxSizer*> layouts;
	layouts.push_back( new LoginLayout(this, "Login window") );
	layouts.push_back( new LoginLayout(this, "Login window 2") );
	this->SetSizer(layouts[0]);
	this->Layout();
	layouts[0]->Fit(this);
	this->Center();

	this->SetSizer(layouts[1]);
	this->Layout();
	layouts[1]->Fit(this);
	this->Center();

	
	// Connect Events
	this->Connect( m_menuItemLoadHand->GetId(), wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( MainFrame::loadPlayerHand ) );
	this->Connect( m_menuItemLoadCenter->GetId(), wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( MainFrame::loadCenterCards ) );
	this->Connect( m_menuItemServerSettings->GetId(), wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( MainFrame::serverSettingsDialog ) );
	this->Connect( m_menuItemConnectToServer->GetId(), wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( MainFrame::connectToServer ) );
	this->Connect( m_menuItemSpadesRules->GetId(), wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( MainFrame::showSpadesRules ) );
	this->Connect( m_menuItemHeartsRules->GetId(), wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( MainFrame::showHeartsRules ) );
}
void MainFrame::loadPlayerHand( wxCommandEvent& event )
{
	SetStatusText("Load Player Hand");
}
void MainFrame::loadCenterCards( wxCommandEvent& event )
{
	SetStatusText("Load Center Cards");
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
