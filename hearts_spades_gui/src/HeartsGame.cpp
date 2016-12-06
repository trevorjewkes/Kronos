#include "HeartsGame.hpp"
#include <wx/msgdlg.h>
#include <iostream>
#include <thread>
#include <chrono>

//constructor
//takes in a vector of players 
HeartsGame::HeartsGame(std::vector <Player>& players)
{
	this->players = players;
	std::vector<Card> tmp;
	for (int i = 0; i < 4; i++)
	{
		cardsToPass.push_back(tmp);
	}
}

HeartsGame::~HeartsGame()
{
	
}

//creates deck of cards taken from Card.cpp
//returns the deck
std::vector<Card> HeartsGame::initializeDeck() 

{
	std::vector<Card> deck;
	deck.reserve(52);
	std::vector<Suit> suits = { HEARTS, SPADES, CLUBS, DIAMONDS };
	for (auto && suit : suits) {
		for (int i = 2; i<=14; i++) {
			deck.push_back(Card(suit, (Value)i));
		}
	}
	return deck;
}

//looks through each hand to find the 2 of clubs
//returns the index of the player with the 2 of clubs
int HeartsGame::findTwoOfClubs()  
{
	for (size_t i = 0; i < players.size(); ++i)
	{
		std::vector<Card> temp = players[i].getHand();
		for (auto j = 0; j < temp.size(); ++j)
		{
			if (temp[j].getSuit() == Suit::CLUBS && temp[j].getValue() == 2)
			{
				return i;
			}
		}
	}
	return -1;
}

//function for passing cards at beginging of round
//takes the round number
void HeartsGame::passCards(int round)  
{
	int pass = 0;
	if ((round + 1) % 4 == 1) pass = 1;
	if ((round + 1) % 4 == 2) pass = 3;
	if ((round + 1) % 4 == 3) pass = 2;
	for (size_t i = 0; i < players.size(); i++)
	{
		Card card1 = cardsToPass[(i + pass) % players.size()][0];
		Card card2 = cardsToPass[(i + pass) % players.size()][1];
		Card card3 = cardsToPass[(i + pass) % players.size()][2];
		players[i].insertCardToHand(card1);
		players[i].insertCardToHand(card2);
		players[i].insertCardToHand(card3);
	}

	cardsToPass.clear();
	std::vector<Card> tmp;
	for (int i = 0; i < 4; i++)
	{
		cardsToPass.push_back(tmp);
	}
	isPassing = false;
}

//checks to see if a players hand is all hearts.
//takes a vector of cards, ie the player's hand
//returns a bool of whether all the cards are hearts
bool HeartsGame::allhearts(std::vector<Card> h)  
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

//compares hand against the lead suit
//Takes in a suit and the player's hand
//returns a bool whether there is a card with suit s
//in the hand
bool HeartsGame::noLeadSuit(Suit s, std::vector<Card> h)  
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

// checks to see if a move is valid
// takes index of player in vector, the proposed card,
// the trick number, and the turn number
// returns a bool of whether the card is a valid move
bool HeartsGame::validateMove(int index, Card move)
{
	Suit lead;
	bool valid = false;
	if (centerPile.size() > 0) lead = centerPile[0].getSuit();
	if (numTricks == 0)
	{
		if (centerPile.size() == 0)
		{
			if (move.getSuit() == CLUBS && move.getValue() == TWO)
				return true;
			else
				return false;
		}
		else
		{
			if (move.getSuit() != lead && noLeadSuit(lead, players[index].getHand()))
			{
				if (move.getSuit() == HEARTS)
					return false;
				else if (move.getSuit() == SPADES && move.getValue() == QUEEN)
					return false;
				else
					return true;
			}
			else if (move.getSuit() != lead)
				return false;
			else
				return true;
		}
	}
	else
	{
		if (centerPile.size() == 0)
		{
			if (move.getSuit() == HEARTS && (brokenHearts || allhearts(players[index].getHand())))
			{
				brokenHearts = true;
				return true;
			}
			else if (move.getSuit() == HEARTS)
			{
				return false;
			}
			else return true;
		}
		else
		{
			if (move.getSuit() != lead && noLeadSuit(lead, players[index].getHand()))
			{
				if (move.getSuit() == HEARTS)
				{
					brokenHearts = true;
				}
				
				return true;
			}
			else if (move.getSuit() != lead)
				return false;
			else
				return true;
		}
	}
	std::cout << "BROKEN VALIDATION\n";
	return valid;
}

//shuffle and deals the cards to the players
//takes in a deck of cards
void HeartsGame::dealCards(std::vector<Card>& Deck)
{

	std::random_device rd;
	std::mt19937 generator(rd());
	std::shuffle(Deck.begin(), Deck.end(), generator);
	for (size_t i = 0; i < players.size(); i++)
	{
		for (auto j = 0; j < 13; j++)
		{
			players[i].insertCardToHand(Deck[(j)+(13 * i)]);
		}
	}
}

bool HeartsGame::play(bool start)
{
	if (start)
		currentPlayerIndex = findTwoOfClubs();

	for (int i = 0; i < 4; i++)
	{
		isRoundOver = false;
		if (turn == 4)
		{
			endTurn();
			if (players[i].getHand().size() == 0)
			{
				endRound();
				isRoundOver = true;
				if (round % 4 == 3)
				{
					isPassing = false;
				}
				turn = 0;
				
				if (isGameOver) return false;
				if (isPassing) return false;
			}
			turn = 0;
			
			//if (currentPlayerIndex == 1) currentPlayerIndex = 3;
			numTricks++;
			centerPile.clear();
			i = 0;
			return true;
		}
		bool valid = false;
		do
		{
			if (players[(currentPlayerIndex) % players.size()].getId() == 0) return true;
			//for AI
			valid = playCard(HeartsAI::getPlay(players[(currentPlayerIndex)].getHand()), 
							players[(currentPlayerIndex)].getId());
		} while (!valid);
		currentPlayerIndex = (currentPlayerIndex + 1) % 4;
		turn++;
	}
	return true;
}
//begins the game of hearts
//can be called multiple times to 
//play again
Status HeartsGame::play_Hearts()
{
	isPassing = true;
	brokenHearts = false;
	//creates deck of cards
	auto deck = initializeDeck();  

	//deals cards and resets round scores to 0
	dealCards(deck); 
	Status tmp;
	for (auto player : players)
	{
		if (player.getId() >= 0)
		{
			tmp.center = centerPile;
			tmp.hand = player.getHand();
		}
	}
	numTricks = 0;
	return tmp;
}

bool HeartsGame::pass(int index)
{
  if (index >= players[0].getHand().size()) {
    return false;
  }
	cardsToPass[0].push_back(players[0].getHand()[index]);
				players[0].removeCardFromHand(players[0].getHand()[index]);
	if (cardsToPass[0].size() == 3)
	{
		for (int i = 1; i < cardsToPass.size(); i++)
		{
			for (int j = 0; j < 3; j++)
			{
        Card tmp = HeartsAI::getPass(players[i].getHand());
				cardsToPass[i].push_back(tmp);
				players[i].removeCardFromHand(tmp);
			}
		}
		passCards(round++);
		return true;
	}
	return false;
}

//preps the passing cards
//takes the vector of card indexes and the name of the player
int HeartsGame::setPassCards(std::vector<Card> cards, std::string name)
{
	int player = -1;
	for (int i = 0; i < players.size(); i++)
	{
		if (players[i].getName() == name)
		{
			for (int j = 0; j < cards.size(); j++)
			{
				Card tmp = cards[j];
				passCard(tmp, i);
				if(players[i].removeCardFromHand(tmp)) std::cout << "yes" << std::endl;
			}			
		}
	}
	bool ready = true;
	for (int i = 0; i < cardsToPass.size(); i++)
	{
		if (cardsToPass[i].size() != 3)
		{
			ready = false;
			break;
		}
	}
	if (ready)
	{
		passCards(round++);
		player = findTwoOfClubs();
	}
	return player;
}

//plays a card
//takes the card index value in hand and player's name
//returns -1 if card was invalid else returns the player 
//that made the move
int HeartsGame::playCard(Card card, int id)
{
	int nextPlayer = 0;
	for (int i = 0; i < players.size(); i++)
	{
		if (players[i].getId() == id)
		{
			
				Card tmp = card;
				if (!validateMove(i, tmp))
				{
					return false;
				}

				players[i].removeCardFromHand(tmp);
				centerPile.push_back(tmp);
				nextPlayer = (i + 1)%4;
		}
	}
	return true;
	bool endRound = true;
	bool bEndTurn = true;
	for (int i = 0; i < players.size(); i++)
	{
		if (players[i].getHand().size() != 0) endRound = false;
		if (players[i].getHand().size() != players[(i + 1) % 4].getHand().size()) bEndTurn = false;
	}
	//if (!endRound) return -2;
	//if (bEndTurn) nextPlayer = endTurn((nextPlayer+4-1)%4);
	turn = (turn + 1) % 4;
	return true;
}

//finished the turn
//takes the index of the current player
//returns the player index who won the trick
void HeartsGame::endTurn()
{
	Suit leadSuit = centerPile[0].getSuit();
	int maxIndex = 0;
	int maxValue = 0;
	int score = 0;
	for (int i = 0; i < centerPile.size(); i++)
	{
		Card tmp = centerPile[i];
		if (tmp.getSuit() == leadSuit && tmp.getValue() > maxValue)
		{
			maxValue = tmp.getValue();
			maxIndex = i;
		}
		if (tmp.getSuit() == SPADES && tmp.getValue() == QUEEN) score += 13;
		if (tmp.getSuit() == HEARTS) score++;
	}
	int winningPlayer = (maxIndex + currentPlayerIndex) % players.size();
	players[winningPlayer].incrementRoundScore(score);
	players[winningPlayer].incrementTricksWon();
	currentPlayerIndex = winningPlayer;
}

//finishes the round and applies scores
void HeartsGame::endRound()
{
	for (int i = 0; i < players.size(); i++)
	{
		if (players[i].getRoundScore() == 26)
		{
			players[i].setRoundScore(0);
			players[(i + 1) % 4].setRoundScore(26);
			players[(i + 2) % 4].setRoundScore(26);
			players[(i + 3) % 4].setRoundScore(26);
			break;
		}
	}
	for (int i = 0; i < players.size(); i++)
	{
		players[i].startNewRound();
		if (players[i].getTotalScore() >= 100) gameOver(); //for testing set to 10
	}
	centerPile.clear();
	turn = 0;
  endRoundPopup();
	play_Hearts();
}

void HeartsGame::endRoundPopup() {
  //build message
  std::string msg = "-- End of round --\n\n";
	for (int i = 0; i < players.size(); i++)
	{
    msg += "\t" + players[i].getName() + " score: " 
        + std::to_string(players[i].getRoundScore()) +
        " (" + std::to_string(players[i].getTotalScore()) + ")\n"; 
	}
  wxMessageBox(msg);
}

//passes a card
//takes a card and index of player
void HeartsGame::passCard(Card tmp, int i)
{
	cardsToPass[i].push_back(tmp);
}

void HeartsGame::setPrivatePasscode(std::string passcode)
{
	privatePasscode = passcode;
}

bool HeartsGame::playCard(int index)
{
	if (index >= players[0].getHand().size()) return false;
	bool valid = playCard(players[0].getHand()[index], players[0].getId());
	if (!valid) return false;
	currentPlayerIndex = (currentPlayerIndex + 1) % 4;
	turn++;
	return true;
}

Status HeartsGame::updateStatus()
{
	Status tmp;
	tmp.center = centerPile;
	tmp.hand = players[0].getHand();
	for (int i = 0; i < players.size(); i++)
	{
		tmp.scores.push_back(players[i].getTotalScore());
		tmp.tricks.push_back(players[i].getTricksWon());
	}
	tmp.isGameOver = isGameOver;
	tmp.passing = isPassing;
	tmp.isRoundOver = isRoundOver;
	return tmp;
}

void HeartsGame::gameOver()
{
	isGameOver = true;
}
