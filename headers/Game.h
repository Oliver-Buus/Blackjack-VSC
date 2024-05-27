#ifndef GAME_H
#define GAME_H

#include "Participant.h"
#include "Player.h"
#include "Dealer.h"
#include "Deck.h"

class Game {
private:
    Player* player;
    Dealer* dealer;
    Deck* deck;
    int currentBet;

public:
    Game();
    ~Game();

    void startGame();
    void playGame();
    void startRound();
    bool playAgain();
    Deck* createDeck();
    void hit(Participant& Participant);
    void playerTurn();
    void dealerTurn();
    Participant* checkWinner();
    void setCurrentBet(int amount);

    void cleanupDeck();
    void clearHands();
};









#endif