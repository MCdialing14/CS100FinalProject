#include "gtest/gtest.h"
#include "gmock/gmock.h"

#include "../header/settings.hpp"

//pass
TEST(SettingsTest, CheckSettingsDisplay) {
    Settings testSettings;
    string expectedDisplay = "\n \n \n \n \n \n \n \n \nSETTINGS \n \nEnter letter to change setting: \n Volume - v \n Sound Effects - e \n \n Default - o \n Main Menu - m";
    EXPECT_EQ(expectedDisplay, testSettings.getSettingsDisplay());
}

//fail
TEST(SettingsTest, CheckIncorrectSettingsDisplay) {
    Settings testSettings;
    string unexpectedDisplay = "Uhh totally not settings";
    EXPECT_EQ(unexpectedDisplay, testSettings.getSettingsDisplay());
}

TEST(SettingsTest, ReturnDefaultVolume) {
    Settings testSettings;
    EXPECT_EQ(5, testSettings.getSoundLevel());
}

TEST(SettingsTest, ReturnDefaultEffects) {
    Settings testSettings;
    EXPECT_EQ(true, testSettings.getSoundEffect());
}

TEST(SettingsTest, ChangeVolume) {
    cout << "Enter 7 to pass test" << endl;
    Settings testSettings;
    testSettings.changeSoundLevel();
    EXPECT_EQ(7, testSettings.getSoundLevel());
}

TEST(SettingsTest, ChangeEffects) {
    cout << "Enter 1 to pass test" << endl;
    Settings testSettings;
    testSettings.changeEffects();
    EXPECT_EQ(false, testSettings.getSoundEffect());
}

TEST(SettingsTest, SetDefaultVolume) {
    Settings testSettings;
    testSettings.changeToDefault();
    EXPECT_EQ(5, testSettings.getSoundLevel());
}

TEST(SettingsTest, SetDefaultEffects) {
    Settings testSettings;
    testSettings.changeToDefault();
    EXPECT_EQ(true, testSettings.getSoundEffect());
}