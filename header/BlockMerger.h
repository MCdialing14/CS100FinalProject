#ifndef BLOCKMERGER_H
#define BLOCKMERGER_H

#include "../header/Board.h"
#include "../header/Block.h"

class BlockMerger
{
private:
    Board* board;

public: 
    BlockMerger(Board* board) : board(board) {}

public:
    bool MergeLeft();

private:
    void CombineBlocks(Block* intoBlock, Block* matchingBlock);
};

#endif