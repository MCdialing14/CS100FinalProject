#include "gtest/gtest.h"
#include "gmock/gmock.h"

#include "../header/BlockShifter.h"

TEST(BlockShifterTests, ShiftLeftEmpty)
{
    Board board = Board();
    BlockShifter blockShifter = BlockShifter(&board);

    EXPECT_FALSE(blockShifter.ShiftLeft());     // nothing should have shifted so expect false
}

TEST(BlockShifterTests, ShiftLeftGap)
{
    Board board = Board();
    BlockShifter blockShifter = BlockShifter(&board);

    /*
    BEFORE:

    x x x x
    x x x x
    x x x x
    2 x x 2
    */

    Block* originBlock = new Block(2);
    board.AddBlock(originBlock, Coordinate(0, 0));

    Block* endBlock = new Block(2);
    board.AddBlock(endBlock, Coordinate(3, 0));

    /* 
    AFTER SHIFT (hopefully):

    x x x x
    x x x x
    x x x x
    2 2 x x
    */

    ASSERT_TRUE(blockShifter.ShiftLeft());

    // make sure the values on that row are 2, 2, x, x
    EXPECT_EQ(originBlock, board.GetBlock(Coordinate(0, 0)));
    EXPECT_EQ(endBlock, board.GetBlock(Coordinate(1, 0)));
    EXPECT_EQ(nullptr, board.GetBlock(Coordinate(2, 0)));
    EXPECT_EQ(nullptr, board.GetBlock(Coordinate(3, 0)));
}