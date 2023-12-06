#include "gtest/gtest.h"
#include "gmock/gmock.h"

#include "../header/Block.h"

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