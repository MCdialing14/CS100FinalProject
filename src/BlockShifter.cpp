#include "../header/BlockShifter.h"

#include <vector>

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

        // replace rest of row with nullptr
        for (auto i = nonNullBlocks.size(); i < board->GetSize(); i++)
        {
            board->SetBlock(nullptr, Coordinate(i, y));
        }
    }

    return rowShifted;
}

/// @brief Returns whether a left shift is possible for the given row index
bool BlockShifter::IsLeftShiftPossible(int row)
{
    for (int x = 1; x < board->GetSize(); x++)
    {
        Block* previousBlock = board->GetBlock(Coordinate(x - 1, row));
        Block* currentBlock = board->GetBlock(Coordinate(x, row));
        if (previousBlock == nullptr && currentBlock != nullptr)    // try to find a block with an empty space before it
        {
            return true;
        }
    }

    return false;
}
