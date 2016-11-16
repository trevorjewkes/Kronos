#include "catch.h"
#include "Card.hpp"

TEST_CASE("card") {
	Card card(HEARTS, NINE);	
	Card card2(HEARTS, EIGHT);
	Card card3(HEARTS, NINE);
	Card card4(SPADES, NINE);

	REQUIRE(card == card3);
	REQUIRE(card != card2);
	REQUIRE(card2 < card);
	REQUIRE(card4 > card);
	REQUIRE(card < card4);
}
