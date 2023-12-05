#include "gtest/gtest.h"
#include "gmock/gmock.h"

#include "../header/Coordinate.h"

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
