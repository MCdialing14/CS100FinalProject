#include "dummymainmenu.hpp"
#include "settings.hpp"
#include "credits.hpp"
#include <iostream>
#include <string>

using namespace std;

void callSettings(Settings& gameSettings);
void callCredits(Credits& gameCreds);

int main() {
    Menu test;
    Settings tested;
    Credits testing;

    while(test.returnInput() != 'q') {
        test.print();
        cin.ignore();

        if(test.returnInput() == 's') { //settings loop
            callSettings(tested);
        }
        if(test.returnInput() == 'c') {
            callCredits(testing);
        }
    }

    return 0;
}

void callSettings(Settings& tested) {

    while(tested.returnInput() != 'q') {
        tested.print();

        if(tested.returnInput() == 'v') {
            cout << "Current Volume level: " << tested.getSoundLevel() << endl;
            cout << "New Volume level (0-10): ";
            tested.changeSoundLevel();
            cout << endl;
        }
    }
}

void callCredits(Credits& testing) {
    while(testing.returnInput() != 'q') {
        testing.print();
    }
}