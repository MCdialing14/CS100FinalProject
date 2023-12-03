#ifndef MENU_HPP
#define MENU_HPP
#include <string>
#include <iostream>
#include "inputmanager.hpp"

using namespace std;

class Menu : public InputManager {
    private:
        string menuDisplay = "2048 \n \n Start Game - g \n Settings - s \n Leaderboard - b \n Credits - c \n Quit - q";
    public:
        void print();
        void getInput();
        char returnInput();
        void clearInput();
        string getMenuDisplay(); // for testing
};

#endif