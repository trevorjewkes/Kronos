#include "catch.h"
#include "Card.hpp"
#include <vector>

TEST_CASE("initDeck") 
{
	std::vector<Card> deck = initializeDeck();	
	REQUIRE(deck.size() == 52);
}
