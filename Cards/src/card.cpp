#include "card.h"
#include <cassert>

Card::Card(int id_, int value_, Suit suit_)
    : id(id_), value(value_), valid(true), discarded(false), suit(suit_) {
  assert(id >= 0 && id <= 52);
  // could throw an error instead
}

// what exactly do we need to compare?
// value or id
bool Card::operator<(const Card &a) const { return value < a.value; }

bool Card::operator>(const Card &a) const { return value > a.value; }

bool Card::operator==(const Card &a) const { return id == a.id; }

bool Card::operator!=(const Card &a) const { return id != a.id; }

Card::~Card() {}
