#ifndef BOARD_H
#define BOARD_H

#include "Block.h"
#include "Coordinate.h"

class Board
{
private:
	Block[4][4] grid;
public:
	int GetScore();
	void AddBlock(Block, Coordinate);
	bool IsBoardFull();
};

#endif // !BOARD_H