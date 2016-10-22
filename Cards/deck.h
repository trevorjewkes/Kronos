#pragma once
#include "card.h"
#include <vector>
#include <random>
#include <algorithm>
class Deck
{
 public:
	Deck();
	~Deck();
	std::vector<Card> cards;
	void shuffleCards();
	int topCardIndex;
	Card drawCard();
	//maybe add a function to sort, draw card??
};