#include "headers/Game.h"
#include "headers/Deck.h"
#include "headers/Dealer.h"
#include <iostream>


using namespace std;


Game::Game() {
    player = new Player("");
    dealer = new Dealer();
    deck = nullptr;
}

Game::~Game() {
    cleanupDeck();
    delete player;
    delete dealer;
    cout << "DESCTRUCTOR INIT!!!" << endl;
    // Bliver ikke brugt, da Game-instansen aldrig ryger uden for scope
}

void Game::startGame() {
    cout << "------------------------------" << '\n';
    cout << "|    WELCOME TO BLACKJACK    |" << '\n';
    cout << "------------------------------" << '\n';
    cout << "Please write your name and the game will begin" << '\n';
    string name;
    cin >> name;
    player->setName(name);
    cout << "Welcome " << name << "!" << '\n';
    cout << "Press '1' to start the game" << '\n';
    cout << "Press any other button to close the game" << '\n';

    int choice;
    cin >> choice;
    if (choice == 1) {
        playGame();
    } else {
        exit(EXIT_SUCCESS);
    }
}

void Game::playGame() {
    do {
        startRound();
        playerTurn();
        cleanupDeck(); // Deletes the deck after each round
        clearHands(); // Clear hands after each round
    }
    while (playAgain());
}

void Game::startRound() {
    cout << "------------------------------" << '\n';
    cout << "|        ROUND START!        |" << '\n';
    cout << "------------------------------" << '\n';
    cout << "You have $" << player->getBalance() << ", how much do you wanna bet?" << '\n';
    cin >> currentBet;
    if (player->getBalance() < currentBet) currentBet = player->getBalance();

    deck = createDeck();
    dealer->addToHand(deck->drawCard());
    player->addToHand(deck->drawCard());
    player->addToHand(deck->drawCard());

    cout << "Hand of " << player->getName() << ": " << player->showHand() << '\n';
    cout << "Hand of dealer: " << dealer->showHand() << '\n';
}

Deck* Game::createDeck() {
    Deck* deck = new Deck();
    deck->shuffle();

    return deck;
}


bool Game::playAgain() {
    cout << "Do you want to play again? Y or N\n";
    char playAgain;
    cin >> playAgain;
    return playAgain == 'Y';
}

/**
 * Player can choose whether to hit or to stand based on the cards he has already.
*/
void Game::playerTurn() {
    cout << "Hit: 1" << '\n';
    cout << "Stand: 2" << '\n';
    int choice;
    cin >> choice;

    if (choice == 1) {
        hit(*player);
        cout << "Your hand: " << player->showHand() << '\n';
        if (player->getHandValue() >= 21) {
            checkWinner();
        } else playerTurn();
    } else {
        dealerTurn();
    }
}


void Game::dealerTurn() {
    while (dealer->getHandValue() < 17) {
        hit(*dealer);
        cout << "Dealers hand: " << dealer->showHand() << '\n';
    }
    checkWinner();
}

void Game::hit(Participant& participant) {
    Card card = deck->drawCard();
    participant.addToHand(card);
    cout << "Card drawn: " << card.toString() << '\n';
}

Participant* Game::checkWinner() {
    int playerHandValue = player->getHandValue();
    int dealerHandValue = dealer->getHandValue();

    if (playerHandValue > 21) {
        cout << "You lose!" << '\n';
        player->adjustBalance(-currentBet);
        return dealer;
    }

    if (dealerHandValue > 21) {
        cout << "You win!" << '\n';
        player->adjustBalance(currentBet);
        return player;
    }

    if (playerHandValue > dealerHandValue) {
        player->adjustBalance(currentBet);
        cout << "You win!" << '\n';
        return player;
    }

    if (dealerHandValue > playerHandValue) {
        player->adjustBalance(-currentBet);
        cout << "You lose!" << '\n';
        return dealer;
    }

    cout << "Draw!" << '\n';
    return nullptr;
}

void Game::setCurrentBet(int amount) {
    currentBet = amount;
}

void Game::cleanupDeck() {
    if (deck) {
        delete deck;
        deck = nullptr;
    }
}

void Game::clearHands() {
    player->clearHand();
    dealer->clearHand();
}