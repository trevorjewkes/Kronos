#include "deck.h"
#include "card.h"
#include <cassert>

Deck::Deck() : topCardIndex(0) {
  cards.reserve(52);

  // initialize the deck
  int id = 0;
  for (int i = 0; i < 4; i++) {
    for (int j = 0; j < 13; j++) {
      Card tmpCard(id++, j + 2, static_cast<Suit>(i));
      cards.push_back(tmpCard);
    }
  }
  assert(cards.size() == 52);
}

Deck::~Deck() {}

void Deck::shuffleCards() {
  std::random_device rd;
  std::mt19937 g(rd());

  std::shuffle(cards.begin(), cards.end(), g);
}

Card Deck::drawCard() {
  topCardIndex++;
  if (topCardIndex > 52) {
    topCardIndex = 1;
  }
  return cards[topCardIndex - 1];
}
