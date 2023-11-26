#include "MainMenu/menu.hpp"
#include "gameover.hpp"
#include <iostream>
#include <string>

using namespace std;

void callGameOver(GameOver &gameOverObject);

int main() {
    Menu testMenu;
    GameOver testGameOver;

    while(testMenu.returnInput() != 'q') {
        testMenu.print();
        cin.ignore();

        if(testMenu.returnInput() == 'g') { // player starts a new game
            callGameOver(testGameOver);
        }
    }

    return 0;
}

void callGameOver(GameOver &gameOverObject) { // FIX
    while((gameOverObject.returnInput() != 'g') && (gameOverObject.returnInput() != 'l') && (gameOverObject.returnInput() != 'm')) { // g = new game, l = leaderboard, m = main menu
        gameOverObject.print();
    }
}