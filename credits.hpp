#ifndef CREDITS_HPP
#define CREDITS_HPP
#include <string>
#include <iostream>
#include "inputmanager.hpp"

using namespace std;

class Credits {
    private:
        string creditDisplay = "\nCREDITS \n \n Mark Sapugay - Leaderboard \n Michael Carlin - Main Menu and Game Over \n Niko Udria - Board, Blocks, and Game Management \n Matthew Cedeno - Settings and Credits \n \n Main Menu - m";
    public:
        void print();
        string getCreditDisplay(); // for testing
};

#endif