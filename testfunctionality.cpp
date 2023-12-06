#include "dummymainmenu.hpp"
#include "settings.hpp"
#include "credits.hpp"
#include "gameover.hpp"
#include "functions.h"
#include <iostream>
#include <string>

using namespace std;

char userChoice;
string userName;
int testScore;

const int SIZE = 5;
string namesArray[SIZE];
int scoresArray[SIZE];
int count = 0;

Menu gameMenu;
Settings gameSettings;
Credits gameCredits; 
GameOver gameEnd;

void callMenu(Menu& gameMenu);
void callSettings(Settings& gameSettings);
void callCredits(Credits& gameCredits);
void callGame();
void callGameOver(GameOver& gameEnd);
void callLeaderboard();

int main() {   
    callMenu(gameMenu);
    return 0;
}

void callMenu(Menu& gameMenu) {
    do {
        gameMenu.print();
        cin >> userChoice;
        cin.ignore();

        if(userChoice == 'g') {
            while(userChoice != 'm') {
                callGame();
                callGameOver(gameEnd);
            }
        }
        if(userChoice == 's') { //settings loop
            callSettings(gameSettings);
        }
        else if(userChoice == 'c') { //credits
            callCredits(gameCredits);
        }
        else if(userChoice == 'l') { //leaderboard
            callLeaderboard();
        }
        else if(userChoice == 'q') {
            break;
        }
        else if(userChoice == 'm') {
            cout << "Back to Main Menu!" << endl;
        }
        else {
            cout << "Invalid input!" << endl << endl;
        }
    } while(userChoice != 'q');
}

void callSettings(Settings& gameSettings) {

    while(userChoice != 'm') {
        gameSettings.print();
        cin >> userChoice;
        cin.ignore();

        if(userChoice == 'v') {
            cout << "Current Volume level: " << gameSettings.getSoundLevel() << endl;
            cout << "New Volume level (0-10): ";
            gameSettings.changeSoundLevel();
            cout << endl;
        }

        else if(userChoice == 'e') {
            cout << "Current sound effects: ";
            if(gameSettings.getSoundEffect() == false) {
                cout << "OFF" << endl;
            }
            else {
                cout << "ON" << endl;
            }
            cout << "Switch? Yes - 1 No - 0:  ";
            gameSettings.changeEffects();
            cout << endl;
        }
        else if(userChoice == 'o') {
            cout << "Settings back to default!" << endl;
            gameSettings.changeToDefault();
        }
    }
}

void callCredits(Credits& gameCredits) {
    while(userChoice != 'm') {
        gameCredits.print();
        cin >> userChoice;
        cin.ignore();

        if(userChoice == 'm') {
            return;
        }
    }
}

void callGame() {
    cout << "\n \n \n \n \n \n \n \n \nIN GAME, enter score to test game over/leaderboard" << endl;
    cout << "Main Menu - m" << endl;
    cout << "Enter trash char to continue, 'm' to main menu: ";
    cin >> userChoice;
    cin.ignore();
    if(userChoice == 'm') {
        return;
    }
    cout << "Enter test score: ";
    cin >> testScore;
    cin.ignore();
}

void callGameOver(GameOver& gameEnd) {
    while(userChoice != 'm') {
        gameEnd.print();
        cin >> userChoice;
        cin.ignore();

        if(userChoice == 'g') {
            callGame();
        }
        else if(userChoice == 'l') {
            cout << "Enter your name onto leaderboard!" << endl;
            cin >> userName;
            addScore(namesArray, scoresArray, count, SIZE, userName, testScore);
            callLeaderboard();
        }
        else if(userChoice == 'm') {
            break;
        }
        else {
            cout << "Invalid input!" << endl << endl;
        }
    }
}

void callLeaderboard() {
    while(userChoice != 'm') {
        displayScores(namesArray, scoresArray, count);
        
        if(is_Empty(namesArray)) {
            cout << "No scores yet!" << endl;
        }

        cout << endl << "Credits - c" << endl;
        cout << "Menu - m" << endl;

        cin >> userChoice;
        cin.ignore();

        if(userChoice == 'c') {
            callCredits(gameCredits);
        }
        if(userChoice == 'm') {
            return;
        }
    }
}