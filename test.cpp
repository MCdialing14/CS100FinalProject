#include "gtest/gtest.h"
#include <iostream>
#include <string>
#include "menu.hpp"
#include "Settings/settings.hpp"
#include "Credits/credits.hpp"

//Main menu tests
TEST(MenuTests, CheckMenuDisplay) {
    Menu testMenu;
    string testString = "2048 \n \n Start Game \n Settings \n Leaderboard \n Quit";
    EXPECT_EQ(testString, testMenu.getMenuDisplay());
}

//pass
TEST(CreditsTest, CheckCreditDisplay) {
    Credits testCredits;
    string expectedCredits = "CREDITS \n \n Mark Sapugay - Leaderboard \n  Michael Carlin - Main Menu \n Niko Udria - Board, Blocks, and Game Management \n Matthew Cedeno - Settings and Credits \n \n Quit";
    EXPECT_EQ(expectedCredits, testCredits.getCreditDisplay());
}

//fail
TEST(CreditsTest, CheckIncorrectCreditDisplay) {
    Credits testCredits;
    string unexpectedCredits = "CREDITS... Uhhh I dont know";
    EXPECT_EQ(unexpectedCredits, testCredits.getCreditDisplay());
}

//pass
TEST(SettingsTest, CheckSettingsDisplay) {
    Settings testSettings;
    string expectedDisplay = "Enter letter to change setting: \n Volume - v \n Sound Effects - e \n \n Apply changes - y \n Default - o \n Quit";
    EXPECT_EQ(expectedDisplay, testSettings.getSettingsDisplay());
}

TEST(SettingsTest, CheckIncorrectSettingsDisplay) {
    Settings testSettings;
    string unexpectedDisplay = "Uhh totally not settings";
    EXPECT_EQ(unexpectedDisplay, testSettings.getSettingsDisplay());
}

//make sure value of sound level/sound effects changed
TEST(SettingsTest, changingSoundLevel) {
    Settings testSettings;
    testSettings.changeSoundLevel();
    EXPECT_EQ(3, testSettings.getSoundLevel());
}

TEST(SettingsTest, changingSoundEffects) {
    Settings testSettings;
    testSettings.changeEffects();
    EXPECT_EQ(0, testSettings.getSoundEffect());
}

int main(int argc, char **argv) {
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}