#ifndef BLOCKSHIFTER_H
#define BLOCKSHIFTER_H

#include "../header/Board.h"

class BlockShifter
{
private:
    Board* board;

public: 
    BlockShifter(Board* board) : board(board) {}
    bool ShiftLeft();
    bool IsLeftShiftPossible(int row);
};

#endif // !BLOCKSHIFTER_H