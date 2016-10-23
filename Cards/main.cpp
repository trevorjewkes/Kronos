#include <iostream>
#include "player.h"
#include "deck.h"

int main()
{
	Deck myDeck;
	myDeck.shuffleCards();

	Player p1("Joe");
	Player p2("Frank");
	Player p3("Bob");
	Player p4("Jill");

	for (int i = 0; i < 13; i++)
	{
		p1.addCard(myDeck.drawCard());
		p2.addCard(myDeck.drawCard());
		p3.addCard(myDeck.drawCard());
		p4.addCard(myDeck.drawCard());
	}
	p1.sortHand();
	p2.sortHand();
	p3.sortHand();
	p4.sortHand();
	std::string suitName = "";
	std::cout << p1.getName() << "'s hand: " << std::endl;
	for (int i = 0; i < (int)p1.hand.size(); i++)
	{
		if (p1.hand[i].getSuit() == 0) suitName = "CLUBS";
		else if (p1.hand[i].getSuit() == 1) suitName = "HEARTS";
		else if (p1.hand[i].getSuit() == 2) suitName = "SPADES";
		else suitName = "DIAMONDS";
		std::cout << p1.hand[i].getId() << ' ' << p1.hand[i].getValue() << ' ' << suitName << std::endl;
	}
	std::cout << p2.getName() << "'s hand: " << std::endl;
	for (int i = 0; i < (int)p2.hand.size(); i++)
	{
		if (p2.hand[i].getSuit() == 0) suitName = "CLUBS";
		else if (p2.hand[i].getSuit() == 1) suitName = "HEARTS";
		else if (p2.hand[i].getSuit() == 2) suitName = "SPADES";
		else suitName = "DIAMONDS";
		std::cout << p2.hand[i].getId() << ' ' << p2.hand[i].getValue() << ' ' << suitName << std::endl;
	}
	std::cout << p3.getName() << "'s hand: " << std::endl;
	for (int i = 0; i < (int)p1.hand.size(); i++)
	{
		if (p3.hand[i].getSuit() == 0) suitName = "CLUBS";
		else if (p3.hand[i].getSuit() == 1) suitName = "HEARTS";
		else if (p3.hand[i].getSuit() == 2) suitName = "SPADES";
		else suitName = "DIAMONDS";
		std::cout << p3.hand[i].getId() << ' ' << p3.hand[i].getValue() << ' ' << suitName << std::endl;
	}
	std::cout << p4.getName() << "'s hand: " << std::endl;
	for (int i = 0; i < (int)p4.hand.size(); i++)
	{
		if (p4.hand[i].getSuit() == 0) suitName = "CLUBS";
		else if (p4.hand[i].getSuit() == 1) suitName = "HEARTS";
		else if (p4.hand[i].getSuit() == 2) suitName = "SPADES";
		else suitName = "DIAMONDS";
		std::cout << p4.hand[i].getId() << ' ' << p4.hand[i].getValue() << ' ' << suitName << std::endl;
	}
	return 0;
}
