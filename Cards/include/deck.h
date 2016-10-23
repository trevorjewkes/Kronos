#pragma once
#include "card.h"
#include <vector>

class Deck {
public:
  Deck();
  ~Deck();
  void shuffleCards();
  Card drawCard();
private:
  std::vector<Card> cards;
  int topCardIndex;
};
