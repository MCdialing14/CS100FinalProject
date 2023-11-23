#include "g/test/gtest.h"
#include "../Leaderboard/functions.cpp"
#include <sstream>

TEST(functionsClassSuite, testDisplayScores)
{
    std::string namesArray[] = {"Alice", "Bob", "Charlie"};
    int scoresArray[] = {100, 95, 85};
    int count = sizeof(namesArray) / sizeof(namesArray[0]);

    displayScores(namesArray, scoresArray, count);

    EXPECT_EQ(std::cout.str(), "Leader Board\nAlice 100\nBob 95\nCharlie 85\n");
}

//no input
TEST(functionsClassSuite, testDisplayScoresEmptyArray)
{
    std::string namesArray[] = {};
    int scoresArray[] = {};
    int count = 0;

    displayScores(namesArray, scoresArray, count);

    EXPECT_EQ(std::cout.str(), "Leader Board\n");
}

TEST(functionsClassSuite, testSortDescending) {
    std::string namesArray[] = {"Alice", "Bob", "Charlie"};
    int scoresArray[] = {100, 95, 85};
    int count = sizeof(namesArray) / sizeof(namesArray[0]);

    sort(namesArray, scoresArray, count, true); // Sort in descending order

    EXPECT_EQ(scoresArray[0], 100);
    EXPECT_EQ(scoresArray[1], 95);
    EXPECT_EQ(scoresArray[2], 85);

    EXPECT_EQ(namesArray[0], "Alice");
    EXPECT_EQ(namesArray[1], "Bob");
    EXPECT_EQ(namesArray[2], "Charlie");
}

//empty arrays
TEST(functionsClassSuite, testSortEmptyArray) {
    std::string namesArray[] = {};
    int scoresArray[] = {};
    int count = 0;

    sort(namesArray, scoresArray, count);

    EXPECT_EQ(scoresArray[0], 0); // Default values for empty array
    EXPECT_EQ(namesArray[0], "");

    EXPECT_EQ(count, 0); // Count remains unchanged for empty array
}

//Exsisting Name
TEST(functionsClassSuite, testAddScoreExistingName)
{
    std::string namesArray[] = {"Charlie", "Bob"};
    int scoresArray[] = {85, 95};
    int count = 2;
    int size = 4;
    std::string name = "Bob";
    int score = 100;

    addScore(namesArray, scoresArray, count, size, name, score);

    EXPECT_EQ(scoresArray[0], 100);
    EXPECT_EQ(scoresArray[1], 85);
    EXPECT_EQ(count, 2);
}

//NewName
TEST(functionsClassSuite, testAddScoreNewName)
{
    std::string namesArray[] = {"Charlie", "Bob"};
    int scoresArray[] = {85, 95};
    int count = 2;
    int size = 4;
    std::string name = "Alice";
    int score = 100;

    addScore(namesArray, scoresArray, count, size, name, score);

    EXPECT_EQ(scoresArray[0], 100);
    EXPECT_EQ(scoresArray[1], 95);
    EXPECT_EQ(scoresArray[2], 85);
    EXPECT_EQ(count, 3);
}

//Replace low score
TEST(functionsClassSuite, testAddScoreReplaceLowScore)
{
    std::string namesArray[] = {"Charlie", "Bob", "Alice"};
    int scoresArray[] = {85, 95, 100};
    int count = 3;
    int size = 3;
    std::string name = "Charlie";
    int score = 75;

    addScore(namesArray, scoresArray, count, size, name, score);

    EXPECT_EQ(scoresArray[0], 95);
    EXPECT_EQ(scoresArray[1], 100);
    EXPECT_EQ(scoresArray[2], 75);
    EXPECT_EQ(count, 3);
}

//empty
TEST(functionsClassSuite, testAddScoreEmptyLeaderboard)
{
    std::string namesArray[] = {};
    int scoresArray[] = {};
    int count = 0;
    int size = 4;
    std::string name = "Alice";
    int score = 100;

    addScore(namesArray, scoresArray, count, size, name, score);

    EXPECT_EQ(namesArray[0], "Alice");
    EXPECT_EQ(scoresArray[0], 100);
    EXPECT_EQ(count, 1);
}

//attempting to add a score lower than all the scores on the leaderboard
TEST(functionsClassSuite, testAddScoreLowerThanAllExistingScores)
{
    std::string namesArray[] = {"Alice", "Bob", "Charlie"};
    int scoresArray[] = {100, 95, 85};
    int count = 3;
    int size = 4;
    std::string name = "David";
    int score = 70;

    addScore(namesArray, scoresArray, count, size, name, score);

    EXPECT_EQ(namesArray[0], "Alice");
    EXPECT_EQ(namesArray[1], "Bob");
    EXPECT_EQ(namesArray[2], "Charlie");
    EXPECT_EQ(namesArray[3], "David");
    EXPECT_EQ(scoresArray[0], 100);
    EXPECT_EQ(scoresArray[1], 95);
    EXPECT_EQ(scoresArray[2], 85);
    EXPECT_EQ(scoresArray[3], 70);
    EXPECT_EQ(count, 4);
}