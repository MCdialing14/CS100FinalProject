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

const int SIZE = 4;
string namesArray[SIZE];
int scoresArray[SIZE];
int count = 0;

Menu test;
Settings tested;
Credits testing; 
GameOver tester;

void callMenu(Menu& gameMenu);
void callSettings(Settings& gameSettings);
void callCredits(Credits& gameCreds);
void callGame();
void callGameOver(GameOver& gameEnd);
void callLeaderboard();

int main() {   
    callMenu(test);
    return 0;
}

void callMenu(Menu& test) {
    do {
        test.print();
        cin >> userChoice;
        cin.ignore();

        if(userChoice == 'g') {
            callGame();
            callGameOver(tester);
        }
        if(userChoice == 's') { //settings loop
            callSettings(tested);
        }
        else if(userChoice == 'c') { //credits
            callCredits(testing);
        }
        else if(userChoice == 'l') { //leaderboard
            callLeaderboard();
        }
        else if(userChoice == 'q') {
            break;
        }
        else {
            cout << "Invalid input!" << endl << endl;
        }
    } while(userChoice != 'q');
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

        else if(userChoice == 'e') {
            cout << "Current sound effects: ";
            if(tested.getSoundEffect() == false) {
                cout << "OFF" << endl;
            }
            else {
                cout << "ON" << endl;
            }
            cout << "Switch? Yes - 1 No - 0:  ";
            tested.changeEffects();
            cout << endl;
        }
        else if(userChoice == 'o') {
            cout << "Settings back to default!" << endl;
            tested.changeToDefault();
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

void callGame() {
    cout << "In game, enter score to test game over/leaderboard" << endl;
    cin >> testScore;
    cin.ignore();
}

void callGameOver(GameOver& tester) {
    while(userChoice != 'm') {
        tester.print();
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
            callCredits(testing);
        }
    }
    callMenu(test);
}