#include "catch.h"
#include "card.h"

TEST_CASE("card") {
	Card testCard(0,1,SPADES);
	Card testCard2(1,2,HEARTS);

  REQUIRE(testCard.getId() == 0);
  REQUIRE(testCard.getValue() == 1);
  REQUIRE(testCard.isValid() == true);
  REQUIRE(testCard.isDiscarded() == false);
  REQUIRE(testCard.getSuit() == SPADES);
	REQUIRE((testCard < testCard2) == true);
	REQUIRE(testCard.isValid() == true);

	testCard.setValid(false);
	REQUIRE(testCard.isValid() == false);

	testCard.setDiscarded(true);
	REQUIRE(testCard.isDiscarded() == true);
}
