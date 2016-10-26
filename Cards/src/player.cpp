#include "player.h"
#include <algorithm>

Player::Player(std::string name_) : name(name_), score(0), turn(false) {
  hand.reserve(13);
}

Player::~Player() {}

void Player::addCard(Card newCard) { hand.push_back(newCard); }

void Player::sortHand() { std::sort(hand.begin(), hand.end()); }
