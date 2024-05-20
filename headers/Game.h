#ifndef GAME_H
#define GAME_H

#include "Player.h"
class Game {
private:
    Player player;

public:
    Game();

    void startGame();
    void startRound();
    void hit();
};









#endif