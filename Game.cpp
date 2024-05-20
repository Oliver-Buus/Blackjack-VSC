#include "headers/Game.h"

using namespace std;


Game::Game()
    : player("") {

}


void Game::startGame() {
    cout << "------------------------------" << '\n';
    cout << "|    WELCOME TO BLACKJACK    |" << '\n';
    cout << "------------------------------" << '\n';
    cout << "Please write your name and the game will begin" << '\n';
    string name;
    cin >> name;
    player.setName(name);
    cout << "Welcome " << name << "!" << '\n';
    cout << "Press '1' to start the game" << '\n';
    cout << "Press any other button to close the game" << '\n';

    int choice;
    cin >> choice;
    if (choice == 1) {
        startRound();
    } else {
        exit(EXIT_SUCCESS);
    }
}

void Game::startRound() {
    cout << "------------------------------" << '\n';
    cout << "|        ROUND START!        |" << '\n';
    cout << "------------------------------" << '\n';
    cout << "You have $" << player.getBalance() << ", how much do you wanna bet?";
    int bet;
    cin >> bet;
    if (player.getBalance() < bet) bet = player.getBalance();

    // Der skal laves et deck af kort, som skal shuffles. Husk at bruge pointers, så decket kan fjernes efter hver runde.
    // Dealeren skal trække 1 kort og player får 2
    // Spilleren skal så have mulighed for at hitte. Hvis man rammer over 21 og har en Ace, så bliver værdien af Acen ændret fra 11 til 1.
    // Når spilleren er færdig med at 'hit' så trækker dealeren indtil denne er på 17 eller derover.
    // Derefter finder man ud af hvem der har vundet, Player eller Dealer og Player får tilføjet $ til sin balance hvis den vinder.
    // Spilleren bliver derefter promptet til at kunne spille igen.

    

}