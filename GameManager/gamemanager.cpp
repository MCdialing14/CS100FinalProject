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
            if (currentBlock != nullptr) { // a null space can not be merged
                if (prevoiusBlock->GetValue() == currentBlock->GetValue()) {
                    mergePossible = true;
                }
            }
            currentBlock = prevoiusBlock;
        }
    }

    prevoiusBlock = board.GetBlock(Coordinate(x, 0));
    currentBlock = nullptr;
    // loop to find possible vertical merges
    for (int y = 1; y < board.GetSize(); ++y) { // loop to find 2 mergable blocks
        for (int x = 0; x < board.GetSize(); ++x) {
            currentBlock = board.GetBlock(Coordinate(x, y));
            if (currentBlock != nullptr) { // a null space can not be merged
                if (prevoiusBlock->GetValue() == currentBlock->GetValue()) {
                    mergePossible = true;
                }
            }
            currentBlock = prevoiusBlock;
        }
    }

    return boardFull && !mergePossible;
}

Direction GameManager::getInput() { // gets inpupt from the user to determine the direction of the shift
    char userInput = ' ';
    cin >> userInput;
    if (userInput == 'w') {
        return NORTH;
    }
    if (userInput == 'a') {
        return WEST;
    }
    if (userInput == 's') {
        return SOUTH;
    }
    if (userInput == 'd') {
        return EAST;
    }
}

void GameManager::handleLose() {
    cout << "Final score: " << board.GetScore() << endl;
}

void GameManager::performGameLoop() {
    blockSpawner.SpawnBlock();
    updateGameDisplay();
    
    while (!isGameLost()) { // when this loop ends, the player has lost
        bool movePerformed = false;
        while (!movePerformed) {
            movePerformed = blockShifter.PerformMove(getInput()); // changed from .ShiftBlocks
        }

        blockSpawner.SpawnBlock();
        updateGameDisplay();
    }

    handleLose();
}