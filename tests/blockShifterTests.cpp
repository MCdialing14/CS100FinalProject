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

    for (int y = 0; y < board.GetSize(); y++)
    {           
        Block* originBlock = new Block(2);
        board.AddBlock(originBlock, Coordinate(0, y));

        Block* endBlock = new Block(2);
        board.AddBlock(endBlock, Coordinate(3, y));

        // BEFORE SHIFT: 2 x x 2
        ASSERT_TRUE(blockShifter.ShiftLeft());
        // AFTER SHIFT (hopefully): 2 2 x x

        // make sure the values on that row are 2, 2, x, x
        EXPECT_EQ(originBlock, board.GetBlock(Coordinate(0, y)));
        EXPECT_EQ(endBlock, board.GetBlock(Coordinate(1, y)));
        EXPECT_EQ(nullptr, board.GetBlock(Coordinate(2, y)));
        EXPECT_EQ(nullptr, board.GetBlock(Coordinate(3, y)));
    }
}

TEST(BlockShifterTests, ShiftLeftNotPossible)
{
    Board board = Board();
    BlockShifter blockShifter = BlockShifter(&board);

    for (int y = 0; y < board.GetSize(); y++)
    {
        // make sure no shift happens and values on row are 2, x, x, x
        Block* originBlock = new Block(2);
        board.AddBlock(originBlock, Coordinate(0, y));
        ASSERT_FALSE(blockShifter.ShiftLeft());
        EXPECT_EQ(originBlock, board.GetBlock(Coordinate(0, y)));
        EXPECT_EQ(nullptr, board.GetBlock(Coordinate(1, y)));
        EXPECT_EQ(nullptr, board.GetBlock(Coordinate(2, y)));
        EXPECT_EQ(nullptr, board.GetBlock(Coordinate(3, y)));

        // make sure no shift happens and the values on that row are 2, 2, x, x
        Block* secondBlock = new Block(2);
        board.AddBlock(secondBlock, Coordinate(1, y));
        ASSERT_FALSE(blockShifter.ShiftLeft());
        EXPECT_EQ(originBlock, board.GetBlock(Coordinate(0, y)));
        EXPECT_EQ(secondBlock, board.GetBlock(Coordinate(1, y)));
        EXPECT_EQ(nullptr, board.GetBlock(Coordinate(2, y)));
        EXPECT_EQ(nullptr, board.GetBlock(Coordinate(3, y)));

        // make sure no shift happens and values on row are 2, 2, 2, x
        Block* thirdBlock = new Block(2);
        board.AddBlock(thirdBlock, Coordinate(2, y));
        ASSERT_FALSE(blockShifter.ShiftLeft());
        EXPECT_EQ(originBlock, board.GetBlock(Coordinate(0, y)));
        EXPECT_EQ(secondBlock, board.GetBlock(Coordinate(1, y)));
        EXPECT_EQ(thirdBlock, board.GetBlock(Coordinate(2, y)));
        EXPECT_EQ(nullptr, board.GetBlock(Coordinate(3, y)));

        // make sure no shift happens and values on row are 2, 2, 2, 2
        Block* endBlock = new Block(2);
        board.AddBlock(endBlock, Coordinate(3, y));
        ASSERT_FALSE(blockShifter.ShiftLeft());
        EXPECT_EQ(originBlock, board.GetBlock(Coordinate(0, y)));
        EXPECT_EQ(secondBlock, board.GetBlock(Coordinate(1, y)));
        EXPECT_EQ(thirdBlock, board.GetBlock(Coordinate(2, y)));
        EXPECT_EQ(endBlock, board.GetBlock(Coordinate(3, y)));
    }
}

TEST(BlockShifterTests, ShiftFromMiddle)
{
    Board board = Board();
    BlockShifter blockShifter = BlockShifter(&board);

    for (int y = 0; y < board.GetSize(); y++)
    {           
        Block* secondBlock = new Block(2);
        board.AddBlock(secondBlock, Coordinate(1, y));

        Block* thirdBlock = new Block(2);
        board.AddBlock(thirdBlock, Coordinate(2, y));

        // BEFORE SHIFT: x 2 2 x
        ASSERT_TRUE(blockShifter.ShiftLeft());
        // AFTER SHIFT (hopefully): 2 2 x x

        // make sure the values on that row are 2, 2, x, x
        EXPECT_EQ(secondBlock, board.GetBlock(Coordinate(0, y)));
        EXPECT_EQ(thirdBlock, board.GetBlock(Coordinate(1, y)));
        EXPECT_EQ(nullptr, board.GetBlock(Coordinate(2, y)));
        EXPECT_EQ(nullptr, board.GetBlock(Coordinate(3, y)));
    }
}