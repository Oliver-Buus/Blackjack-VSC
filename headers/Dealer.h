#ifndef DEALER_H
#define DEALER_H

#include "Participant.h"

using namespace std;

class Dealer : public Participant {
public:
    Dealer();

    void addToHand(const Card& card) override;
    void clearHand() override;
    int getHandValue() override;
    string showHand() override;
};


#endif