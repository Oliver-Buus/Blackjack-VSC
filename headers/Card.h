#ifndef CARD_H
#define CARD_H

// Libraries
#include <iostream>

// Enums card values
enum class CardValue {
    Two, Three, Four, Five, Six, Seven, Eight, Nine, Ten, Jack, Queen, King, Ace 
};

// Enums card suits
enum class Suit {
    Hearts, Diamonds, Clubs, Spades
};

// Card class
class Card {
private:
    CardValue value;
    Suit suit;
    bool faceUp;

public:
    Card(CardValue value, Suit suit, bool faceUp = true);

    // Methods
    CardValue getValue();
    int getValueAmount() const;
    Suit getSuit();
    bool isFaceUp();

    //
    friend std::ostream& operator<<(std::ostream& os, const Card& card);
};

#endif