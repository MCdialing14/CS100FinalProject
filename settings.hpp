#ifndef SETTINGS_HPP
#define SETTINGS_HPP
#include <string>
#include <iostream>
#include "inputmanager.hpp"

using namespace std;

class Settings : public InputManager {
    private:
        string settingsDisplay = "\nEnter letter to change setting: \n Volume - v \n Sound Effects - e \n \n Default - o \n Main Menu - m";
        int soundLevel = 5; //default value 1-10 levels
        bool soundEffects = true; //default value 1-On 0-Off

    public:
        void getInput();
        char returnInput();
        void print();
        string getSettingsDisplay(); //for testing
        void changeSoundLevel();
        void changeEffects();

        //for testing
        int getSoundLevel();
        bool getSoundEffect();
};

#endif