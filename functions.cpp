#include "functions.h"

void displayScores(std::string namesArray[], int scoresArray[], int count){
    std::cout << std::endl << std::endl << std::endl << std::endl << std::endl << std::endl << std::endl << std::endl << std::endl << "LEADERBOARD" << std::endl;
    int ranking = 0;
    for (int i = count -1; i >=0; i--){
        ++ranking;
        std::cout << ranking << ". " << namesArray[i] << " " << scoresArray[i] << std::endl;
    }

}
void sort(std::string namesArray[], int scoresArray[], int count){
    //increment over unsorted items 
    for (int i = 0; i < count; i++) {
        //value to be inserted into the sorted array
        std::string name = namesArray[i];
        int score = scoresArray[i];

        //start at back of sorted array
        int j = i -1;

        //search through array for the correct location
        while 
            (j >= 0 && scoresArray[j] > score) {
            scoresArray[j+1] = scoresArray [j];
            namesArray[j+1] = namesArray[j];
            j--;
        }

        scoresArray[j+1] = score;
        namesArray [j+1] = name;
    }

}
void addScore(std::string namesArray[], int scoresArray[], int &count, int size, std::string name, int score){
    int index;
    //Find the name if it exists
    index = findName(namesArray, count, name);
    if(index >= 0 ) {
        //name already exists
        if (scoresArray [index]< score) 
        scoresArray[index] = score;
        sort(namesArray, scoresArray, count);
    }
    else {
        if (count < 1) {
            //Put in the only score
            scoresArray[0] = score;
            namesArray[0] = name;
            count++;
        }
        else {
            //Replace low score if the loader board is filled
            if (count == size){
                if (score > scoresArray [0]) {
                    scoresArray[0] = score;
                    namesArray[0] = name;
                }
            }
            else {
                scoresArray [count] = score;
                namesArray [count] = name;
                count++;
            }

           //sort the Array  
           sort(namesArray, scoresArray, count);
        }
    }


}
int findName(std::string namesArray[], int count, std::string name){
    int index = -1;

    for (int i=0; i < count; i++){
        if (name.compare(namesArray[i])==0)index =i;
    }
    return index;
}

bool is_Empty(std::string namesArray[]) {
    if(namesArray->empty()) {
        return true;
    }
    else {
        return false;
    }
}