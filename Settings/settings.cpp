#include "settings.hpp"

void Settings::getInput() {
    cin >> userInputChar;
    cin.ignore();
}

char Settings::returnInput() {
    return userInputChar;
}

void Settings::print() {
    cout << settingsDisplay << endl;
    //getInput();
}

string Settings::getSettingsDisplay() { // for testing
    return this->settingsDisplay;
}

void Settings::changeSoundLevel() {
    cin >> userInputInt;
    cin.clear();
    cin.ignore(256, '\n');

    if(userInputInt < 0) {
        this->soundLevel = 0;
    }
    else if(userInputInt > 10) {
        this->soundLevel = 10;
    }
    else {
        this->soundLevel = userInputInt;
    }
    return;
}

void Settings::changeEffects() {
    cin >> userInputInt;

    if(userInputInt == 1) {
        this->soundEffects = !(soundEffects);
    }
    else if (userInputInt == 0) {
        return;
    }
    return;
}

//for testing
int Settings::getSoundLevel() {
    return this->soundLevel;
}

bool Settings::getSoundEffect() {
    return this->soundEffects;
}