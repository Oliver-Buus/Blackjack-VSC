#include "headers/Card.h"

Card::Card(CardValue value, Suit suit, bool faceUp)
    : value(value),
    suit(suit),
    faceUp(faceUp) {}

CardValue Card::getValue() const {
    return value;
}

int Card::getValueAmount() const {
    if (!faceUp) return 0;

    switch (value) {   
        case CardValue::Two: return 2;
        case CardValue::Three: return 3;
        case CardValue::Four: return 4;
        case CardValue::Five: return 5;
        case CardValue::Six: return 6;
        case CardValue::Seven: return 7;
        case CardValue::Eight: return 8;
        case CardValue::Nine: return 9;
        case CardValue::Ten: return 10;
        case CardValue::Jack: return 10;
        case CardValue::Queen: return 10;
        case CardValue::King: return 10;
        case CardValue::Ace: return 11;
        default: return 0;
    }
}

Suit Card::getSuit() {
    return suit;
}

bool Card::isFaceUp() {
    return faceUp;
}

string Card::toString() {
    string str;

    if (faceUp) {
        switch (value) {
            case CardValue::Two: str += "Two"; break;
            case CardValue::Three: str += "Three"; break;
            case CardValue::Four: str += "Four"; break;
            case CardValue::Five: str += "Five"; break;
            case CardValue::Six: str += "Six"; break;
            case CardValue::Seven: str += "Seven"; break;
            case CardValue::Eight: str += "Eight"; break;
            case CardValue::Nine: str += "Nine"; break;
            case CardValue::Ten: str += "Ten"; break;
            case CardValue::Jack: str += "Jack"; break;
            case CardValue::Queen: str += "Queen"; break;
            case CardValue::King: str += "King"; break;
            case CardValue::Ace: str += "Ace"; break;
        }
        
        str += " of ";

        switch (suit) {
            case Suit::Hearts: str += "Hearts"; break;
            case Suit::Diamonds: str += "Diamonds"; break;
            case Suit::Clubs: str += "Clubs"; break;
            case Suit::Spades: str += "Spades"; break;            
        }

    } else {
        str = "Face down";
    }

    return str;
}