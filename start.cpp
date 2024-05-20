#include "headers/Card.h"
#include "headers/Deck.h"
#include "headers/Player.h"
#include "headers/Game.h"
#include <iostream>

using namespace std;

int main() {
    Player player {"Oliver"};
    Card card {CardValue::Four, Suit::Clubs};
    cout << card << '\n';
    Game game;
    game.startGame();
    

    Deck deck;
    deck.shuffle();
    Card c1 = deck.drawCard();
    cout << c1 << '\n';
    cout << c1.getValueAmount() << '\n';
    player.addToHand(c1);
    Card c2 = deck.drawCard();
    cout << c2 << '\n';

    player.addToHand(c2);
    cout << "HandValue: " << player.getHandValue() << '\n';

    cout << "Your hand is now: " << player.showHand();

    return 0;
}