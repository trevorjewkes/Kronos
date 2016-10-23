#pragma once
#include "card.h"
#include <string>
#include <vector>

class Player {
public:
  Player(std::string name_);
  ~Player();
  void addCard(Card newCard);
  void sortHand();
  int getScore() { return score; }
  std::vector<Card> getHand() { return hand; }
  bool isTurn() { return turn; }
  void setTurn(bool turn_) { turn = turn_; }
  std::string getName() { return name; }
  void setName(std::string name_) { name = name_; }

private:
  std::vector<Card> hand;
  std::string name;
  int score;
  bool turn;
};
