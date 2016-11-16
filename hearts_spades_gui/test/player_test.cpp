#include "catch.h"
#include "Player.hpp"
#include "Card.hpp"

TEST_CASE("player") {
	Player p1(1,"1.0.0.0");	
	REQUIRE(p1.getId() == 1);
	REQUIRE(p1.getIp() == "1.0.0.0");
	REQUIRE(p1.getName() == "noname");

	p1.setName("bob");
	REQUIRE(p1.getName() == "bob");

	std::vector<Card> deck = initializeDeck();
	p1.initializeHand(deck, 13);
	REQUIRE(p1.getHand().size() == 13);
	REQUIRE(p1.removeCardFromHand(p1.getHand()[0]));
	REQUIRE(p1.getHand().size() == 12);

	p1.insertCardToHand(Card(HEARTS,NINE));
	REQUIRE(p1.getHand().size() == 13);
	REQUIRE(p1.getRoundScore() == 0);

	p1.setRoundScore(1);
	REQUIRE(p1.getRoundScore() == 1);
	p1.incrementRoundScore(5);
	REQUIRE(p1.getRoundScore() == 6);
	REQUIRE(p1.getOverallScores().size() == 0);
	REQUIRE(p1.getTotalScore() == 6);
}
