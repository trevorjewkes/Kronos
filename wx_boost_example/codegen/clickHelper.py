#for i in range(13):
#	print "void MyFrame::cardEvent" + str(i) + "(wxMouseEvent& event)"
#	print "{"
#	print "m_centerCards[(int)turn]->SetBitmap(m_cardHand[" + str(i) + "]->GetBitmap());"
#	print "SetStatusText(\"card " + str(i) + " clicked\");"
#	print "}"
#	print

#for i in range(13):
#	print "void cardEvent" + str(i) + "(wxMouseEvent& event);"

for i in range(1,13):
	print "tmpCard = new wxStaticBitmap( this,"
	print "wxID_ANY,"
	if i<10:
		print "wxBitmap( bmDeck[D0" + str(i) + "],"
	else:
		print "wxBitmap( bmDeck[D" + str(i) + "],"
	print "wxBITMAP_TYPE_ANY ),"
	print "wxDefaultPosition,"
	print "wxDefaultSize,"
	print "0 );"
	print "m_cardHand.push_back(tmpCard);"
	print "fgSizer2->Add(tmpCard, 0, wxTOP|wxBOTTOM, 5);"
	print "tmpCard->Connect( wxEVT_LEFT_DCLICK, wxMouseEventHandler( MyFrame::cardEvent"+str(i-1)+"), NULL, this );"
	
