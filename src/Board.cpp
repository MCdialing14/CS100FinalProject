#include "../header/Board.h"
#include <stdexcept>

/// <summary>
/// Creates a board full of empty Block pointers
/// </summary>
Board::Board()
{
	for (int x = 0; x < ROWS; x++)
	{
		for (int y = 0; y < COLUMNS; y++)
		{
			grid[x][y] = nullptr;
		}
	}
}

/// <summary>
/// Deallocates any blocks remaining in the board
/// </summary>
Board::~Board()
{
	for (int x = 0; x < ROWS; x++)
	{
		for (int y = 0; y < COLUMNS; y++)
		{
			if (grid[x][y] != nullptr)
			{
				delete grid[x][y];
				grid[x][y] = nullptr;
			}
		}
	}
}

/// <summary>
/// Returns the sum of all Blocks score within the board
/// </summary>
/// <returns></returns>
int Board::GetScore()
{
	int sum = 0;

	for (int x = 0; x < ROWS; x++)
	{
		for (int y = 0; y < COLUMNS; y++)
		{
			if (grid[x][y] != nullptr)
			{
				sum += grid[x][y]->GetValue();
			}
		}
	}

	return sum;
}

/// <summary>
/// returns number of rows of the board
/// </summary>
/// <returns></returns>
const int Board::GetRows()
{
	return ROWS;
}

/// <summary>
/// returns number of columns of the board
/// </summary>
/// <returns></returns>
const int Board::GetColumns()
{
	return COLUMNS;
}

Block* Board::GetBlock(int x, int y)
{
	return grid[x][y];
}

/// <summary>
/// Adds a block at the provided Coordinate to the Board.
/// Cannot add blocks to spaces that are already occupied.
/// </summary>
/// <param name="block"> The block to be added. </param>
/// <param name="coord"> The coordinate to add the block at.</param>
void Board::AddBlock(Block* block, Coordinate coord)
{
	int x = coord.GetX();
	int y = coord.GetY();

	if (grid[x][y] == nullptr)
	{
		grid[x][y] = block;
	}
	else
	{
		throw std::invalid_argument("The specified coordinate is already occupied.");
	}
}

/// <summary>
/// Checks if each space in the board is occupied.
/// </summary>
/// <returns>
/// Returns true if every space on the board is occupied by a block, 
/// otherwise returns false.
/// </returns>
bool Board::IsBoardFull()
{
	// Return false if it finds an empty space
	for (int x = 0; x < ROWS; x++)
	{
		for (int y = 0; y < COLUMNS; y++)
		{
			if (grid[x][y] == nullptr)
			{
				return false;
			}
		}
	}

	// Otherwise return true
	return true;
}
