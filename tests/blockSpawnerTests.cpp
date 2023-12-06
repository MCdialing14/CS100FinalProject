#include "gtest/gtest.h"
#include "gmock/gmock.h"

#include "../header/BlockSpawner.h"
#include "../header/Board.h"

//-- BLOCK SPAWNER TESTS

TEST(BlockSpawnerTests, TestNoThrowConstruction)
{
    Board* newBoard = new Board();
    EXPECT_NO_THROW(BlockSpawner blockSpawner(newBoard));

    delete newBoard;
}

TEST(BlockSpawnerTests, TestNoThrowSpawnBlock)
{
    Board* board = new Board();
    BlockSpawner blockSpawner = BlockSpawner(board);

    EXPECT_NO_THROW(blockSpawner.SpawnBlock());

    delete board;
}

TEST(BlockSpawnerTests, TestFullBoardSpawnBlock)
{
    Board* board = new Board();
    BlockSpawner blockSpawner = BlockSpawner(board);

    // Spawn 16 blocks to fully populate board
    for (int i = 0; i < 16; i++)
    {
        blockSpawner.SpawnBlock();
    }

    EXPECT_EQ(true, board->IsBoardFull());

    delete board;
}
