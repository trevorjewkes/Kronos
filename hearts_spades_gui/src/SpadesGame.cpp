#include "SpadesGame.hpp"
#include <iostream>

//constructor
//takes in a vector of players
SpadesGame::SpadesGame(std::vector <Player>& players)
{
	this->players = players;
}

SpadesGame::~SpadesGame()
{

}

//creates deck of cards taken from Card.cpp
//returns the deck
std::vector<Card> SpadesGame::initializeDeck()

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


//checks to see if a players hand is all spades.
//takes a vector of cards, ie the player's hand
//returns a bool of whether all the cards are spades
bool SpadesGame::allSpades(std::vector<Card> h)
{

	for (size_t i = 0; i < h.size(); ++i)
	{
		if (h[i].getSuit() != SPADES)
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
bool SpadesGame::noLeadSuit(Suit s, std::vector<Card> h)
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
bool SpadesGame::validateMove(int index, Card move)
{
	Suit lead;
	bool valid = false;
	if (centerPile.size() > 0) lead = centerPile[0].getSuit();
	if (numTricks == 0)
	{
		if (centerPile.size() == 0)
		{
			if (move.getSuit()==SPADES)
				return false;
			else
				return true;
		}

	else
		{
			if (move.getSuit() != lead && noLeadSuit(lead, players[index].getHand()))
			{
				if (move.getSuit() == SPADES)
				{
					brokenSpades = true;
				}

				return true;
			}
			else if (move.getSuit() != lead)
				return false;
		}
	}
	std::cout << "BROKEN VALIDATION\n";
	return valid;
}

//shuffle and deals the cards to the players
//takes in a deck of cards
void SpadesGame::dealCards(std::vector<Card>& Deck)
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

void SpadesGame::play(bool start)
{
	if(start)
		currentPlayerIndex = turn;


	for (int i = 0; i < 4; i++)
	{

		if (turn == 4)
		{
			if (players[i].getHand().size() == 0)
			{
				endRound();
				turn = 0;
				if (isGameOver) return;
				if (isBidding) return;
			}
			turn = 0;

			//if (currentPlayerIndex == 1) currentPlayerIndex = 3;
			endTurn();
			numTricks++;
			centerPile.clear();
			i = 0;

		}
		bool valid = false;
		do
		{
			if (players[(currentPlayerIndex) % players.size()].getId() == 0) return;
			//for AI
			valid = playCard(SpadesAI::getPlay(players[(currentPlayerIndex)].getHand()),
							players[(currentPlayerIndex)].getId());
		} while (!valid);
		currentPlayerIndex = (currentPlayerIndex + 1) % 4;
		turn++;
	}

}
//begins the game of spades
//can be called multiple times to
//play again
Status SpadesGame::play_Spades()
{
	isBidding = true;
	brokenSpades = false;
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
//plays a card
//takes the card index value in hand and player's name
//returns -1 if card was invalid else returns the player
//that made the move
int SpadesGame::playCard(Card card, int id)
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
void SpadesGame::endTurn()
{
	Suit leadSuit = centerPile[0].getSuit();
	int maxIndex = 0;
	int maxValue = 0;
	for (int i = 0; i < centerPile.size(); i++)
	{
		Card tmp = centerPile[i];
		if ((tmp.getSuit() == SPADES) &&((leadSuit != SPADES)))
		{
			leadSuit = SPADES;
			maxValue = tmp.getValue();
			maxIndex = i;
		}

		if (tmp.getSuit() == leadSuit && tmp.getValue() > maxValue)
		{
			maxValue = tmp.getValue();
			maxIndex = i;
		}

	}
	players[(maxIndex + currentPlayerIndex) % players.size()].incrementTricksWon();
	centerPile.clear();
	currentPlayerIndex = (maxIndex+ currentPlayerIndex)%players.size();
}

//finishes the round and applies scores
void SpadesGame::endRound()
{
	for (int i = 0; i < players.size(); i++)
	{
		int total_bid = (players[i].getBid() + players[((i+2)%players.size())].getBid());
		int total_trick = (players[i].getTricksWon()+players[((i+2)%players.size())].getTricksWon());
		if (total_trick<total_bid)
		{
			players[i].setRoundScore(-(total_bid*10));
		}

		else
		{
			int bags = (total_trick-total_bid);
			players[i].setBags(bags+players[i].getBags());
			if (players[i].getBags()>9)
				{
					players[i].setRoundScore(-100);
				}
			players[i].setRoundScore((total_bid*10)+bags);
		}
	}

	for (int i = 0; i < players.size(); ++i)
	{
		if (players[i].getRoundScore()>500)
		{
			isGameOver = true;
		}
		else
		{
				players[i].startNewRound();
		}
	}
}

bool SpadesGame::playCard(int index)
{
	if (index >= players[0].getHand().size()) return false;
	bool valid = playCard(players[0].getHand()[index], players[0].getId());
	if (!valid) return false;
	currentPlayerIndex = (currentPlayerIndex + 1) % 4;
	turn++;
	return true;
}

Status SpadesGame::updateStatus()
{
	Status tmp;
	tmp.center = centerPile;
	tmp.hand = players[0].getHand();
	for (int i = 0; i < players.size(); i++)
	{
		tmp.scores.push_back(players[i].getTotalScore());
		tmp.tricks.push_back(players[i].getTricksWon());
		tmp.bids.push_back(players[i].getBid());
	}
	tmp.isGameOver = isGameOver;
	tmp.bidding = isBidding;
	return tmp;
}

void SpadesGame::gameOver()
{
	isGameOver = true;
}

void SpadesGame::doBids(int bid)
{
	players[0].setBid(bid);
	for (int i = 1; i < players.size(); i++)
	{
		players[i].setBid(SpadesAI::getBid(players[i].getHand()));
	}
}
