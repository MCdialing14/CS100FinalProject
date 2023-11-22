#include "settings.hpp"

void Settings::getInput() {
    cin >> userInputChar;
}

char Settings::returnInput() {
    return userInputChar;
}

void Settings::print() {
    cout << settingsDisplay << endl;
    getInput();
}

string Settings::getSettingsDisplay() { // for testing
    return this->settingsDisplay;
}

void Settings::changeSoundLevel() {
    cin >> userInputInt;
    this->soundLevel = userInputInt;
    return;
}

void Settings::changeEffects() {
    this->soundEffects = 0; //hard coded value for testing
    return;
}

//for testing
int Settings::getSoundLevel() {
    return this->soundLevel;
}

int Settings::getSoundEffect() {
    return this->soundEffects;
}