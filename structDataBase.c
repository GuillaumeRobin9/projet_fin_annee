//
// Project: projet_fin_annee
// Authors: Antoine SOYDEMIR, Guillaume ROBIN, Mickaël NERODA
// Creation date: 25/06/2021
// Modification date: 29/06/2021
// Role: access/creation/suppression functions
//


// Includes
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>

#include "structDataBase.h"
#include "menu.h"


//-------------------------------------------------------------------------
//--- Functions Implementation --------------------------------------------
//-------------------------------------------------------------------------

//** Creation Function **

//
// -=[Function Description]=-
// Function that create a data base structure.
//
struct dataBase* createDataBase(int numberPerson) {

    struct dataBase* data = malloc(sizeof(struct dataBase));

    if (data == NULL) { // if malloc error
        return NULL;
    }

    data->personArray = malloc(numberPerson * sizeof (struct Person*)); // allocate memory for the person Array
    if (data->personArray == NULL){  // if malloc error
        return NULL;
    }

    data->validIndex = 0;
    data->numberPerson = numberPerson;

    for (int i = 0; i < 12; i++){ // set the matrix birthday to 0
        for (int j = 0; j < 31; j++){
            data->birthdays[i][j] = 0;
        }
    }

    for (int i = 0; i < 3; i++){ // set default value to birthdays
        data->oldestBirth[i] = 99999999;
        data->earliestBirth[i] = 0;
    }

    data->IDoldestPerson = 0;
    data->IDyoungestPerson = 0;

    //** régions **
    data->trie = createEmptyNodeTrie(); // create the node TRie
    data->maxBirths = 0;
    data->fertileRegion = NULL;

    return data;
}

//** Access Function **

//
// -=[Function Description]=-
// Function to get the person array.
//
struct Person** getPersonArray(struct dataBase* data){
    return data->personArray;
}

//
// -=[Function Description]=-
// Function to get the number array.
//
int getNumberPerson(struct dataBase* data){
    return data->numberPerson;
}

//
// -=[Function Description]=-
// Function to get the oldest.birth date
//
int* getOldestBirth(struct dataBase* data){
    return data->oldestBirth;
}

//
// -=[Function Description]=-
// Function to get the earliest birth date.
//
int* getEarliestBirth(struct dataBase* data){
    return data->earliestBirth;
}

//
// -=[Function Description]=-
// Function to get the ID of the oldest person.
//
int getOldestID(struct dataBase* data){
    return data->IDoldestPerson;
}

//
// -=[Function Description]=-
// Function to  get the ID of the youngest person.
//
int getyoungestID(struct dataBase* data){
    return data->IDyoungestPerson;
}

//
// -=[Function Description]=-
// Function to get the maximum number of birth among all the regions in the node trie.
//
int getMaxBirths(struct dataBase* data){
    return data->maxBirths;
}

//
// -=[Function Description]=-
// Function to get the node trie of the struct data base.
//
struct NodeTrie* getTrie(struct dataBase* data){
    return data->trie;
}

//
// -=[Function Description]=-
// Function to get the name of the region with the of most peoples born in.
//
char* getFertileRegion(struct dataBase* data){
    return data->fertileRegion;
}

//
// -=[Function Description]=-
// Function to get the valid index were we can insert a Person in the person array.
//
int getValidIndex(struct dataBase* data){
    return data->validIndex;
}

//
// -=[Function Description]=-
// Function to compute the mean of a set of numbers.
//
int numberBirthDates(struct dataBase* data){
    int count = 0;

    for (int i = 0; i < 12; i++){ // going threw the birthday matrix
        for (int j = 0; j < 31; j++){
            if (data->birthdays[i][j] != 0){
                count++; // increment count if a person is born to the j/i date
            }
        }
    }
    return count;
}


//
// -=[Function Description]=-
// Function to get the date when the most people are born.
//
void getDateWithMostBirths(struct dataBase* data, int* day, int* month){
    int max = 0;

    for (int i = 0; i < 12; i++){ // going threw the birthday matrix
        for (int j = 0; j < 31; j++){
            if (data->birthdays[i][j] > max){
                *day = j; // give the value of day with most births
                *month = i;
                max = data->birthdays[i][j]; // update max
            }
        }
    }
}


//
// -=[Function Description]=-
// Function that shows the infos of the DB.
//
void showGeneralInfoDataBase(struct dataBase* data){
    int day;
    int month;

    green();
    printf("\n--=|| General informations about the genealogical trees ||=--\n\n");
    reset();
    printf("number person in the tree : %d\n", getNumberPerson(data));
    printf("number of different natal regions : %d\n", numberOfWords(getTrie(data)));
    printf("number of different birthdays dates : %d\n", numberBirthDates(data));
    getDateWithMostBirths(data, &day, &month);
    printf("date with the most of births : %d/%d\n", day, month);
    printf("\n\n");
}


//** Insertion Function **

//
// -=[Function Description]=-
// Function to insert a region name in the node trie of the DB.
//
void insertWord(struct NodeTrie* trie, char* word, struct dataBase* data){
    int n = strlen(word);

    for (int i = 0; i < n; i++){

        if (word[i] == POS_SPACE){ // when the char is a space

            if (getLetters(trie)[LAST_POS_ARR] == NULL){ // the space does not exist yet
                trie->letters[LAST_POS_ARR] = createEmptyNodeTrie();
            }
            trie = getLetters(trie)[LAST_POS_ARR];
        }

        if (word[i] <= 90 && word[i] >= 65){ // when the  char is uppercase

            if (getLetters(trie)[capitalChartoPos(word[i])] == NULL){ // when the char is not in the Trie
                trie->letters[capitalChartoPos(word[i])] = createEmptyNodeTrie();
            }
            trie = getLetters(trie)[capitalChartoPos(word[i])];
        }


        if (word[i] <= 122 && word[i] >= 97) { // when the char is in lowercase
            if (getLetters(trie)[charToPos(word[i])] == NULL) { // when the char is not in the Trie
                trie->letters[charToPos(word[i])] = createEmptyNodeTrie();
            }
            trie = getLetters(trie)[charToPos(word[i])];
        }

    }
    setIsWord(trie, true); // mark the end of the word
    incrementNumberBirths(trie); // add a birth to the name of the region

    if (getNumberBirths(trie) > getMaxBirths(data)){ // update fertileRegion

        if (getFertileRegion(data) != NULL){
            free(data->fertileRegion);
        }

        data->fertileRegion = malloc( (n + 1) * sizeof(char));
        if (data->fertileRegion == NULL){
            return;
        }
        strcpy(data->fertileRegion, word); // update region name

        data->maxBirths = getNumberBirths(trie); // update value of maxBirths
    }
}

//
// -=[Function Description]=-
// Function to compute the mean of a set of numbers.
//
void insertBirth(int day, int month, struct dataBase* data){
    data->birthdays[month - 1][day - 1] = data->birthdays[month - 1][day - 1] + 1;
}


//
// -=[Function Description]=-
// Function to add a person to the data base.
//
void insertPerson(struct Person* p, struct dataBase* data) {

    getPersonArray(data)[getValidIndex(data)] = p;

//    **insertion birthday of the person in dataBase**
    insertBirth(getDay(p), getMonth(p), data);


//      **update oldest/youngest births**
    int newPersonBirth[3]; // array with the new person dates
    newPersonBirth[0] = getDay(p);
    newPersonBirth[1] = getMonth(p);
    newPersonBirth[2] = getYear(p);
    updateOldest(getOldestID(data), getOldestBirth(data), getID(p), newPersonBirth, data);
    updateYoungest(getyoungestID(data), getEarliestBirth(data), getID(p), newPersonBirth, data);

//    **insetion name region in the data Base**
    insertWord(getTrie(data), getRegion(p), data);

//    **update valid Index**
    data->validIndex = data->validIndex + 1;
}

//** data Comparaison Function **

//
// -=[Function Description]=-
// Function to compare the birthday passed with the oldest birthday.
// The oldest birthday is updated in case if the birthday passed is < to the actual oldest birthday
//
void updateOldest(int IDActualOldest, int* actualOldestBirth, int IDNewPerson, int* newPersonBirth, struct dataBase* data){

    if (newPersonBirth[2] < actualOldestBirth[2]){ // update the oldest birthday
        data->IDoldestPerson = IDNewPerson;
        getOldestBirth(data)[2] = newPersonBirth[2];
        getOldestBirth(data)[1] = newPersonBirth[1];
        getOldestBirth(data)[0] = newPersonBirth[0];
        return;
    }
    if (newPersonBirth[2] > actualOldestBirth[2]){
        return;
    }

    // here the two persons are born the same year

    if (newPersonBirth[1] < actualOldestBirth[1]){// update the oldest birthday
        data->IDoldestPerson = IDNewPerson;
        getOldestBirth(data)[2] = newPersonBirth[2];
        getOldestBirth(data)[1] = newPersonBirth[1];
        getOldestBirth(data)[0] = newPersonBirth[0];
        return;
    }
    if (newPersonBirth[1] > actualOldestBirth[1]){
        return;
    }

//    here the two persons are born the same month
    if (newPersonBirth[0] < actualOldestBirth[0]){// update the oldest birthday
        data->IDoldestPerson = IDNewPerson;
        getOldestBirth(data)[2] = newPersonBirth[2];
        getOldestBirth(data)[1] = newPersonBirth[1];
        getOldestBirth(data)[0] = newPersonBirth[0];
        return;
    }
    if (newPersonBirth[0] > actualOldestBirth[0]){
        return;
    }
//    here persons are born the same date
}

//
// -=[Function Description]=-
// Function to compare the birthday passed with the earliest birthday.
// The earliest birthday is updated in case if the birthday passed is > to the actual earliest birthday
//
void updateYoungest(int IDActualYoungest, int* actualYoungestBirth, int IDNewPerson, int* newPersonBirth, struct dataBase* data){

    if (newPersonBirth[2] > actualYoungestBirth[2]){// update the earliest birthday
        data->IDyoungestPerson = IDNewPerson;
        getEarliestBirth(data)[2] = newPersonBirth[2];
        getEarliestBirth(data)[1] = newPersonBirth[1];
        getEarliestBirth(data)[0] = newPersonBirth[0];
        return;
    }
    if (newPersonBirth[2] < actualYoungestBirth[2]){
        return;
    }

    // here the two persons are born the same year

    if (newPersonBirth[1] > actualYoungestBirth[1]){ // update the earliest birthday
        data->IDyoungestPerson = IDNewPerson;
        getEarliestBirth(data)[2] = newPersonBirth[2];
        getEarliestBirth(data)[1] = newPersonBirth[1];
        getEarliestBirth(data)[0] = newPersonBirth[0];
        return;
    }
    if (newPersonBirth[1] < actualYoungestBirth[1]){
        return;
    }

//    here the two persons are born the same month
    if (newPersonBirth[0] > actualYoungestBirth[0]){ // update the earliest birthday
        data->IDyoungestPerson = IDNewPerson;
        getEarliestBirth(data)[2] = newPersonBirth[2];
        getEarliestBirth(data)[1] = newPersonBirth[1];
        getEarliestBirth(data)[0] = newPersonBirth[0];
        return;
    }
    if (newPersonBirth[0] < actualYoungestBirth[0]){
        return;
    }
//    here persons are born the same date

}


//** Suppression Function **

//
// -=[Function Description]=-
// Function to delete the data base struct.
//
void deleteDataBase(struct dataBase* data){

    for (int i = 0; i <= getNumberPerson(data); i++){ // delete all the person of the person array
        deletePerson(getPersonArray(data)[i]);
    }
    free(data->personArray); // delete the person array

    deleteNodeTrie(data->trie); // delete the node trie

    free(data->fertileRegion); // delete de fertile region name

    free(data);
}



