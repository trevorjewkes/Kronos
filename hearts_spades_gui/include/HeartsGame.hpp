#ifndef HEARTS_GAME_HPP
#define HEARTS_GAME_HPP

#include "Player.hpp"
#include <random>
#include <algorithm>

class HeartsGame
{
public:
	bool playCard(int index);
	HeartsGame(std::vector<Player> &players);
	~HeartsGame();
	Status play_Hearts();
	//looks through each hand to find the 2 of clubs
	int findTwoOfClubs();  
	//function for passing cards at beginging of round
	void passCards(int round);  
	void endTurn();
	void endRound();
  void endRoundPopup();
	int setPassCards(std::vector<Card> cards, std::string name);
	int playCard(Card card, int id);
	std::vector<Player> getPlayers() { return players; }
	std::vector<Card> getCenterPile() { return centerPile; }
	std::string getPrivatePasscode() { return privatePasscode; }
	void setPrivatePasscode(std::string passcode);
	bool pass(int index);
	Status updateStatus();
	bool play(bool start);
private:
	bool isPassing = false;
	bool isRoundOver = false;
	std::vector<Card> initializeDeck();
	void dealCards(std::vector<Card>& Deck);
	int currentPlayerIndex;
	int fixPass(int r, int p, int c);
	//checks to see if a players hand is all hearts.
	bool allhearts(std::vector<Card> h);  
	//compares hand against the lead suit
	bool noLeadSuit(Suit s, std::vector<Card> h);  
	bool validateMove(int index, Card move);
	std::vector<Player> players;
	std::vector<Card> centerPile;
	
	bool brokenHearts = false;
	void gameOver();
	bool isGameOver = false;
	int turn = 0;
	int round = 0;
	int numTricks = 0;
	std::vector<std::vector<Card>> cardsToPass;
	void passCard(Card tmp, int i);
	std::string privatePasscode;
};

class HeartsAI
{
public:
	static Card getPass(std::vector<Card> hand)
	{
		return hand[rand() % hand.size()];
	}
	static Card getPlay(std::vector<Card> hand)
	{
		return hand[rand() % hand.size()];
	}

private:

};
#endif //HEARTS_GAME_HPP
