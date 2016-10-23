#pragma once

enum Suit { CLUBS, HEARTS, SPADES, DIAMONDS };

class Card {
public:
  Card(int id, int value, Suit suit);
  int getId() { return id; }
  int getValue() { return value; }
  bool isValid() { return valid; }
  bool isDiscarded() { return discarded; }
  Suit getSuit() { return suit; }
  void setValid(bool valid_t) { valid = valid_t; }
  void setDiscarded(bool discarded_t) { discarded = discarded_t; }
  bool operator<(const Card &a) const;
  bool operator>(const Card &a) const;
  bool operator==(const Card &a) const;
  bool operator!=(const Card &a) const;

  ~Card();

private:
  int id;
  int value;
  bool valid;
  bool discarded;
  Suit suit;
};
