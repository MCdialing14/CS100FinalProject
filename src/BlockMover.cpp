#include "../header/BlockMover.h"
#include "../header/BlockShifter.h"
#include "../header/BlockMerger.h"
#include "../header/Board.h"
#include "../header/Block.h"

#include <stdexcept>
#include <vector>

BlockMover::BlockMover(Board* board)
{
    this->board = board;
    this->blockShifter = new BlockShifter(board);
    this->blockMerger = new BlockMerger(board);
}

BlockMover::~BlockMover()
{
    delete blockShifter;
    delete blockMerger;
}

/// @brief Attempts to move all blocks in the direction provided
bool BlockMover::PerformMove(Direction direction)
{
    bool successfulShift = false;

    switch (direction)
    {
        case Direction::NORTH:
            RotateBoard();
            successfulShift = PerformMoveHelper();
            RotateBoard();
            RotateBoard();
            RotateBoard();
            break;
        case Direction::EAST:
            RotateBoard();
            RotateBoard();
            successfulShift = PerformMoveHelper();
            RotateBoard();
            RotateBoard();
            break;
        case Direction::SOUTH:
            RotateBoard();
            RotateBoard();
            RotateBoard();
            successfulShift = PerformMoveHelper();
            RotateBoard();
            break;
        case Direction::WEST:
            successfulShift = PerformMoveHelper();
            break;
        default:
            throw std::invalid_argument("Unrecognized Direction enum value");
    }
    return successfulShift;
}

/// @brief Rotates the board 90 degrees counter clock-wise. Used for shifting blocks in directions other than left.
void BlockMover::RotateBoard()
{
    const int size = board->GetSize();
    for (int x = 0; x < (size / 2); x++)
    {
        for (int y = x; y < (size - x - 1); y++)
        {
            Block* temp = board->GetBlock(Coordinate(x, y));
 
            // Move values from right to top
            Block* right = board->GetBlock(Coordinate(y, size - 1 - x));
            board->SetBlock(right, Coordinate(x, y));
 
            // Move values from bottom to right
            Block* bottom = board->GetBlock(Coordinate(size - 1 - x, size - 1 - y));
            board->SetBlock(bottom, Coordinate(y, size - 1 - x));
 
            // Move values from left to bottom
            Block* left = board->GetBlock(Coordinate(size - 1 - y, x));
            board->SetBlock(left, Coordinate(size - 1 - x, size - 1 - y));
 
            // Assign temp to left
            board->SetBlock(temp, Coordinate(size - 1 - y, x));
        }
    }
}

//-- HELPERS

/// @brief Performs a shift, merge, then shift in the left direction mimicing the behavior you'd expect in a regular 2048 game.
/// @returns Whether bool for whether a shift or merge occured
bool BlockMover::PerformMoveHelper()
{
    bool movedOrCombined = false;

    movedOrCombined = movedOrCombined || blockShifter->ShiftLeft();
    movedOrCombined = movedOrCombined || blockMerger->MergeLeft();
    movedOrCombined = movedOrCombined || blockShifter->ShiftLeft();

    return movedOrCombined;
}