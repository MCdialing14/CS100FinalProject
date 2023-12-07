#include "gtest/gtest.h"
#include "gmock/gmock.h"

#include "../header/Board.h"
#include "../header/Coordinate.h"

//-- BOARD TESTS

TEST(BoardTests, TestValidConstruction)
{
    EXPECT_NO_THROW(Board());
}

TEST(BoardTests, TestGetRows)
{
    Board board = Board();

    EXPECT_EQ(4, board.GetSize());
}

TEST(BoardTests, TestGetColumns)
{
    Board board = Board();

    EXPECT_EQ(4, board.GetSize());
}

TEST(BoardTests, TestAddBlock)
{
    Board board = Board();
    Block* newBlock = new Block(2);
    Coordinate origin = Coordinate(0, 0);
    EXPECT_NO_THROW(board.AddBlock(newBlock, origin));
    EXPECT_EQ(newBlock, board.GetBlock(origin));
}

TEST(BoardTests, TestConstructionInitialization)
{
    Board board = Board();

    for (int x = 0; x < board.GetSize(); x++)
    {
        for (int y = 0; y < board.GetSize(); y++)
        {
            Coordinate currentCoord = Coordinate(x, y);
            EXPECT_EQ(nullptr, board.GetBlock(currentCoord));
        }
    }
}

TEST(BoardTests, TestGetBlock)
{
    Board board = Board();
    Coordinate origin = Coordinate(0, 0);

    EXPECT_EQ(nullptr, board.GetBlock(origin));

    Block* newBlock = new Block(2);
    board.AddBlock(newBlock, Coordinate(origin));
    EXPECT_EQ(newBlock, board.GetBlock(origin));
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

    EXPECT_FALSE(board.IsBoardFull());
}

TEST(BoardTests, Test1BlockIsBoardFull)
{
    Board board = Board();

    Block* newBlock = new Block(2);
    board.AddBlock(newBlock, Coordinate(0, 0));
    EXPECT_FALSE(board.IsBoardFull());
}

TEST(BoardTests, TestFullIsBoardFull)
{
    Board board = Board();
    for (int x = 0; x < board.GetSize(); x++)
    {
        for (int y = 0; y < board.GetSize(); y++)
        {
            board.AddBlock(new Block(2), Coordinate(x, y));
        }
    }

    EXPECT_TRUE(board.IsBoardFull());
}
