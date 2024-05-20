#include "headers/Player.h"
#include <sstream>
using namespace std;

Player::Player(string name)
    : balance(500),
    name(name) {}

void Player::addToHand(const Card& card) {
    hand.push_back(card);
}

void Player::clearHand() {
    hand.clear();
}

int Player::getHandValue() {
    int value = 0;
    for (const Card& card : hand) {
        value += card.getValueAmount();
    }
    return value;
}

string Player::showHand() {
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

int Player::getBalance() {
    return balance;
}

int Player::adjustBalance(int amount) {
    return balance + amount;
}

void Player::setName(string name) {
    this-> name = name;
}