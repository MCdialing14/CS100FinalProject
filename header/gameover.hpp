#ifndef GAMEOVER_HPP
#define GAMEOVER_HPP
#include <string>
#include <iostream>

using namespace std;

class GameOver {
    private:
        string overDisplay = "\nGAME OVER \n \n New Game - g \n Add score on leaderboard - l \n Main Menu - m"; // change to print final score
    public:
        void print();
        string getOverDisplay(); // for testing
};

#endif