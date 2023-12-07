#include "gtest/gtest.h"
#include "gmock/gmock.h"
#include <iostream>
#include <string>

#include "../header/gamemanager.hpp"

TEST(GameManagerTests, TestValidConstruction)
{
    EXPECT_NO_THROW(GameManager());
}

TEST(GameManagerTests, TestIsGameLostEmptyBoard)
{
    Board board = Board();
    GameManager gameManager = GameManager();
    EXPECT_FALSE(gameManager.isGameLost());
}

TEST(GameManagerTests, TestIsGameLostFirstRowFullBoard)
{
    Board board = Board();
    Block* newBlock = new Block(2);
    board.AddBlock(newBlock, Coordinate(0, 0));
    newBlock = new Block(4);
    board.AddBlock(newBlock, Coordinate(0, 1));
    newBlock = new Block(8);
    board.AddBlock(newBlock, Coordinate(0, 2));
    newBlock = new Block(16);
    board.AddBlock(newBlock, Coordinate(0, 3));
    GameManager gameManager = GameManager();
    EXPECT_FALSE(gameManager.isGameLost());
}

TEST(GameManagerTests, TestIsGameLostFullBoard)
{
    Board board = Board();

    for (int x = 0; x < board.GetSize(); x++)
    {
        for (int y = 0; y < board.GetSize(); y++)
        {
            board.AddBlock(new Block(2), Coordinate(x, y));
        }
    }

    GameManager gameManager = GameManager();
    EXPECT_FALSE(gameManager.isGameLost());
}

TEST(GameManagerTests, TestIsGameLostFullBoardAndNoMergesPossible)
{
    Board board = Board();
    Block* newBlock = new Block(2);
    board.AddBlock(newBlock, Coordinate(0, 0));
    newBlock = new Block(4);
    board.AddBlock(newBlock, Coordinate(0, 1));
    newBlock = new Block(8);
    board.AddBlock(newBlock, Coordinate(0, 2));
    newBlock = new Block(16);
    board.AddBlock(newBlock, Coordinate(0, 3));
    newBlock = new Block(32);
    board.AddBlock(newBlock, Coordinate(1, 0));
    newBlock = new Block(64);
    board.AddBlock(newBlock, Coordinate(1, 1));
    newBlock = new Block(128);
    board.AddBlock(newBlock, Coordinate(1, 2));
    newBlock = new Block(256);
    board.AddBlock(newBlock, Coordinate(1, 3));
    newBlock = new Block(512);
    board.AddBlock(newBlock, Coordinate(2, 0));
    newBlock = new Block(1024);
    board.AddBlock(newBlock, Coordinate(2, 1));
    newBlock = new Block(2048);
    board.AddBlock(newBlock, Coordinate(2, 2));
    newBlock = new Block(4096);
    board.AddBlock(newBlock, Coordinate(2, 3));
    newBlock = new Block(8192);
    board.AddBlock(newBlock, Coordinate(3, 0));
    newBlock = new Block(16384);
    board.AddBlock(newBlock, Coordinate(3, 1));
    newBlock = new Block(32768);
    board.AddBlock(newBlock, Coordinate(3, 2));
    newBlock = new Block(65536);
    board.AddBlock(newBlock, Coordinate(3, 3));

    GameManager gameManager = GameManager();
    EXPECT_TRUE(gameManager.isGameLost());
}