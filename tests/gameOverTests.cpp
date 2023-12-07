#include "gtest/gtest.h"
#include "gmock/gmock.h"
#include <iostream>
#include <string>

#include "../header/gameover.hpp"

TEST(GameOverTests, CheckMenuDisplay) {
    GameOver testGameOver;
    string testString = "\n \n \n \n \n \n \n \n \nGAME OVER \n \n New Game - g \n Add score on leaderboard - l \n Main Menu - m";
    EXPECT_EQ(testString, testGameOver.getOverDisplay());
}