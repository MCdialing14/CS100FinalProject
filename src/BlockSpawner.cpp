#include "../header/BlockSpawner.h"
#include <random>
#include <vector>

/// <summary>
/// Creates a block with a random value of 2 or 4 at a random empty spot on the board
/// </summary>
void BlockSpawner::SpawnBlock()
{
	// Set up the random number generator
	std::random_device rd;
	std::mt19937 gen(rd());
	
	// Get distribution for spaces and random values
	std::vector<Coordinate> emptySpaces = GetEmptyCoords();
	std::uniform_int_distribution<> spacesDist(0, emptySpaces.size() - 1);
	std::uniform_int_distribution<> randomValDist(1, 2);

	// Creates a block with random value of 2 or 4
	int randomBlockVal = randomValDist(gen) * 2;
	Block* newBlock = new Block(randomBlockVal);

	// Place block at random space
	int randomSpaceIndex = spacesDist(gen);
	Coordinate randomCoord = emptySpaces.at(randomSpaceIndex);
	board->AddBlock(newBlock, randomCoord);
}

/// <summary>
/// Helper function that returns a vector of all empty coordinates on the board
/// </summary>
/// <returns></returns>
std::vector<Coordinate> BlockSpawner::GetEmptyCoords()
{
	std::vector<Coordinate> emptyCoords;

	for (int x = 0; x < board->GetRows(); x++)
	{
		for (int y = 0; y < board->GetColumns(); y++)
		{
			if (board->GetBlock(x, y) == nullptr)
			{
				emptyCoords.push_back(Coordinate(x, y));
			}
		}
	}

	return emptyCoords;
}