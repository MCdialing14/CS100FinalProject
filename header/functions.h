#include <iostream>

#ifndef LEADER_BOARD_FUNCTIONS_H
#define LEADER_BOARD_FUNCTIONS_H

void displayScores(std::string namesArray[], int scoresArray[], int count);
void sort(std::string namesArray[], int scoresArray[], int count);
void addScore(std::string namesArray[], int scoresArray[], int &count, int size, std::string name, int score);
int findName(std::string namesArray[], int count, std::string name);
bool is_Empty(std::string namesArray[]);


#endif