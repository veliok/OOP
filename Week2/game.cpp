#include "game.h"
#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

Game::Game(int max) {
    maxNumber = max;
    cout << "GAME CONSTRUCTOR: object initialized with "
         << maxNumber << " as a maximum value" << endl;
}

Game::~Game() {
    cout << "GAME DESTRUCTOR: object cleared from stack memory";
}

void Game::play() {
    srand(time(0));
    randomNumber = rand() % maxNumber + 1;
    bool inLoop = true;
    while(inLoop) {
        cout << "Give your guess between 1-" << maxNumber << endl;
        cin >> playerGuess;

        numOfGuesses++;

        if(playerGuess == randomNumber) {
            cout << "Your guess is right" << endl;
            printGameResult();
            inLoop = false;
        }
        else if(playerGuess < randomNumber) {
            cout << "Your guess is too small" << endl;
        }
        else {
            cout << "Your guess too big" << endl;
        }
    }
}

void Game::printGameResult() {
    cout << "You guessed the right answer = " << randomNumber << " with "
         << numOfGuesses << " guesses" << endl;
}
