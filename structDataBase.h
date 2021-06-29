
#ifndef CODE_STRUCTDATABASE_H
#define CODE_STRUCTDATABASE_H

#include "structNodeTrie.h"
#include "structPerson.h"

struct dataBase {
    struct Person** personArray;
    int validIndex;
    int numberPerson;

    int birthdays[12][31];
    int oldestBirth[3];
    int earliestBirth[3];
    int IDoldestPerson; //** calcul nombre de jour puis comparaison **
    int IDyoungestPerson;

    //** régions **
    struct NodeTrie* trie; // a liberer
    int maxBirths;
    char* fertileRegion;
};

//** Create Function **
struct dataBase* createDataBase(int numberPerson);


//** Access Function **

struct Person** getPersonArray(struct dataBase* data);
int getNumberPerson(struct dataBase* data);
int* getOldestBirth(struct dataBase* data);
int* getEarliestBirth(struct dataBase* data);
int getOldestID(struct dataBase* data);
int getyoungestID(struct dataBase* data);
int getMaxBirths(struct dataBase* data);
struct NodeTrie* getTrie(struct dataBase* data);
char* getFertileRegion(struct dataBase* data);
int getValidIndex(struct dataBase* data);

int numberBirthDates(struct dataBase* data);
void getDateWithMostBirths(struct dataBase* data, int* day, int* month);
void showGeneralInfoDataBase(struct dataBase* data);

//** Insertion Function **
void insertPerson(struct Person* p, struct dataBase* data);
int insertBirth(int day, int month, struct dataBase* data);
void insertWord(struct NodeTrie* trie, char* word, struct dataBase* data);

//** data Comparaison Function **
void updateOldest(int IDActualOldest, int* actualOldestBirth, int IDNewPerson, int* newPersonBirth, struct dataBase* data);
void updateYoungest(int IDActualYoungest, int* actualYoungestBirth, int IDNewPerson, int* newPersonBirth, struct dataBase* data);

//** Print Database **
void printDataBase(struct dataBase* data);


//** Suppression Function **
void deleteDataBase(struct dataBase* data); 

#endif //CODE_STRUCTDATABASE_H