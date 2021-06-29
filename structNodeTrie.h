//
// Project: projet_fin_annee
// Authors:  Mickaël NERODA
// Creation date: //2021
// Modification date: //2021
// Role: declare struct Node Trie, and access/creation/suppression functions
//

#ifndef CODE_STRUCTNODETRIE_H
#define CODE_STRUCTNODETRIE_H

// Includes
#include <stdbool.h>
#include "structDataBase.h"

// Global Variables
#define MAX_LETTERS 27
#define POS_A 97
#define POS_A_CAPITAL 65
#define POS_SPACE 32
#define LAST_POS_ARR 26


//-------------------------------------------------------------------------
//--- Structure Definition ------------------------------------------------
//-------------------------------------------------------------------------
struct NodeTrie{
    bool isWord;
    int numberBirths;
    struct NodeTrie* letters[MAX_LETTERS];
};


//-------------------------------------------------------------------------
//--- Functions Definitions -----------------------------------------------
//-------------------------------------------------------------------------

//** Creation Function **
struct NodeTrie* createEmptyNodeTrie();

//** Suppression Function **
void deleteNodeTrie(struct NodeTrie* trie);

//** Access Functions **
struct NodeTrie** getLetters(struct NodeTrie* trie);
bool getIsWord(struct NodeTrie* trie);
bool isEmptyTrie(struct NodeTrie* trie);
int getNumberBirths(struct NodeTrie* trie);

// ** Insertion/Search Functions **
bool belongs(struct NodeTrie* trie, char* word);
int numberOfWords(struct NodeTrie* trie);
int findBirthsOfRegion(struct NodeTrie* trie, char* word, bool* valid);
void displayRegions(struct NodeTrie* trie, int index, char* word);

//** Convertions **
char capitalPosToChar(int pos);
char posToChar(int pos);
int charToPos(char c);
int capitalChartoPos(char c);

// **update functions **
void setIsWord(struct NodeTrie* trie, bool newBool);
void incrementNumberBirths(struct NodeTrie* trie);



#endif //CODE_STRUCTNODETRIE_H
