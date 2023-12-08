#include "../header/BlockMerger.h"
#include "../header/Board.h"
#include "../header/Block.h"
#include "../header/Coordinate.h"
#include <stdexcept>
#include <iostream>

/// @brief Merges all blocks with the block to their left 
bool BlockMerger::MergeLeft()
{
    bool mergeOccured = false;

    for (int y = 0; y < board->GetSize(); y++)
    {
        for (int x = 1; x < board->GetSize(); x++)
        {
            Coordinate currentCoord = Coordinate(x, y);
            Block* previousBlock = board->GetBlock(Coordinate(x - 1, y));
            Block* currentBlock = board->GetBlock(currentCoord);
            if (previousBlock != nullptr && currentBlock != nullptr)
            {
                if (previousBlock->GetValue() == currentBlock->GetValue())
                {
                    CombineBlocks(previousBlock, currentBlock);
                    board->SetBlock(nullptr, currentCoord);

                    mergeOccured = true;
                }
            }
        }
    }    

    return mergeOccured;
}

/// @brief Combines the values of 2 blocks and deletes the matching one.
void BlockMerger::CombineBlocks(Block *intoBlock, Block *matchingBlock)
{
    if (intoBlock->GetValue() != matchingBlock->GetValue())
    {
        throw std::runtime_error("Cannot combine blocks whose values do not match.");
    }
    
    intoBlock->AddValue(matchingBlock->GetValue());
    delete matchingBlock;
}
