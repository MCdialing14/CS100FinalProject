#ifndef BLOCKSPAWNER_H
#define BLOCKSPAWNER_H

#include <vector>
#include "Board.h"
#include "Coordinate.h"

class BlockSpawner
{
private:
	Board* board;

public:
	BlockSpawner(Board* board) : board(board) {}
	void SpawnBlock();

private:
	std::vector<Coordinate> GetEmptyCoords();
};

#endif // !BLOCKSPAWNER_H
