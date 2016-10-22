#include "card.h"

Card::Card(int id_, int value_, Suit suit_)
{
	id = id_;
	value = value_;
	suit = suit_;
	discarded = false;
	valid = true;
}

bool Card::operator<(const Card & a) const
{
	return id < a.id;
}

Card::~Card()
{
}