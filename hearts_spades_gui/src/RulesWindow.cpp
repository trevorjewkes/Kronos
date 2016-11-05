#include "RulesWindow.hpp"

RulesWindow::RulesWindow(wxWindow* parent, wxWindowID id, std::string rules) : wxScrolledWindow(parent, id), m_rules(rules)
{
wxBoxSizer* sizer = new wxBoxSizer(wxVERTICAL);
////add a series of widgets
//for (int w=1; w<=120; w++)
//{
//		wxButton* b = new wxButton(this, wxID_ANY, wxString::Format(wxT("Button %i"), w));
//		sizer->Add(b, 0, wxALL, 3);
//}
wxStaticText* text = new wxStaticText(this, wxID_ANY,wxString(m_rules),wxDefaultPosition,wxDefaultSize, 0);
text->Wrap(400);

sizer->Add(text, 0, wxALL, 3);
this->SetSizer(sizer);

// this part makes the scrollbars show up
this->FitInside(); // ask the sizer about the needed size
this->SetScrollRate(5, 5);
}
