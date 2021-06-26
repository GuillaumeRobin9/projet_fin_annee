
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>

#include "structDataBase.h"
//#include "structPerson.h"
//#include "structNodeTrie.h"

//** Create Function **
struct dataBase* createDataBase(int numberPerson) {

    struct dataBase* data = malloc(sizeof(struct dataBase));

    if (data == NULL) {
        return NULL;
    }

    data->personArray = malloc(numberPerson * sizeof (struct Person*));
    if (data->personArray == NULL){
        return NULL;
    }

    data->validIndex = 0;
    data->numberPerson = numberPerson;

    for (int i = 0; i < 12; i++){
        for (int j = 0; j < 31; j++){
            data->birthdays[i][j] = 0;
        }
    }

    for (int i = 0; i < 3; i++){
        data->oldestBirth[i] = 99999999;
        data->earliestBirth[i] = 0;
    }

    data->IDoldestPerson = 0;
    data->IDyoungestPerson = 0;

    //** régions **
    data->trie = createEmptyNodeTrie();
    data->maxBirths = 0;
    data->fertileRegion = NULL;

    return data;
}

//** Access Function **
struct Person** getPersonArray(struct dataBase* data){
    return data->personArray;
}

int getNumberPerson(struct dataBase* data){
    return data->numberPerson;
}

int** getBirthdayArray(struct dataBase* data){
    return data->birthdays;
}

int* getOldestBirth(struct dataBase* data){
    return data->oldestBirth;
}

int* getEarliestBirth(struct dataBase* data){
    return data->earliestBirth;
}

int getOldestID(struct dataBase* data){
    return data->IDoldestPerson;
}

int getyoungestID(struct dataBase* data){
    return data->IDyoungestPerson;
}

int getMaxBirths(struct dataBase* data){
    return data->maxBirths;
}

struct NodeTrie* getTrie(struct dataBase* data){
    return data->trie;
}

char* getFertileRegion(struct dataBase* data){
    return data->fertileRegion;
}

int getValidIndex(struct dataBase* data){
    return data->validIndex;
}



//** Insertion Function **
int insertBirth(int day, int month, struct dataBase* data){
    return data->birthdays[month - 1][day - 1] += 1;
}


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
void updateOldest(int IDActualOldest, int* actualOldestBirth, int IDNewPerson, int* newPersonBirth, struct dataBase* data){

    if (newPersonBirth[2] < actualOldestBirth[2]){
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

    if (newPersonBirth[1] < actualOldestBirth[1]){
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
    if (newPersonBirth[0] < actualOldestBirth[0]){
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

void updateYoungest(int IDActualYoungest, int* actualYoungestBirth, int IDNewPerson, int* newPersonBirth, struct dataBase* data){

    if (newPersonBirth[2] > actualYoungestBirth[2]){
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

    if (newPersonBirth[1] > actualYoungestBirth[1]){
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
    if (newPersonBirth[0] > actualYoungestBirth[0]){
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

//** Print Database **
void printDataBase(struct dataBase* data){

    if (data == NULL){
        return;
    }

    printf("\n\n--------------=|| DATA BASE INFO's ||=--------------\n\n");

    printf("Valid Index value : %d\n", getValidIndex(data));
    printf("number of Person : %d\n", getNumberPerson(data));

//    for (int i = 0; i < 12; i++){
//        for (int j = 0; j < 31; j++){
//            printf("%d / %d => number Births this date : %d \n", j + 1, i + 1, data->birthdays[i][j]);
//        }
//    }

    printf("Oldest Birth in Database : %d/%d/%d\n", getOldestBirth(data)[0], getOldestBirth(data)[1], getOldestBirth(data)[2]);
    printf("Earliest Birth in Database : %d/%d/%d\n", getEarliestBirth(data)[0], getEarliestBirth(data)[1], getEarliestBirth(data)[2]);

    printf("ID of the Oldest Person : %d\n", getOldestID(data));
    printf("ID of the Youngest Person : %d\n", getyoungestID(data));

    printf("Max Births : %d\n", getMaxBirths(data));
    printf("Most Fertile Region : %s\n", getFertileRegion(data));

    printf("--------------=|| END INFO's ||=--------------\n\n");
}





//** Suppression Function **
void deleteDataBase(struct dataBase* data){

    for (int i = 0; i < getNumberPerson(data); i++){
        deletePerson(getPersonArray(data)[i]);
    }

    deleteNodeTrie(data->trie);
    free(data->fertileRegion);
    free(data);

}



