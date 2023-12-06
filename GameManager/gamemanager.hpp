#ifndef GAMEMANAGER_HPP
#define GAMEMANAGER_HPP
#include <string>
#include <iostream>
#include "header/Board.h"
#include "header/BlockSpawner.h"
#include "header/BlockShifter.h"

using namespace std;

class GameManager {
    private:
        Board board;
        BlockShifter blockShifter;
        BlockSpawner blockSpawner;

    public:
        Direction getInput();
        void performGameLoop();
        bool isGameLost();
        void handleLose(); // prints final score and gives options to navigate menus
        void updateGameDisplay();
};

#endif