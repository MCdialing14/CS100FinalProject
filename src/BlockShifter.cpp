#include "../header/BlockShifter.h"
#include "../header/Block.h"

#include <stdexcept>
#include <vector>

/// <summary>
/// Attempts to move all blocks to the direction provided, combining or colliding them along the way.
/// </summary>
/// <param name="direction"> The direction to shift the blocks in. </param>
/// <returns>
/// Returns true if it was able to successfully move/ combine at least one block
/// Returns false if nothing changed meaning it was an invalid move
/// </returns>
bool BlockShifter::ShiftBlocks(Direction direction)
{
    bool movedOrCombined = false;

    switch (direction)
    {
        case Direction::NORTH:
            
            break;
        case Direction::EAST:

            break;
        case Direction::SOUTH:
            break;
        case Direction::WEST:
            break;
        default:
            throw std::invalid_argument("Unrecognized Direction enum value");
    }
    return movedOrCombined;
}

//-- HELPERS

/// @brief Shifts all blocks in all rows to the left. Returns whether a shift occurred as a bool.
bool BlockShifter::ShiftLeft()
{
    bool rowShifted = false;

    for (int y = 0; y < board->GetSize(); y++)
    {
        rowShifted = rowShifted || IsLeftShiftPossible(y);

        // create ordered vector of non null blocks on the row
        std::vector<Block*> nonNullBlocks;
        for (int x = 0; x < board->GetSize(); x++)
        {
            Block* currentBlock = board->GetBlock(Coordinate(x, y));
            if (currentBlock != nullptr)
            {
                nonNullBlocks.push_back(currentBlock);
            }
        }

        // replace the row with the ordered vector
        for (auto i = 0; i < nonNullBlocks.size(); i++)
        {
            Coordinate currentCoord = Coordinate(i, y);
            board->SetBlock(nonNullBlocks.at(i), currentCoord);
        }
    }

    return rowShifted;
}

/// @brief Returns whether a left shift is possible for the given row index
bool BlockShifter::IsLeftShiftPossible(int row)
{
    Block* previousBlock = board->GetBlock(Coordinate(0, row));
    for (int x = 1; x < board->GetSize(); x++)
    {
        Block* currentBlock = board->GetBlock(Coordinate(x, row));
        if (previousBlock == nullptr && currentBlock != nullptr)    // try to find a block with an empty space before it
        {
            return true;
        }
    }

    return false;
}

/// @brief Merges all blocks with the block to their left 
bool BlockShifter::MergeLeft()
{
    bool mergeOccured = false;

    for (int y = 0; y < board->GetSize(); y++)
    {
        Block* previousBlock = board->GetBlock(Coordinate(0, y));
        for (int x = 1; x < board->GetSize(); x++)
        {
            Coordinate currentCoord = Coordinate(x, y);
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
void BlockShifter::CombineBlocks(Block *intoBlock, Block *matchingBlock)
{
    if (intoBlock->GetValue() != matchingBlock->GetValue())
    {
        throw std::runtime_error("Cannot combine blocks whose values do not match.");
    }
    
    intoBlock->AddValue(matchingBlock->GetValue());
    delete matchingBlock;
}
