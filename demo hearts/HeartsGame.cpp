#include "HeartsGame.h"



HeartsGame::HeartsGame()
{
	m_resolver = new boost::asio::ip::tcp::resolver(io_service);
	auto endpoint_iterator = m_resolver->resolve({ "129.123.141.248", "8080" });
	chat = new chat_client(io_service, endpoint_iterator);
	t = new std::thread([this]() { io_service.run(); });
}

HeartsGame::~HeartsGame()
{
	chat->close();
}

std::string HeartsGame::suite(int i)  //converts enum ints to string of suit
{
	switch (i) {
	case 0: return "HEARTS";
	case 1: return "SPADES";
	case 2: return "CLUBS";
	case 3: return "DIAMONDS";
	default:return "error";
	}
}


std::vector<Card> HeartsGame::initializeDeck() //creates deck of cards taken from Card.cpp

{
	std::vector<Card> deck;
	deck.reserve(52);
	std::vector<Suit> suits = { HEARTS, SPADES, CLUBS, DIAMONDS };
	for (auto && suit : suits) {
		for (int i = 1; i<14; i++) {
			deck.push_back(Card(suit, i));
		}
	}
	return deck;
}

std::string HeartsGame::makename(int n)  //converts Player + int into Player names
{
	switch (n) {
	case 0: return "Player 1";
		break;
	case 1: return "Player 2";
		break;
	case 2: return "Player 3";
		break;
	case 3: return "Player 4";
		break;
	default: return "error";
	}


}

std::vector<Player> HeartsGame::creatPlayers(int p)  //Creats a vector of Players to play the game.
{
	std::vector<Player> players;
	players.reserve(p);

	for (auto i = 0; i < p; ++i)
	{
		players.push_back(Player(makename(i)));
		players[i].setScore(0);
	}

	return players;

}

std::string HeartsGame::value(int i)
{
	switch (i) {
	case 1: return "Ace"; break;
	case 2: return "2"; break;
	case 3: return "3"; break;
	case 4: return "4"; break;
	case 5: return "5"; break;
	case 6: return "6"; break;
	case 7: return "7"; break;
	case 8: return "8"; break;
	case 9: return "9"; break;
	case 10: return "10"; break;
	case 11: return "Jack"; break;
	case 12: return "Queen"; break;
	case 13: return "King"; break;
	default: return "error";
	}

}

void HeartsGame::displayCards(std::vector<Card>& hand)//displays the deck for screen purposes.
{
	//std::sort(hand.begin(), hand.end());  sorts the hand but causes problems when it sorts the center pile
	for (size_t i = 0; i<hand.size(); ++i)
	{
		std::cout << (i + 1) << ". The " << value(hand[i].getValue()) << " of " << suite(hand[i].getSuit()) << " " << std::endl;
	}

}

void HeartsGame::dealCards(std::vector<Player>& players, std::vector<Card>& Deck)
{

	std::random_device rd;
	std::mt19937 generator(rd());
	std::shuffle(Deck.begin(), Deck.end(), generator);

	for (size_t i = 0; i < players.size(); ++i)
	{
		std::vector<Card> hand;
		for (auto j = 0; j < 13; ++j)
		{
			hand.push_back(Deck[(j)+(13 * i)]);
		}
		players[i].setHand(hand);
		players[i].sortHand();
		players[i].setroundScore(0);
	}
}

int HeartsGame::findTwoOfClubs(std::vector<Player>& p)  //looks through each hand to find the 2 of clubs
{
	for (size_t i = 0; i < p.size(); ++i)
	{
		std::vector<Card> temp = p[i].getHand();
		for (auto j = 0; j < 13; ++j)
		{
			if (temp[j].getSuit() == Suit::CLUBS && temp[j].getValue() == 2)
			{
				std::cout << p[i].getip() << " has the 2 of Clubs!" << std::endl;
				return i;
			}
		}
	}
	return -1;
}

Card HeartsGame::getCardsToPass(std::vector<Card>& h, std::string p)  //gets and stores cards for passing
{
	std::cout << p << " what card would you like to pass?" << std::endl;

	int card;
	displayCards(h);
	std::cin >> card;
	std::swap(h[h.size() - 1], h[card - 1]);
	Card pass = h[h.size() - 1];
	h.pop_back();
	std::cout << "You passed the " << pass.getValue() << " of " << suite(pass.getSuit()) << std::endl;
	return pass;
}

int HeartsGame::fixPass(int r, int p, int c)
{
	if (r == 1) //pass to the Left
	{
		switch (p)
		{
		case 0:  return c + 9;
			break;
		case 1: return c;
			break;
		case 2: return c + 3;
			break;
		case 3: return c + 6;
			break;
		default: return -1;
		}
	}

	if (r == 2) // pass to the Right
	{
		switch (p)
		{
		case 0:  return c + 3;
			break;
		case 1: return c + 6;
			break;
		case 2: return c + 9;
			break;
		case 3: return c;
			break;
		default: return -1;
		}
	}

	if (r == 3) // pass across the Table
	{
		switch (p)
		{
		case 0:  return c + 6;
			break;
		case 1: return c + 9;
			break;
		case 2: return c;
			break;
		case 3: return c + 3;
			break;
		default: return -1;
		}
	}
	return -1;
}

void HeartsGame::assignPassedCards(std::vector<Player>& p, std::vector<Card>& h, int r)  //takes the passed cards and redistributes based on round
{
	for (size_t i = 0; i < p.size(); ++i)
	{
		std::vector<Card> temp = p[i].getHand();
		for (auto j = 0; j < 3; ++j)
		{
			temp.push_back(h[fixPass(r, i, j)]);
		}
		p[i].setHand(temp);
		p[i].sortHand();
		//displayCards(p[i].getHand());  displays everyones hand to make sure no doubles can be removed
	}
}


int HeartsGame::passCards(std::vector<Player>& p, int round)  //function for passing cards at beginging of round
{
	int modr = ((round + 1) % 4);
	if (modr == 0)
	{
		return findTwoOfClubs(p);
	}
	else {
		std::vector<Card> pass;
		for (size_t i = 0; i < p.size(); ++i)
		{
			std::vector<Card> temp = p[i].getHand();
			pass.push_back(getCardsToPass(temp, p[i].getip()));
			pass.push_back(getCardsToPass(temp, p[i].getip()));
			pass.push_back(getCardsToPass(temp, p[i].getip()));
			p[i].setHand(temp);
		}

		assignPassedCards(p, pass, modr);
	}
	return findTwoOfClubs(p);
}

int HeartsGame::scoretrick(std::vector<Card>& center, std::vector<Player>& players, int& turn)
{
	int winner = turn;
	Suit lead = center[0].getSuit();
	int high = center[0].getValue();
	int score = 0;
	for (size_t i = 0; i < center.size(); ++i)
	{
		if (center[i].getSuit() == HEARTS) { ++score; }
		if ((center[i].getSuit() == lead) && (center[i].getValue() > high)) { winner = (turn + i) % 4;  high = center[i].getValue(); }
		if ((center[i].getSuit() == lead) && (center[i].getValue() == 1)) { winner = (turn + i) % 4; high = 14; }  //aces are high but its not a value in our cards
		if ((center[i].getSuit() == SPADES) && (center[i].getValue() == 12)) { score = score + 13; high = center[i].getValue(); }
	}

	players[winner].setroundScore((players[winner].getroundScore()) + score);
	return winner;
}

void HeartsGame::displayroundScores(std::vector<Player> p)
{
	std::cout << "The Scores after this trick are " << std::endl;
	for (size_t i = 0; i < p.size(); ++i)
	{
		std::cout << p[i].getip() << " has a score of " << p[i].getroundScore() << "." << std::endl;
	}


}

void HeartsGame::displayScores(std::vector<Player> p)
{
	std::cout << "The Scores after this Round are " << std::endl;
	for (size_t i = 0; i < p.size(); ++i)
	{
		std::cout << p[i].getip() << " has a score of " << p[i].getScore() << "." << std::endl;
	}


}

bool HeartsGame::allhearts(std::vector<Card> h)  //checks to see if a players hand is all hearts.
{

	for (size_t i = 0; i < h.size(); ++i)
	{
		if (h[i].getSuit() != HEARTS)
		{
			return false;
		}
	}
	return true;
}

bool HeartsGame::noLeadSuit(Suit s, std::vector<Card> h)  //compares hand against the lead suit
{
	for (size_t i = 0; i < h.size(); ++i)
	{
		if (h[i].getSuit() == s)
		{
			return false;
		}
	}
	return true;
}

bool HeartsGame::validateMove(Player& p, bool& broken, std::vector<Card> Center, Card move, int t, int i)
{
	Suit lead;
	if (i != 0) { lead = Center[0].getSuit(); }//sets the lead suit
	if (t == 1 && move.getSuit() == HEARTS) { return false; }//cannot play hearts in first round
	if ((t == 1 && move.getSuit() == SPADES) && (move.getValue() == 12)) { return false; }//cannot play queen of spades in first round
	if ((t == 1 && i == 0) && (move.getSuit() != CLUBS && move.getValue() != 2)) { return false; }//must play 2 of clubs at the first of each round
	if ((i == 0 && move.getSuit() == CLUBS) && (move.getValue() == 2)) { return true; }
	if (i == 0 && allhearts(p.getHand())) { broken = true; return true; }  //if player only has hearts hearts are broken and move is valid
	if (i == 0 && broken) { return true; }  //can play any card on first move once hearts are broken
	if (i != 0 && move.getSuit() == lead) { return true; }//if you play the same suit as lead it is valid
	if (i == 0 && move.getSuit() != HEARTS) { return true; } //can play anything but hearts to start
	if (i != 0 && move.getSuit() != lead)
	{
		if (noLeadSuit(lead, p.getHand()) && move.getSuit() == HEARTS) { broken = true; return true; }
		else if (noLeadSuit(lead, p.getHand())) { return true; }
		else return false;
	} //if no lead suit any play is valid, if valid play is hearts hearts is broken

	else { return false; }
}

Card HeartsGame::getmove(Player& p, bool& b, std::vector<Card> c, int t, int i)
{
	int move;
	std::vector<Card> h = p.getHand();
	std::cout << p.getip() << " what card would you like to play?" << std::endl;
	displayCards(h);
	std::cin >> move;
	std::swap(h[h.size() - 1], h[move - 1]);
	Card play = h[h.size() - 1];
	if (!validateMove(p, b, c, play, t, i))
	{
		std::cout << "That is not a valid Move" << std::endl; return getmove(p, b, c, t, i);
	}
	else {
		h.pop_back();
		p.setHand(h);
		p.sortHand();
		std::cout << "You played the " << value(play.getValue()) << " of " << suite(play.getSuit()) << std::endl;
		return play;
	}
}

void HeartsGame::updateScore(std::vector<Player>& p)//adds round score to Score
{
	for (size_t i = 0; i<p.size(); ++i)
		if (p[i].getroundScore() == 26) //if a player has shoot the moon
		{
			p[(i + 1) % 4].setScore(p[(i + 1) % 4].getScore() + 26);
			p[(i + 2) % 4].setScore(p[(i + 2) % 4].getScore() + 26);
			p[(i + 3) % 4].setScore(p[(i + 3) % 4].getScore() + 26);
			return;
		}
		else
		{
			p[i].setScore(p[i].getroundScore() + p[i].getScore());
		}
}


bool HeartsGame::playRound(std::vector<Player>& players, std::vector<std::vector<Card>>& history, int round)
{
	std::cout << "Start of Round " << round + 1 << "." << std::endl;
	sendMessage("Start of Round...");
	auto deck = initializeDeck();  //creates deck of cards
	dealCards(players, deck);  //deals cards and resets round scores to 0
	int whoseTurn = passCards(players, round);  //pass cards
	bool turnover = false;  //keeps round going until turn = 13
	bool heartsbroken = false;  //tracks when hearts can be played
	int turn = 1;
	while (!turnover)
	{
		std::vector<Card> center;
		center.reserve(4);
		std::cout << "Turn =" << turn << std::endl << std::endl;
		for (size_t i = 0; i < players.size(); ++i)
		{
			Card move = getmove(players[(whoseTurn + i) % 4], heartsbroken, center, turn, i);
			center.push_back(move);
			std::cout << "The Cards played for this trick are " << std::endl;
			displayCards(center);
		}
		whoseTurn = scoretrick(center, players, whoseTurn);  //scores trick after all players have played
		displayroundScores(players);
		if (turn > 12) //when all cards have been played
		{
			turnover = true;
			updateScore(players);
			displayScores(players);
		}
		history.push_back(center);
		++turn;
	}

	for (size_t i = 0; i < players.size(); ++i)
	{
		if (players[i].getroundScore()>99)
		{
			std::cout << "gameover " << std::endl;
			return true;
		}
	}

	return false;
}

void HeartsGame::startGame(std::vector<Player>& players, std::vector<std::vector<Card>>& history)  //uses players and calls round until game is over
{
	bool gameover = false;
	int round = 0;
	while (!gameover)
	{
		gameover = playRound(players, history, round);
		++round;
	}

}

void HeartsGame::play_Hearts(int num)
{
	auto players = creatPlayers(num);   //creates players 1-4
	std::vector<std::vector<Card>> history;
	startGame(players, history);

}

void HeartsGame::sendMessage(char* message)
{
	chat_message msg;
	msg.body_length(std::strlen(message));
	std::memcpy(msg.body(), message, msg.body_length());
	msg.encode_header();
	chat->write(msg);
}