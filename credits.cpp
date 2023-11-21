#include "credits.hpp"

void Credits::print(string &creditDisplay) {
    cout << creditDisplay << endl;
    getInput();
}

void Credits::getInput() {
    cin >> userInputChar;
}

string Credits::getCreditDisplay() { // for testing
    return this->creditDisplay;
}