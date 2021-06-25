
#ifndef CODE_STRUCTDATABASE_H
#define CODE_STRUCTDATABASE_H

#include "structNodeTrie.h"

struct dataBase {
    struct Person** personArray;
    int numberPerson;

    int birthdays[12][31];
    int oldestBirth;
    int earliestBirth;
    int IDoldestPerson; //** calcul nombre de jour puis comparaison **
    int IDyoungestPerson;

    //** régions **
    struct NodeTrie* trie;
    int maxBirths;
    char* fertileRegion;
}

struct dataBase* createEmptyDataBase(int numberPerson);

//** Access Function **

int getAllPerson(struct dataBase* data);
int getOldestBirth(struct dataBase* data);
int getEarliestBirth(struct dataBase* data);
int getOldestID(struct dataBase* data);
int getyoungestID(struct dataBase* data);
int getMaxBirths(struct dataBase* data);
int getDayOfBirth(int day, int month, struct dataBase* data);
struct NodeTrie* getTrie(struct dataBase* data);
char* getFertileRegion(struct dataBase* data);

#endif //CODE_STRUCTDATABASE_H