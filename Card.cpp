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

std::ostream& operator<<(std::ostream& os, const Card& card) {
    if (card.faceUp) {
        switch (card.value) {
            case CardValue::Two: os << "Two"; break;
            case CardValue::Three: os << "Three"; break;
            case CardValue::Four: os << "Four"; break;
            case CardValue::Five: os << "Five"; break;
            case CardValue::Six: os << "Six"; break;
            case CardValue::Seven: os << "Seven"; break;
            case CardValue::Eight: os << "Eight"; break;
            case CardValue::Nine: os << "Nine"; break;
            case CardValue::Ten: os << "Ten"; break;
            case CardValue::Jack: os << "Jack"; break;
            case CardValue::Queen: os << "Queen"; break;
            case CardValue::King: os << "King"; break;
            case CardValue::Ace: os << "Ace"; break;
        }
        os << " of ";
        switch (card.suit) {
            case Suit::Hearts: os << "Hearts"; break;
            case Suit::Diamonds: os << "Diamonds"; break;
            case Suit::Clubs: os << "Clubs"; break;
            case Suit::Spades: os << "Spades"; break;
        }
    } else {
        os << "Face Down";
    }
    return os;
}