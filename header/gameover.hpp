#ifndef GAMEOVER_HPP
#define GAMEOVER_HPP
#include <string>
#include <iostream>
#include "../inputmanager.hpp"

using namespace std;

class GameOver : public InputManager {
    private:
        string overDisplay = "Game Over \n \n New Game - g \n Leaderboard - l \n Main Menu - m"; // change to print final score
    public:
        void print();
        void getInput();
        char returnInput();
        string getOverDisplay(); // for testing
};

#endif