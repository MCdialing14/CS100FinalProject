#include "gamemanager.hpp"

void GameManager::updateGameDisplay() {
    Block *blockPointer;
    for (int row = 0; row < 4; ++row) { 
        for (int column = 0; column < 4; ++column) {
            blockPointer = board.GetBlock(row, column);
            if (blockPointer == nullptr) {
                cout << "x "
            }
            else {
                cout << blockPointer->GetValue(); << " ";
            }
        }
        cout << endl;
    }
}

bool GameManager::isGameLost() { // returns true if the player lost, otherwise returns false
    bool boardFull = board.IsBoardFull();
    bool mergePossible = false;

    Block *prevoiusBlock = board.GetBlock(Coordinate(0, y));
    Block *currentBlock == nullptr;
    // loop to find possible horizontal merges
    for (int x = 1; x < board.GetSize(); ++x) { // loop to find 2 mergable blocks
        for (int y = 0; y < board.GetSize(); ++y) {
            currentBlock = board.GetBlock(Coordinate(x, y));
            if (!(currentBlock == nullptr)) { // go through the different cases of checking blocks
                if (prevoiusBlock->GetValue() == currentBlock->GetValue()) {
                    mergePossible = true;
                }
            }
            currentBlock = prevoiusBlock;
        }
    }

    // loop to find possible vertical merges


    return boardFull && !mergePossible;
}

void GameManager::performGameLoop() {
    blockSpawner.SpawnBlock();
    updateGameDisplay();
    
    while (!isGameLost()) {
        bool movePerformed = false;
        while (!movePerformed) {
            movePerformed = blockShifter.ShiftBlocks(getInput());
        }

        blockSpawner.SpawnBlock();
        updateGameDisplay();
    }

    handleLose();
}