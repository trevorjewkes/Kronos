// wxWidgets "Hello world" Program
// For compilers that support precompilation, includes "wx/wx.h".
#include <wx/wxprec.h>
#ifndef WX_PRECOMP
    #include <wx/wx.h>
#endif
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
		wxStaticBitmap* m_cardBM1;
		wxStaticBitmap* m_cardBM2;
		wxStaticBitmap* m_cardBM3;
		wxStaticBitmap* m_cardBM4;
		wxStaticText* text1;
    void OnHello(wxCommandEvent& event);
    void OnExit(wxCommandEvent& event);
    void OnAbout(wxCommandEvent& event);
		void chooseCard(wxMouseEvent& event);
		void chooseCard2(wxMouseEvent& event);
		void chooseCard3(wxMouseEvent& event);
		void chooseCard4(wxMouseEvent& event);
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
    MyFrame *frame = new MyFrame( "Card Test", wxPoint(50, 50), wxSize(450, 340) );
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

		wxBoxSizer* bSizer;
		bSizer = new wxBoxSizer( wxVERTICAL );
		text1 = new wxStaticText( this, wxID_ANY, wxT("Double click to choose a card"), wxDefaultPosition, wxDefaultSize, 0 );
		bSizer->Add(text1, 0, wxALL|wxALIGN_CENTER_HORIZONTAL,5);

		wxFlexGridSizer* fgSizer1;
		fgSizer1 = new wxFlexGridSizer( 0, 4, 0, 0 );
		fgSizer1->SetFlexibleDirection( wxBOTH );
		fgSizer1->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );

		m_cardBM1 = new wxStaticBitmap( this, wxID_ANY, wxBitmap( wxT("../img/Cropped/s09.png"), wxBITMAP_TYPE_ANY ), wxDefaultPosition, wxDefaultSize, 0 );
		fgSizer1->Add( m_cardBM1, 0, wxTOP|wxBOTTOM|wxLEFT, 5 );

		m_cardBM2 = new wxStaticBitmap( this, wxID_ANY, wxBitmap( wxT("../img/Cropped/c01.png"), wxBITMAP_TYPE_ANY ), wxDefaultPosition, wxDefaultSize, 0 );
		fgSizer1->Add( m_cardBM2, 0, wxTOP|wxBOTTOM, 5 );

		m_cardBM3 = new wxStaticBitmap( this, wxID_ANY, wxBitmap( wxT("../img/Cropped/h11.png"), wxBITMAP_TYPE_ANY ), wxDefaultPosition, wxDefaultSize, 0 );
		fgSizer1->Add( m_cardBM3, 0, wxTOP|wxBOTTOM, 5 );

		m_cardBM4 = new wxStaticBitmap( this, wxID_ANY, wxBitmap( wxT("../img/Scaled/d02.png"), wxBITMAP_TYPE_ANY ), wxDefaultPosition, wxDefaultSize, 0 );
		fgSizer1->Add( m_cardBM4, 0, wxTOP|wxBOTTOM, 5 );

		bSizer->Add(fgSizer1, 1, wxEXPAND, 5);

		this->SetSizer(bSizer);
		this->Layout();
		this->Center(wxBOTH);

		m_cardBM1->Connect( wxEVT_LEFT_DCLICK, wxMouseEventHandler( MyFrame::chooseCard ), NULL, this );
		m_cardBM2->Connect( wxEVT_LEFT_DCLICK, wxMouseEventHandler( MyFrame::chooseCard2 ), NULL, this );
		m_cardBM3->Connect( wxEVT_LEFT_DCLICK, wxMouseEventHandler( MyFrame::chooseCard3 ), NULL, this );
		m_cardBM4->Connect( wxEVT_LEFT_DCLICK, wxMouseEventHandler( MyFrame::chooseCard4 ), NULL, this );
}
void MyFrame::OnExit(wxCommandEvent& event)
{
    Close( true );
}
void MyFrame::OnAbout(wxCommandEvent& event)
{
    wxMessageBox( "This is a wxWidgets' Hello world sample",
                  "About Hello World", wxOK | wxICON_INFORMATION );
}
void MyFrame::OnHello(wxCommandEvent& event)
{
    wxLogMessage("Hello world from wxWidgets!");
}
void MyFrame::chooseCard(wxMouseEvent& event) {
    //wxMessageBox( "You clicked a card","mouse click event", wxOK | wxICON_INFORMATION );
		m_cardBM1->SetBitmap(wxBitmap( wxT("../img/Cropped/s11.png"), wxBITMAP_TYPE_ANY ));
		m_cardBM2->SetBitmap(wxBitmap( wxT("../img/Cropped/s12.png"), wxBITMAP_TYPE_ANY ));
		m_cardBM3->SetBitmap(wxBitmap( wxT("../img/Cropped/s13.png"), wxBITMAP_TYPE_ANY ));
		m_cardBM4->SetBitmap(wxBitmap( wxT("../img/Scaled/s01.png"), wxBITMAP_TYPE_ANY ));
		text1->SetLabel(wxT("Player1\nTricks: 9\nScore: 5"));
		this->Layout();
		SetStatusText("Spades");
}
void MyFrame::chooseCard2(wxMouseEvent& event) {
    //wxMessageBox( "You clicked a card","mouse click event", wxOK | wxICON_INFORMATION );
		m_cardBM1->SetBitmap(wxBitmap( wxT("../img/Cropped/h01.png"), wxBITMAP_TYPE_ANY ));
		m_cardBM2->SetBitmap(wxBitmap( wxT("../img/Cropped/h12.png"), wxBITMAP_TYPE_ANY ));
		m_cardBM3->SetBitmap(wxBitmap( wxT("../img/Cropped/h13.png"), wxBITMAP_TYPE_ANY ));
		m_cardBM4->SetBitmap(wxBitmap( wxT("../img/Scaled/h05.png"), wxBITMAP_TYPE_ANY ));
		text1->SetLabel(wxT("Player1\nTricks: 2\nScore: 5"));
		this->Layout();
		SetStatusText("Hearts");
}
void MyFrame::chooseCard3(wxMouseEvent& event) {
    //wxMessageBox( "You clicked a card","mouse click event", wxOK | wxICON_INFORMATION );
		m_cardBM1->SetBitmap(wxBitmap( wxT("../img/Cropped/d01.png"), wxBITMAP_TYPE_ANY ));
		m_cardBM2->SetBitmap(wxBitmap( wxT("../img/Cropped/d12.png"), wxBITMAP_TYPE_ANY ));
		m_cardBM3->SetBitmap(wxBitmap( wxT("../img/Cropped/d13.png"), wxBITMAP_TYPE_ANY ));
		m_cardBM4->SetBitmap(wxBitmap( wxT("../img/Scaled/d05.png"), wxBITMAP_TYPE_ANY ));
		text1->SetLabel(wxT("Player1\nTricks: 56\nScore: 43"));
		this->Layout();
		SetStatusText("Diamonds");
}
void MyFrame::chooseCard4(wxMouseEvent& event) {
    //wxMessageBox( "You clicked a card","mouse click event", wxOK | wxICON_INFORMATION );
		m_cardBM1->SetBitmap(wxBitmap( wxT("../img/Cropped/c01.png"), wxBITMAP_TYPE_ANY ));
		m_cardBM2->SetBitmap(wxBitmap( wxT("../img/Cropped/c12.png"), wxBITMAP_TYPE_ANY ));
		m_cardBM3->SetBitmap(wxBitmap( wxT("../img/Cropped/c13.png"), wxBITMAP_TYPE_ANY ));
		m_cardBM4->SetBitmap(wxBitmap( wxT("../img/Scaled/c05.png"), wxBITMAP_TYPE_ANY ));
		text1->SetLabel(wxT("Player1\nTricks: 10\nScore: 34"));
		this->Layout();
		SetStatusText("Clubs");
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

