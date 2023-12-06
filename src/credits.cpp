#include "../header/credits.hpp"

void Credits::print() {
    cout << creditDisplay << endl;
    //getInput();
}

void Credits::getInput() {
    cin >> userInputChar;
}

char Credits::returnInput() {
    return userInputChar;
}

string Credits::getCreditDisplay() { // for testing
    return this->creditDisplay;
}