#ifndef MENU_HPP
#define MENU_HPP
#include <string>
#include <iostream>
#include "../header/inputmanager.hpp"

using namespace std;

class Menu {
    private:
        string menuDisplay = "\n \n \n \n \n \n \n \n \n2048 \n \n Start Game - g \n Settings - s \n Leaderboard - l \n Credits - c \n Quit - q";
    public:
        void print();
        string getMenuDisplay(); // for testing
};

#endif