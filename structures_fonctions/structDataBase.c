
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>

#include "structures_headers/structDataBase.h"
#include "structures_headers/structPerson.h"
#include "structures_headers/structNodeTrie.h"

struct dataBase* createEmptyDataBase(int numberPerson) {

    struct dataBase* base = malloc(sizeof(struct dataBase));

    if (base == NULL) {
        return NULL;
    }

    base->personArray = malloc(numberPerson * sizeof (struct Person*));
    if (base->personArray == NULL){
        return NULL;
    }

    base->numberPerson = numberPerson;
    for (int i = 0; i < 12; i++){
        for (int j = 0; j < 31; j++){
            base->birthdays[i][j] = 0;
        }
    }
    base->oldestBirth = 0;
    base->earliestBirth = 999999999;
    base->IDoldestPerson = 0;
    base->IDyoungestPerson = 0;

    //** régions **
    base->trie = createEmptyNodeTrie();
    base->maxBirths = 0;

}

int getDayOfBirth(int day, int month, struct dataBase* data){
    return data->birthdays[month-1][day-1];
}

int getAllPerson(struct dataBase* data){
    return data->numberPerson;
}

int getOldestBirth(struct dataBase* data){
    return data->oldestBirth;
}

int getEarliestBirth(struct dataBase* data){
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
