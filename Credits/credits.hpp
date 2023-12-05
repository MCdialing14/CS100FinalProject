#ifndef CREDITS_HPP
#define CREDITS_HPP
#include <string>
#include <iostream>
#include "../inputmanager.hpp"

using namespace std;

class Credits : public InputManager {
    private:
        string creditDisplay = "CREDITS \n \n Mark Sapugay - Leaderboard \n Michael Carlin - Main Menu and Game Over \n Niko Udria - Board, Blocks, and Game Management \n Matthew Cedeno - Settings and Credits \n \n Main Menu - m";
    public:
        void print();
        void getInput();
        char returnInput();
        string getCreditDisplay(); // for testing
};

#endif