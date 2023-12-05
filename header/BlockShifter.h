#ifndef BLOCKSHIFTER_H
#define BLOCKSHIFTER_H

#include "Board.h"
#include "Block.h"

enum Direction
{
    NORTH,
    EAST,
    SOUTH,
    WEST
};

class BlockShifter
{
private:
    Board* board;

public: 
    BlockShifter(Board* board) : board(board) {}
    bool PerformMove(Direction direction);

private:
    bool PerformMoveHelper();
    void CombineBlocks(Block* intoBlock, Block* matchingBlock);
    void RotateBoard();
    bool ShiftLeft();
    bool IsLeftShiftPossible(int row);
    bool MergeLeft();
};

#endif // !BLOCKSHIFTER_H