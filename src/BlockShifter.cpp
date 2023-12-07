#include "../header/BlockShifter.h"

#include <vector>

/// @brief Shifts all blocks in all rows to the left. Returns whether a shift occurred as a bool.
bool BlockShifter::ShiftLeft()
{
    bool rowShifted = false;

    for (int y = 0; y < board->GetSize(); y++)
    {
        int shiftIndex = 0; // track the index to shift blocks to
        for (int x = 0; x < board->GetSize(); x++)
        {
            Block* currentBlock = board->GetBlock(Coordinate(x, y));
            if (currentBlock != nullptr)
            {
                if (shiftIndex != x) {
                    rowShifted = true;
                    board->SetBlock(currentBlock, Coordinate(shiftIndex, y));
                    board->SetBlock(nullptr, Coordinate(x, y));
                }
                shiftIndex++;
            }
        }

        // No need to set remaining elements to nullptr as they already are
    }

    return rowShifted;
}