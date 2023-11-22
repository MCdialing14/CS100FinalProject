#include "dummymainmenu.hpp"

void Menu::print() {
    cout << menuDisplay << endl;
    getInput();
}

void Menu::getInput() {
    cin.clear();
    cin >> userInputChar;
}

char Menu::returnInput() {
    return userInputChar;
}

void Menu::clearInput() {
    userInputChar = 'z';
}

string Menu::getMenuDisplay() { // for testing
    return this->menuDisplay;
}