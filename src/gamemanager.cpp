#include "../header/gamemanager.hpp"

GameManager::GameManager() {
    board = new Board();
    blockMover = new BlockMover(board);
    blockSpawner = new BlockSpawner(board);
}

GameManager::~GameManager() {
    delete board;
    delete blockMover;
    delete blockSpawner;
}

void GameManager::updateGameDisplay() {
    Block *blockPointer;
    for (int row = 0; row < 4; ++row) { 
        for (int column = 0; column < 4; ++column) {
            blockPointer = board->GetBlock(Coordinate(row, column));
            if (blockPointer == nullptr) {
                cout << "x ";
            }
            else {
                cout << blockPointer->GetValue() << " ";
            }
        }
        cout << endl;
    }
}

bool GameManager::isGameLost() { // returns true if the player lost, otherwise returns false
    bool boardFull = board->IsBoardFull();
    bool mergePossible = false;

    // loop to find possible horizontal merges
    for (int y = 0; y < board->GetSize(); y++)
    {
        Block* previousBlock = board->GetBlock(Coordinate(0, y));
        for (int x = 1; x < board->GetSize(); x++)
        {
            Block* currentBlock = board->GetBlock(Coordinate(x, y));
            if (previousBlock != nullptr && currentBlock != nullptr)
            {
                if (previousBlock->GetValue() == currentBlock->GetValue())
                {
                    mergePossible = true;
                }
            }
        }
    }    

    // loop to find possible vertical merges
    for (int x = 0; x < board->GetSize(); x++)
    {
        Block* previousBlock = board->GetBlock(Coordinate(x, 0));
        for (int y = 1; y < board->GetSize(); y++)
        {
            Coordinate currentCoord = Coordinate(x, y);
            Block* currentBlock = board->GetBlock(currentCoord);
            if (previousBlock != nullptr && currentBlock != nullptr)
            {
                if (previousBlock->GetValue() == currentBlock->GetValue())
                {
                    mergePossible = true;
                }
            }
        }
    }    

    return boardFull && !mergePossible;
}

Direction GameManager::getInput() { // gets input from the user to determine the direction of the shift
    char userInput = ' ';
    while (userInput != 'w' || userInput != 'a' || userInput != 's' || userInput != 'd') {
        cin >> userInput;
        if (userInput == 'w') {
        return NORTH;
        }
        else if (userInput == 'a') {
            return WEST;
        }
        else if (userInput == 's') {
            return SOUTH;
        }
        else if (userInput == 'd'){
            return EAST;
        }
    }
}

void GameManager::handleLose() {
    cout << "Final score: " << board->GetScore() << endl;

}

void GameManager::performGameLoop() {
    blockSpawner->SpawnBlock();
    updateGameDisplay();
    
    while (!isGameLost()) { // when this loop ends, the player has lost
        bool movePerformed = false;
        while (!movePerformed) {
            movePerformed = blockMover->PerformMove(getInput());
        }

        blockSpawner->SpawnBlock();
        updateGameDisplay();
    }

    handleLose();
}