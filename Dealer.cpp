#include "headers/Dealer.h"
#include <sstream>


using namespace std;

Dealer::Dealer() {}

void Dealer::addToHand(const Card& card) {
    hand.push_back(card);
}

void Dealer::clearHand() {
    hand.clear();
}

int Dealer::getHandValue() {
    int value = 0;
    for (const Card& card : hand) {
        value += card.getValueAmount();
    }
    return value;
}

string Dealer::showHand() {
    stringstream ss;

    for (int i = 0; i < hand.size(); i++) {
        if (i == hand.size() - 1) {
            ss << hand.at(i) << '\n';
        } else {
            ss << hand.at(i) << ", ";
        }
    }

    return ss.str();    
}