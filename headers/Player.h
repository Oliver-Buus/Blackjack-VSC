#ifndef PLAYER_H
#define PLAYER_H

#include "Participant.h"
#include <string>

using namespace std;

class Player : public Participant {
private:
    string name;
    int balance;

public:
    Player(string name);

    int getBalance();
    int adjustBalance(int amount);
    void setName(string name);
    string getName();
};

#endif