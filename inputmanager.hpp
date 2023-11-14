#ifndef INPUTMANAGER_HPP
#define INPUTMANAGER_HPP
#include <string>
#include <iostream>

class InputManager {
    protected:
        char userInputChar;
        int userInputInt;
    public:
        virtual void getInput() = 0;
};

#endif