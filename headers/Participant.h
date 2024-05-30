#ifndef PARTICIPANT_H
#define PARTICIPANT_H

#include "Card.h"
#include <vector>
#include <algorithm>

using namespace std;

class Participant {
protected:
    vector<Card> hand;

public:
    void addToHand(const Card& card) {
        hand.push_back(card);
    };

    void clearHand() {
        hand.clear();
    };

    int getHandValue() {
        int value = 0;
        int numberOfAces = 0;

        for (const Card& card : hand) {
            value += card.getValueAmount();
        }

        numberOfAces = count_if(hand.begin(), hand.end(), [](const Card& card) {
            return card.getValue() == CardValue::Ace;
        }); // STL

        while (value > 21 && numberOfAces > 0) {
            value -= 10;
            numberOfAces--;
        }

        return value;
    };

    string showHand() {
        string str;

        for (int i = 0; i < hand.size(); ++i) {
            str += hand.at(i).toString();
            if (i != hand.size() - 1) {
                str += ", ";
            }
        }

        return str; 
    };
};

// Virtual og = 0 gør klassen abstrakt


#endif