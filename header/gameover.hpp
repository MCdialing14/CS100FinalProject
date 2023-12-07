#ifndef GAMEOVER_HPP
#define GAMEOVER_HPP
#include <string>
#include <iostream>
#include "../header/inputmanager.hpp"

using namespace std;

class GameOver : public InputManager {
    private:
        string overDisplay = "\n \n \n \n \n \n \n \n \nGAME OVER \n \n New Game - g \n Add score on leaderboard - l \n Main Menu - m"; // change to print final score
    public:
        void print();
        void getInput();
        char returnInput();
        string getOverDisplay(); // for testing
};

#endif