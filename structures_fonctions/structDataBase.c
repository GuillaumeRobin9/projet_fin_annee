
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>

#include "structures_headers/structDataBase.h"
#include "structures_headers/structPerson.h"
#include "structures_headers/structNodeTrie.h"

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
        data->oldestBirth[i] = 0;
        data->earliestBirth[i] = 99999999;
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

int insertBirth(int day, int month, struct dataBase* data){
    data->birthdays[month][day] += 1;
}


void insertPerson(struct Person* p, struct dataBase* data) {

    getPersonArray(data)[getValidIndex(data)] = p;
    data->validIndex = getValidIndex(data) + 1;

//    **insertion birthday of the person in dataBase**
    insertBirth(getDay(p), getMonth(p), data);

//      **update oldest/youngest births**
    compareOldest(getPersonArray(data)[getOldestID(data)], p, data);
    compareEarliest(getPersonArray(data)[getyoungestID(data)], p, data);

    // inserer la région dans le trie

    data->validIndex = data->validIndex + 1;
}


void compareOldest(struct Person* p1, struct Person* p2, struct dataBase* data){
    if(p1->year > p2->year){
        data->IDoldestPerson = getID(p1);
        data->oldestBirth[0] = getDay(p1);
        data->oldestBirth[1] = getMonth(p1);
        data->oldestBirth[2] = getYear(p1);
    }
    if(p1->year == p2->year && p1->month > p2->month){
        data->IDoldestPerson = getID(p1);
        data->oldestBirth[0] = getDay(p1);
        data->oldestBirth[1] = getMonth(p1);
        data->oldestBirth[2] = getYear(p1);
    }
    if(p1->year == p2->year && p1->month == p2->month && p1->day > p2->day){
        data->IDoldestPerson = getID(p1);
        data->oldestBirth[0] = getDay(p1);
        data->oldestBirth[1] = getMonth(p1);
        data->oldestBirth[2] = getYear(p1);
    } else{
        data->IDoldestPerson = getID(p2);
        data->oldestBirth[0] = getDay(p2);
        data->oldestBirth[1] = getMonth(p2);
        data->oldestBirth[2] = getYear(p2);
    }

}

void compareEarliest(struct Person* p1, struct Person* p2, struct dataBase* data){
    if(p1->year > p2->year){
        data->IDoldestPerson = getID(p2);
        data->oldestBirth[0] = getDay(p2);
        data->oldestBirth[1] = getMonth(p2);
        data->oldestBirth[2] = getYear(p2);
    }
    if(p1->year == p2->year && p1->month > p2->month){
        data->IDoldestPerson = getID(p2);
        data->oldestBirth[0] = getDay(p2);
        data->oldestBirth[1] = getMonth(p2);
        data->oldestBirth[2] = getYear(p2);
    }
    if(p1->year == p2->year && p1->month == p2->month && p1->day > p2->day){
        data->IDoldestPerson = getID(p2);
        data->oldestBirth[0] = getDay(p2);
        data->oldestBirth[1] = getMonth(p2);
        data->oldestBirth[2] = getYear(p2);
    } else{
        data->IDoldestPerson = getID(p1);
        data->oldestBirth[0] = getDay(p1);
        data->oldestBirth[1] = getMonth(p1);
        data->oldestBirth[2] = getYear(p1);
    }
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



