#include "gtest/gtest.h"
#include "../header/functions.h"
#include <sstream>


TEST(functionsClassSuite, testAddScoreEmptyLeaderboard) {
  // Declare the arrays with enough space to hold the new score
  std::string namesArray[4];
  int scoresArray[4];
  int count = 0;
  int size = sizeof(namesArray) / sizeof(namesArray[0]);
  std::string name = "Alice";
  int score = 100;

  addScore(namesArray, scoresArray, count, size, name, score);

  // Expect the first element to be filled with the new score
  EXPECT_EQ(namesArray[0], "Alice");
  EXPECT_EQ(scoresArray[0], 100);
  EXPECT_EQ(count, 1); // Count should be incremented after adding a score
}


TEST(functionsClassSuite, testSortFunction) {
  std::string namesArray[] = {"Alice", "Charlie", "Bob"};
  int scoresArray[] = {85, 100, 95};
  int count = 3;

  sort(namesArray, scoresArray, count);

  // Check if the arrays are sorted in descending order based on score
  EXPECT_EQ(scoresArray[0], 85);
  EXPECT_EQ(scoresArray[1], 95);
  EXPECT_EQ(scoresArray[2], 100);

  // Check if the names are sorted accordingly
  EXPECT_EQ(namesArray[0], "Alice");
  EXPECT_EQ(namesArray[1], "Bob");
  EXPECT_EQ(namesArray[2], "Charlie");
}

TEST(functionsClassSuite, testSortSingleElement) {
  std::string namesArray[] = {"Alice"};
  int scoresArray[] = {100};
  int count = 1;

  sort(namesArray, scoresArray, count);

  // Check if the single element remains unchanged after sorting
  EXPECT_EQ(scoresArray[0], 100);
  EXPECT_EQ(namesArray[0], "Alice");
}

TEST(functionsClassSuite, testAddScoreSingleEmptyLeaderboard) {
  std::string namesArray[1];
  int scoresArray[1];
  int count = 0;
  int size = 1;
  std::string name = "Alice";
  int score = 100;

  addScore(namesArray, scoresArray, count, size, name, score);

  // Expect the single score and name to be added
  EXPECT_EQ(scoresArray[0], 100);
  EXPECT_EQ(namesArray[0], "Alice");
  EXPECT_EQ(count, 1);
}


TEST(functionsClassSuite, testSortDescending) {
  // Create arrays with unsorted values
  std::string namesArray[] = {"Bob", "Alice", "Charlie"};
  int scoresArray[] = {95, 100, 85};
  int count = 3;

  // Call the sort function
  sort(namesArray, scoresArray, count);

  // Expect descending order for scores
  EXPECT_EQ(scoresArray[0], 85);
  EXPECT_EQ(scoresArray[1], 95);
  EXPECT_EQ(scoresArray[2], 100);

  // Expect corresponding names in the same order
  EXPECT_EQ(namesArray[0], "Charlie");
  EXPECT_EQ(namesArray[1], "Bob");
  EXPECT_EQ(namesArray[2], "Alice");
}

TEST(functionsClassSuite, testAddScoreFullLeaderboard) {
  // Leaderboard is already full
  std::string namesArray[] = {"Alice", "Bob", "Charlie"};
  int scoresArray[] = {100, 95, 85};
  int count = 3;
  int size = 3; // Full leaderboard
  std::string name = "David";
  int score = 90;

  // Add a score that is higher than the lowest score
  addScore(namesArray, scoresArray, count, size, name, score);

  // Expect the existing low score to be replaced
  EXPECT_EQ(scoresArray[2], 100);
  EXPECT_EQ(namesArray[2], "Alice");

  // Expect the other entries to remain unchanged
  EXPECT_EQ(scoresArray[0], 85);
  EXPECT_EQ(scoresArray[1], 95);
  EXPECT_EQ(namesArray[0], "Charlie");
  EXPECT_EQ(namesArray[1], "Bob");

  // Expect count to remain the same
  EXPECT_EQ(count, 3);
}