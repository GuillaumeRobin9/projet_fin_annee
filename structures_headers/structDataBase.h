
#ifndef CODE_STRUCTDATABASE_H
#define CODE_STRUCTDATABASE_H

#include "structNodeTrie.h"

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
    struct NodeTrie* trie;
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

//** Insertion Function **
void insertPerson(struct Person* p, struct dataBase* data);
int insertBirth(int day, int month, struct dataBase* data);

//** data Comparaison Function **
void compareOldest(struct Person* p1, struct Person* p2, struct dataBase* data);
void compareEarliest(struct Person* p1, struct Person* p2, struct dataBase* data);

//** Suppression Function **
void deleteDataBase(struct dataBase* data); 

#endif //CODE_STRUCTDATABASE_H