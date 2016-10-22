#include "deck.h"

Deck::Deck()
{
	Suit suit = CLUBS;
	topCardIndex = 0;
	int j = 2;
	for (int i = 0; i < 52; i++)
	{
		if (i >= 39)
		{
			if (i == 39)j = 2;
			suit = DIAMONDS;
		}
		else if (i >= 26)
		{
			if (i == 26) j = 2;
			suit = SPADES;
		}
		else if (i >= 13)
		{
			if (i == 13) j = 2;
			suit = HEARTS;
		}
		else if (i < 13)
		{
			if (i == 0) j = 2;
			suit = CLUBS;
		}

		Card tmpCard(i, j, suit);
		cards.push_back(tmpCard);
		j++;
		
	}
}

Deck::~Deck()
{

}

void Deck::shuffleCards()
{
	std::random_device rd;
	std::mt19937 g(rd());

	std::shuffle(cards.begin(), cards.end(), g);
}

Card Deck::drawCard()
{
	topCardIndex++;
	if (topCardIndex > 52) topCardIndex = 1;
	return cards[topCardIndex - 1];
}