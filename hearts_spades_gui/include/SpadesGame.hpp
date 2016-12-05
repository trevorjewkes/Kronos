#ifndef SPADES_GAME_HPP
#define SPADES_GAME_HPP

#include "Player.hpp"
#include <random>
#include <algorithm>

class SpadesGame
{
public:
	bool playCard(int index);
	SpadesGame(std::vector<Player> &players);
	~SpadesGame();
	void doBids(int bid);
	Status play_Spades();
	void endTurn();
	void endRound();
	int setPassCards(std::vector<Card> cards, std::string name);
	int playCard(Card card, int id);
	std::vector<Player> getPlayers() { return players; }
	std::vector<Card> getCenterPile() { return centerPile; }
	std::string getPrivatePasscode() { return privatePasscode; }
	void setPrivatePasscode(std::string passcode);
	bool pass(int index);
	Status updateStatus();
	void play(bool start);
private:
	bool isBidding = false;
	std::vector<Card> initializeDeck();
	void dealCards(std::vector<Card>& Deck);
	int currentPlayerIndex;

	bool allSpades(std::vector<Card> h);
	//compares hand against the lead suit
	bool noLeadSuit(Suit s, std::vector<Card> h);
	bool validateMove(int index, Card move);
	std::vector<Player> players;
	std::vector<Card> centerPile;

	bool brokenSpades = false;
	void gameOver();
	bool isGameOver = false;
	int turn = 0;
	int round = 0;
	int numTricks = 0;
	void passCard(Card tmp, int i);
	std::string privatePasscode;
};

class SpadesAI
{
public:
	static Card getPlay(std::vector<Card> hand)
	{
		return hand[rand() % hand.size()];
	}
	static int getBid(std::vector<Card> hand)
	{
		return rand() % 4;
	}

private:

};
#endif //SPADES_GAME_HPP
