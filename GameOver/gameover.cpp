#include "gameover.hpp"

void GameOver::print() {
    cout << overDisplay << endl;
    // getInput();
}

void GameOver::getInput() {
    cin >> userInputChar;
}

char GameOver::returnInput() {
    return userInputChar;
}

string GameOver::getOverDisplay() { // for testing
    return this->overDisplay;
}