#ifndef GAMEOVER_HPP
#define GAMEOVER_HPP
#include <string>
#include <iostream>
#include "inputmanager.hpp"

using namespace std;

class GameOver : public InputManager {
    private:
        string overDisplay = "\nGame Over \n \n New Game - g \n Add score on leaderboard - l \n Main Menu - m"; // change to print final score
    public:
        void print();
        void getInput();
        char returnInput();
        string getOverDisplay(); // for testing
};

#endif