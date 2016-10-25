#include "catch.h"
#include "player.h"

TEST_CASE("player") {
	Player player1("Jim");
	Player player2("Sally");
	Card card(0, 2, CLUBS);

	REQUIRE(player1.getHand().size() == 0);
	REQUIRE(player1.getScore() == 0);
	REQUIRE(player1.getName() == "Jim");
	REQUIRE(player1.getHand().size() == 0);
	player1.addCard(card);
	REQUIRE(player1.getHand().size() == 1);
	int id = 2, j = 0, i = 0;
	Card tmpCard(id++ , j, (Suit)i);	
}
