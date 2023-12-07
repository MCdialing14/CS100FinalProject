#include "gtest/gtest.h"
#include "gmock/gmock.h"

#include "../header/BlockMerger.h"
#include "../header/Board.h"

TEST(BlockMergerTests, EmptyBoardMergeLeft)
{
    Board board = Board();
    BlockMerger blockMerger = BlockMerger(&board);

    ASSERT_FALSE(blockMerger.MergeLeft());
}

TEST(BlockMergerTests, GapMerge)
{
    Board board = Board();
    BlockMerger blockMerger = BlockMerger(&board);

    for (int y = 0; y < board.GetSize(); y++)
    {           
        Block* originBlock = new Block(2);
        board.AddBlock(originBlock, Coordinate(0, y));

        Block* gapBlock = new Block(2);
        board.AddBlock(gapBlock, Coordinate(2, y));

        // BEFORE MERGE: 2 x 2 x
        ASSERT_FALSE(blockMerger.MergeLeft());
        // AFTER MERGE (hopefully): 2 x 2 x

        // make sure the values on that row are 2, x, 2, x
        EXPECT_EQ(2, board.GetBlock(Coordinate(0, y))->GetValue());
        EXPECT_EQ(originBlock, board.GetBlock(Coordinate(0, y)));
        EXPECT_EQ(nullptr, board.GetBlock(Coordinate(1, y)));
        EXPECT_EQ(2, board.GetBlock(Coordinate(2, y))->GetValue());
        EXPECT_EQ(gapBlock, board.GetBlock(Coordinate(2, y)));
        EXPECT_EQ(nullptr, board.GetBlock(Coordinate(3, y)));
    }
}

TEST(BlockMergerTests, InvalidMergeLeft)
{
    Board board = Board();
    BlockMerger blockMerger = BlockMerger(&board);

    for (int y = 0; y < board.GetSize(); y++)
    {           
        Block* originBlock = new Block(2);
        board.AddBlock(originBlock, Coordinate(0, y));

        Block* nextBlock = new Block(4);
        board.AddBlock(nextBlock, Coordinate(1, y));

        // BEFORE MERGE: 2 4 x x
        ASSERT_FALSE(blockMerger.MergeLeft());
        // AFTER MERGE (hopefully): 2 4 x x

        // make sure the values on that row are 2, 4, x, x
        EXPECT_EQ(2, board.GetBlock(Coordinate(0, y))->GetValue());
        EXPECT_EQ(originBlock, board.GetBlock(Coordinate(0, y)));
        EXPECT_EQ(4, board.GetBlock(Coordinate(1, y))->GetValue());
        EXPECT_EQ(nextBlock, board.GetBlock(Coordinate(1, y)));
        EXPECT_EQ(nullptr, board.GetBlock(Coordinate(2, y)));
        EXPECT_EQ(nullptr, board.GetBlock(Coordinate(3, y)));
    }
}

TEST(BlockMergerTests, LeftSideMergeLeft)
{
    Board board = Board();
    BlockMerger blockMerger = BlockMerger(&board);

    for (int y = 0; y < board.GetSize(); y++)
    {           
        Block* originBlock = new Block(2);
        board.AddBlock(originBlock, Coordinate(0, y));

        Block* nextBlock = new Block(2);
        board.AddBlock(nextBlock, Coordinate(1, y));

        // BEFORE MERGE: 2 2 x x
        ASSERT_TRUE(blockMerger.MergeLeft());
        // AFTER MERGE (hopefully): 4 x x x

        // make sure the values on that row are 4, x, x, x
        EXPECT_EQ(4, board.GetBlock(Coordinate(0, y))->GetValue());
        EXPECT_EQ(originBlock, board.GetBlock(Coordinate(0, y)));
        EXPECT_EQ(nullptr, board.GetBlock(Coordinate(1, y)));
        EXPECT_EQ(nullptr, board.GetBlock(Coordinate(2, y)));
        EXPECT_EQ(nullptr, board.GetBlock(Coordinate(3, y)));
    }
}

TEST(BlockMergerTests, MiddleMergeLeft)
{
    Board board = Board();
    BlockMerger blockMerger = BlockMerger(&board);

    for (int y = 0; y < board.GetSize(); y++)
    {           
        Block* originBlock = new Block(2);
        board.AddBlock(originBlock, Coordinate(1, y));

        Block* nextBlock = new Block(2);
        board.AddBlock(nextBlock, Coordinate(2, y));

        // BEFORE MERGE: x 2 2 x
        ASSERT_TRUE(blockMerger.MergeLeft());
        // AFTER MERGE (hopefully): x 4 x x

        // make sure the values on that row are x, 4, x, x
        EXPECT_EQ(nullptr, board.GetBlock(Coordinate(0, y)));
        EXPECT_EQ(4, board.GetBlock(Coordinate(1, y))->GetValue());
        EXPECT_EQ(originBlock, board.GetBlock(Coordinate(1, y)));
        EXPECT_EQ(nullptr, board.GetBlock(Coordinate(2, y)));
        EXPECT_EQ(nullptr, board.GetBlock(Coordinate(3, y)));
    }
}

TEST(BlockMergerTests, RightSideMergeLeft)
{
    Board board = Board();
    BlockMerger blockMerger = BlockMerger(&board);

    for (int y = 0; y < board.GetSize(); y++)
    {           
        Block* originBlock = new Block(2);
        board.AddBlock(originBlock, Coordinate(2, y));

        Block* nextBlock = new Block(2);
        board.AddBlock(nextBlock, Coordinate(3, y));

        // BEFORE MERGE: x x 2 2
        ASSERT_TRUE(blockMerger.MergeLeft());
        // AFTER MERGE (hopefully): x x 4 x

        // make sure the values on that row are x, x, 4, x
        EXPECT_EQ(nullptr, board.GetBlock(Coordinate(0, y)));
        EXPECT_EQ(nullptr, board.GetBlock(Coordinate(1, y)));
        EXPECT_EQ(4, board.GetBlock(Coordinate(2, y))->GetValue());
        EXPECT_EQ(originBlock, board.GetBlock(Coordinate(2, y)));
        EXPECT_EQ(nullptr, board.GetBlock(Coordinate(3, y)));
    }
}

TEST(BlockMergerTests, testDoubleMerge)
{
    Board board = Board();
    BlockMerger blockMerger = BlockMerger(&board);

    for (int y = 0; y < board.GetSize(); y++)
    {           
        Block* firstBlock = new Block(2);
        board.AddBlock(firstBlock, Coordinate(0, y));

        Block* secondBlock = new Block(2);
        board.AddBlock(secondBlock, Coordinate(1, y));
        
        Block* thirdBlock = new Block(2);
        board.AddBlock(thirdBlock, Coordinate(2, y));

        Block* fourthBlock = new Block(2);
        board.AddBlock(fourthBlock, Coordinate(3, y));

        // BEFORE MERGE: 2 2 2 2
        ASSERT_TRUE(blockMerger.MergeLeft());
        // AFTER MERGE (hopefully): x 4 x 4

        // make sure the values on that row are 4, x, 4, x
        EXPECT_EQ(firstBlock, board.GetBlock(Coordinate(0, y)));
        EXPECT_EQ(4, board.GetBlock(Coordinate(0, y))->GetValue());
        EXPECT_EQ(nullptr, board.GetBlock(Coordinate(1, y)));
        EXPECT_EQ(thirdBlock, board.GetBlock(Coordinate(2, y)));
        EXPECT_EQ(4, board.GetBlock(Coordinate(2, y))->GetValue());
        EXPECT_EQ(nullptr, board.GetBlock(Coordinate(3, y)));
    }
}