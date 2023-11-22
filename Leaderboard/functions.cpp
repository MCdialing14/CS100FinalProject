#include "functions.h"

void displayScores(std::string namesArray[], int scoresArray[], int count){
    std::cout << "Leader Board" << std::endl;
    for (int i = count -1; i >=0; i--){
        std::cout << namesArray[i] << " " << scoresArray[i] << std::endl;
    }

}
void sort(std::string namesArray[], int scoresArray[], int count){
    //increment over unsorted items 
    for (int i = 1; < count; i++) {
        //value to be inserted into the sorted array
        std::string name = namesArray[i];
        int score = scoresArray[i];

        //start at back of sorted array
        int j = i -1;

        //search through array for the correct location
        while 
            (j >= 0 && scoresArray[j] > score) {
            scoresArray[j+1] = scoresArray [j];
            namesArray[j+1] = namesArray[j]
            j--;
        }
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
            count++
        }
        else {
            //Replace low score if the loader board is filled
            if (count == size){
                if (score > scoresArray [0]) {
                    scoresArray[0] = score
                }
            }
            else {
                scoresArray [count] = score;
                namesArray [count] = name;
                count++''
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
