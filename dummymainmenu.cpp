#include "dummymainmenu.hpp"

void Menu::print() {
    cout << menuDisplay << endl;
    //getInput();
}

void Menu::getInput() {
    cin >> userInputChar;
    cin.ignore();
}

char Menu::returnInput() {
    return userInputChar;
}

void Menu::clearInput() {
    userInputChar = '0';
}

string Menu::getMenuDisplay() { // for testing
    return this->menuDisplay;
}