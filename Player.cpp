#include "headers/Player.h"
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

string Player::showHand() {
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