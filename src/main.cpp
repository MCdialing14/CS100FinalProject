#include <iostream>
#include "../header/functions.h"
int main() {
    const int SIZE = 5;
    std::string namesArray[SIZE];
    int scoresArray[SIZE];
    int count = 0;

    addScore(namesArray, scoresArray, count, SIZE, "Mark", 25);
    addScore(namesArray, scoresArray, count, SIZE, "Michael", 30);
    addScore(namesArray, scoresArray, count, SIZE, "Matthew", 35);
    addScore(namesArray, scoresArray, count, SIZE, "Niko", 40);
    
    displayScores(namesArray, scoresArray, count);
    return 0;
}