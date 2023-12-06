#ifndef BLOCKMOVER_H
#define BLOCKMOVER_H

#include "Board.h"
#include "BlockShifter.h"
#include "BlockMerger.h"


enum Direction
{
    NORTH,
    EAST,
    SOUTH,
    WEST
};

class BlockMover
{
private:
    Board* board;
    BlockShifter* blockShifter;
    BlockMerger* blockMerger;

public:
    BlockMover(Board* board);
    ~BlockMover();
    bool PerformMove(Direction direction);
    void RotateBoard();

private:
    bool PerformMoveHelper();
};

#endif