#ifndef GAMEOVER_HPP
#define GAMEOVER_HPP
#include <string>
#include <iostream>
#include "inputmanager.hpp"

using namespace std;

class GameOver : public InputManager {
    private:
        string overDisplay = "Game Over \n \n New Game \n Leaderboard \n Leaderboard \n Main Menu"; // change to print final score
    public:
        void print();
        void getInput();
        char returnInput();
        string getOverDisplay(); // for testing
};

#endif