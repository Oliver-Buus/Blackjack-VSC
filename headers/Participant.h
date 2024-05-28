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
    virtual void addToHand(const Card& card) = 0;
    virtual void clearHand() = 0;
    virtual int getHandValue() = 0;
    virtual string showHand() = 0;
};

// Virtual og = 0 gør klassen abstrakt


#endif