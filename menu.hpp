#ifndef MENU_HPP
#define MENU_HPP
#include <string>
#include <iostream>

using namespace std;

class InputManager {
    protected:
        char userInputChar;
        int userInputInt;
    public:
        virtual void getInput() = 0;
};

class Menu : public InputManager {
    private:
        string menuDisplay = "2048 \n \n Start Game \n Settings \n Leaderboard \n Quit";
    public:
        void print(string &menuDisplay);
        void getInput();
        string getMenuDisplay(); // for testing
};

#endif