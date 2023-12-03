#include "dummymainmenu.hpp"
#include "settings.hpp"
#include "credits.hpp"
#include <iostream>
#include <string>

using namespace std;

char userChoice;

void callSettings(Settings& gameSettings);
void callCredits(Credits& gameCreds);

int main() {
    Menu test;
    Settings tested;
    Credits testing;

    do {
        test.print();
        cin >> userChoice;
        cin.ignore();

        if(userChoice == 's') { //settings loop
            callSettings(tested);
        }
        else if(userChoice == 'c') { //credits
            callCredits(testing);
        }
    } while(userChoice != 'q');

    return 0;
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