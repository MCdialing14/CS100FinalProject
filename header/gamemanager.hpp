#ifndef GAMEMANAGER_HPP
#define GAMEMANAGER_HPP
#include <string>
#include <iostream>
#include "../header/Board.h"
#include "../header/BlockSpawner.h"
#include "../header/BlockMover.h"

using namespace std;

class GameManager {
    private:
        Board *board;
        BlockMover *blockMover;
        BlockSpawner *blockSpawner;

    public:
        Direction getInput();
        GameManager();
        ~GameManager();
        void performGameLoop();
        bool isGameLost();
        void handleLose(); // prints final score and gives options to navigate menus
        void updateGameDisplay();
};

#endif