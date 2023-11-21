#include "settings.hpp"

void Settings::getInput() {
    cin >> userInputChar;
}

void Settings::print(string &settingsDisplay) {
    cout << settingsDisplay << endl;
    getInput();
}

string Settings::getSettingsDisplay() { // for testing
    return this->settingsDisplay;
}

void Settings::changeSoundLevel() {
    this->soundLevel = 3; //hard coded value for testing
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