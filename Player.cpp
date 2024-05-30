#include "headers/Player.h"
using namespace std;

Player::Player(string name)
    : balance(500),
    name(name) {}


int Player::getBalance() {
    return balance;
}

int Player::adjustBalance(int amount) {
    return balance += amount;
}

void Player::setName(string name) {
    this-> name = name;
}

string Player::getName() {
    return name;
}