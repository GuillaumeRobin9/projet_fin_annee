
#ifndef PROJET_FILE1_H
#define MAX_PERSON 10000
#define MAX_LETTERS 26
//separer.h
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

struct Person {
    int ID;
    int IDfather;
    int IDmother;
    int children[];
    char* lastName;
    char* firstName;
    int day;
    int month;
    int year;
    char* region;
}

struct NodeTrie{
    bool end;
    int numberBirths;
    struct NodeTrie* tab[MAX_LETTERS];
};

struct dataBase* createEmptyDataBase();

#define PROJET_FILE1_H

#endif
