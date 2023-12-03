#include "MainMenu/menu.hpp"
#include "Settings/settings.hpp"
#include "Credits/credits.hpp"
#include "GameOver/gameover.hpp"
#include <iostream>
#include <string>

using namespace std;

char userChoice;

void callSettings(Settings& gameSettings);
void callCredits(Credits& gameCreds);
void callGameOver(GameOver& gameOverObject);

int main() {
    Menu test;
    Settings tested;
    Credits testing;
    GameOver gameOverObject;

    do {
        test.print();
        cin >> userChoice;
        cin.ignore();

        if(userChoice == 'g') { //game loop
            callGameOver(gameOverObject);
        }
        if(userChoice == 's') { //settings loop
            callSettings(tested);
        }
        if(userChoice == 'c') { //credits
            callCredits(testing);
        }
    } while(userChoice != 'q');

    return 0;
}

void callGameOver(GameOver& gameOverObject) {
    while (userChoice != 'm') {
        gameOverObject.print();
        cin >> userChoice;
        cin.ignore();

        if (userChoice == 'g') { // fix later
            cout << "START NEW GAME HERE!" << endl;
        }
        if (userChoice == 'l') { // fix later
            cout << "PRINT LEADERBOARD HERE!" << endl;
        }
    }
}

void callSettings(Settings& tested) {
    while(userChoice != 'm') {
        tested.print();
        cin >> userChoice;
        cin.ignore();

        if(userChoice == 'v') {
            cout << "Current Volume level: " << tested.getSoundLevel() << endl;
            cout << "New Volume level (0-10): ";
            tested.changeSoundLevel();
            cout << endl;
        }
    }
}

void callCredits(Credits& testing) {
    while(userChoice != 'm') {
        testing.print();
        cin >> userChoice;
        cin.ignore();
    }
}