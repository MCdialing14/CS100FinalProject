#include "gtest/gtest.h"
#include "gmock/gmock.h"

#include "../header/Block.h"
#include "../header/Coordinate.h"
#include "../header/Board.h"
#include "../header/BlockSpawner.h"

//-- BLOCK TESTS
TEST(BlockTests, TestValidConstruction)
{
    EXPECT_NO_THROW(Block(2));
    EXPECT_NO_THROW(Block(4));
}

TEST(BlockTests, TestGetters)
{
    Block block2 = Block(2);
    EXPECT_EQ(2, block2.GetValue());

    Block block4 = Block(4);
    EXPECT_EQ(4, block4.GetValue());
}

//-- COORDINATE TESTS
TEST(CoordinateTests, TestValidConstruction)
{
    EXPECT_NO_THROW(Coordinate(0, 0));
    EXPECT_NO_THROW(Coordinate(1, 2));
    EXPECT_NO_THROW(Coordinate(2, 1));
    EXPECT_NO_THROW(Coordinate(3, 3));
}

TEST(CoordinateTests, TestGetters)
{
    Coordinate coord00 = Coordinate(0, 0);
    EXPECT_EQ(0, coord00.GetX());
    EXPECT_EQ(0, coord00.GetY());

    Coordinate coord12 = Coordinate(1, 2);
    EXPECT_EQ(1, coord12.GetX());
    EXPECT_EQ(2, coord12.GetY());

    Coordinate coord21 = Coordinate(2, 1);
    EXPECT_EQ(2, coord21.GetX());
    EXPECT_EQ(1, coord21.GetY());

    Coordinate coord33 = Coordinate(3, 3);
    EXPECT_EQ(3, coord33.GetX());
    EXPECT_EQ(3, coord33.GetY());
}

//-- BOARD TESTS
TEST(BoardTests, TestValidConstruction)
{
    EXPECT_NO_THROW(Board());
}

TEST(BoardTests, TestGetRows)
{
    Board board = Board();

    EXPECT_EQ(4, board.GetRows());
}

TEST(BoardTests, TestGetColumns)
{
    Board board = Board();

    EXPECT_EQ(4, board.GetColumns());
}

TEST(BoardTests, TestAddBlock)
{
    Board board = Board();
    Block* newBlock = new Block(2);
    EXPECT_NO_THROW(board.AddBlock(newBlock, Coordinate(0, 0)));
    EXPECT_EQ(newBlock, board.GetBlock(0, 0));
}

TEST(BoardTests, TestConstructionInitialization)
{
    Board board = Board();

    for (int x = 0; x < board.GetRows(); x++)
    {
        for (int y = 0; y < board.GetColumns(); y++)
        {
            EXPECT_EQ(nullptr, board.GetBlock(x, y));
        }
    }
}

TEST(BoardTests, TestGetBlock)
{
    Board board = Board();

    EXPECT_EQ(nullptr, board.GetBlock(0, 0));

    Block* newBlock = new Block(2);
    board.AddBlock(newBlock, Coordinate(0, 0));
    EXPECT_EQ(newBlock, board.GetBlock(0, 0));
}

TEST(BoardTests, TestGetScore)
{
    Board board = Board();

    // Empty board should have a score of 0
    EXPECT_EQ(0, board.GetScore());

    // Add 6 worth of 2-blocks
    Block* blockVal2 = new Block(2);
    board.AddBlock(blockVal2, Coordinate(0, 0));
    blockVal2 = new Block(2);
    board.AddBlock(blockVal2, Coordinate(3, 1));
    blockVal2 = new Block(2);
    board.AddBlock(blockVal2, Coordinate(2, 2));

    // Add 8 worth of 4-blocks
    Block* blockVal4 = new Block(4);
    board.AddBlock(blockVal4, Coordinate(1, 2));
    blockVal4 = new Block(4);
    board.AddBlock(blockVal4, Coordinate(3, 3));

    // total score should now be 14 (6 + 8)
    EXPECT_EQ(14, board.GetScore());
}

TEST(BoardTests, TestEmptyIsBoardFull)
{
    Board board = Board();

    EXPECT_EQ(false, board.IsBoardFull());
}

TEST(BoardTests, Test1BlockIsBoardFull)
{
    Board board = Board();

    Block* newBlock = new Block(2);
    board.AddBlock(newBlock, Coordinate(0, 0));
    EXPECT_EQ(false, board.IsBoardFull());
}

TEST(BoardTests, TestFullIsBoardFull)
{
    Board board = Board();
    for (int x = 0; x < board.GetRows(); x++)
    {
        for (int y = 0; y < board.GetColumns(); y++)
        {
            board.AddBlock(new Block(2), Coordinate(x, y));
        }
    }

    EXPECT_EQ(true, board.IsBoardFull());
}

//-- BLOCK SPAWNER
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

int main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}