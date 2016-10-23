#include "catch.h"
#include "card.h"
#include "deck.h"

TEST_CASE("deck") {
	Deck deck;
	Card card(0, 2, CLUBS);
	
	REQUIRE(deck.drawCard() == card ); 
	deck.shuffleCards();
	//this should pass about 98% of the time
	REQUIRE(deck.drawCard() != card ); 
}
