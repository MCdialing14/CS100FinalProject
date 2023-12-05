#ifndef BOARD_H
#define BOARD_H

#include "Block.h"
#include "Coordinate.h"

class Board
{
private:
	static constexpr int SIZE = 4;
	Block* grid[SIZE][SIZE] = {};
public:
	Board();
	~Board();
	int GetScore();
	const int GetSize();
	Block* GetBlock(Coordinate);
	void AddBlock(Block*, Coordinate);
	void SetBlock(Block*, Coordinate);
	bool IsBoardFull();
};

#endif // !BOARD_H