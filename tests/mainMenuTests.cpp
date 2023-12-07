#include "gtest/gtest.h"
#include "gmock/gmock.h"
#include <iostream>
#include <string>

#include "../header/menu.hpp"

TEST(MenuTests, CheckMenuDisplay) {
    Menu testMenu;
    string testString = "2048 \n \n Start Game - g \n Settings - s \n Leaderboard - l \n Credits - c \n Quit - q";
    EXPECT_EQ(testString, testMenu.getMenuDisplay());
}