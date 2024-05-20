#ifndef PLAYER_H
#define PLAYER_H

#include <vector>
#include "Card.h"
#include <string>

using namespace std;

class Player {
private:
    vector<Card> hand;
    string name;
    int balance;

public:
    Player(string name);

    void addToHand(const Card& card);
    void clearHand();
    int getHandValue();
    string showHand();
    int getBalance();
    int adjustBalance(int amount);
    void setName(string name);
};

#endif