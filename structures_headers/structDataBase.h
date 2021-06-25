//
// Created by micka on 25/06/2021.
//

#ifndef CODE_STRUCTDATABASE_H
#define CODE_STRUCTDATABASE_H

#define MAX_PERSON 10000 // utiliser plutot la valeur de la première ligne de la base de donnée

struct dataBase {
    struct Person* personArray[MAX_PERSON];
    int numberPerson;

    int birthdays[12][31];
    int oldestBirth;
    int earliestBirth;
    int IDoldestPerson; //calcul nombre de jour puis comparaison
    int IDyoungestPerson;

    // régions
    struct NodeTrie* trie;
    int maxBirths;
    char* fertileRegion;
}

struct dataBase* createEmptyDataBase();

#endif //CODE_STRUCTDATABASE_H
