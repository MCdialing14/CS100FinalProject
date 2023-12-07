#include "gtest/gtest.h"
#include "gmock/gmock.h"
#include <iostream>
#include <string>

#include "../header/gameover.hpp"

TEST(GameOverTests, CheckMenuDisplay) {
    GameOver testGameOver;
    string testString = "Game Over \n \n New Game - g \n Leaderboard - l \n Main Menu - m";
    EXPECT_EQ(testString, testGameOver.getOverDisplay());
}