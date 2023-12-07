#include "gtest/gtest.h"
#include "gmock/gmock.h"

#include "../header/credits.hpp"

//pass
TEST(CreditsTest, CheckCreditDisplay) {
    Credits testCredits;
    string expectedCredits = "\n \n \n \n \n \n \n \n \nCREDITS \n \n Mark Sapugay - Leaderboard \n Michael Carlin - Main Menu and Game Over \n Niko Udria - Board, Blocks, and Game Management \n Matthew Cedeno - Settings and Credits \n \n Main Menu - m";
    EXPECT_EQ(expectedCredits, testCredits.getCreditDisplay());
}

//fail
TEST(CreditsTest, CheckIncorrectCreditDisplay) {
    Credits testCredits;
    string unexpectedCredits = "CREDITS... Uhhh I dont know";
    EXPECT_EQ(unexpectedCredits, testCredits.getCreditDisplay());
}