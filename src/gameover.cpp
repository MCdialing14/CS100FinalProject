#include "../header/gameover.hpp"

void GameOver::print() {
    cout << overDisplay << endl;
}

string GameOver::getOverDisplay() { // for testing
    return this->overDisplay;
}