#include "headers/Dealer.h"


Dealer::Dealer() {}

void Dealer::addToHand(const Card& card) {
    hand.push_back(card);
}

void Dealer::clearHand() {
    hand.clear();
}

int Dealer::getHandValue() {
    int value = 0;
    int numberOfAces = 0;

    for (const Card& card : hand) {
        value += card.getValueAmount();
    }

    numberOfAces = count_if(hand.begin(), hand.end(), [](const Card& card) {
        return card.getValue() == CardValue::Ace;
    }); // STL

    if (value > 21 && numberOfAces > 0) {
        value -= 10;
        numberOfAces--;
    }

    return value;
}

string Dealer::showHand() {
    string str;

        for (int i = 0; i < hand.size(); ++i) {
        str += hand.at(i).toString();
        if (i != hand.size() - 1) {
            str += ", ";
        }
    }

    str += '\n';

    return str;    
}