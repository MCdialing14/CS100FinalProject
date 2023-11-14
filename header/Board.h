#ifndef BOARD_H
#define BOARD_H

#include "Block.h"
#include "Coordinate.h"

class Board
{
private:
	const int ROWS = 4;
	const int COLUMNS = 4;
	Block* grid[ROWS][COLUMNS] = {};
public:
	Board();
	~Board();
	int GetScore();
	const int GetRows();
	const int GetColumns();
	Block* GetBlock(int x, int y);
	void AddBlock(Block*, Coordinate);
	bool IsBoardFull();
};

#endif // !BOARD_H