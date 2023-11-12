#include "gtest/gtest.h"
#include <iostream>
#include <string>
#include "menu.hpp"

TEST(MenuTests, CheckMenuDisplay) {
    Menu testMenu;
    string testString = "2048 \n \n Start Game \n Settings \n Leaderboard \n Quit";
    EXPECT_EQ(testString, testMenu.getMenuDisplay());
}

int main(int argc, char **argv) {
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}