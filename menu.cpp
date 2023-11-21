#include "menu.hpp"

void Menu::print(string &menuDisplay) {
    cout << menuDisplay << endl;
    getInput();
}

void Menu::getInput() {
    cin >> userInputChar;
}

string Menu::getMenuDisplay() { // for testing
    return this->menuDisplay;
}