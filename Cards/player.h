#pragma once
#include <string>
#include <vector>

#include "card.h"
class Player
{
public:
	Player(std::string name_);
	~Player();
	void addCard(Card newCard);
	std::vector<Card> hand;
	int getScore() { return score; }
	bool isTurn() { return turn; }
	std::string getName() { return name; }
	void sortHand();


private:
	std::string name;
	int score;
	bool turn;
};

