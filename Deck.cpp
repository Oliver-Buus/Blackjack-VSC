#include "headers/Deck.h"
#include <algorithm>
#include <random>
#include <ctime>

Deck::Deck() {    
    for (int i = 0; i <= static_cast<int>(CardValue::Ace); i++) {
        for (int j = 0; j <= static_cast<int>(Suit::Spades); j++) {
            cards.push_back(Card(static_cast<CardValue>(i), static_cast<Suit>(j)));       
        }
    }
}

void Deck::shuffle() {
    std::default_random_engine engine(static_cast<unsigned int>(std::time(nullptr)));
    std::shuffle(cards.begin(), cards.end(), engine);
}


Card Deck::drawCard() {
    Card drawnCard = cards.back();
    cards.pop_back();
    return drawnCard;
}

vector<Card> Deck::getCards() {
    return cards;
}