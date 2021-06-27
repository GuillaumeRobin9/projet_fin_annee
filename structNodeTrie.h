
#ifndef CODE_STRUCTNODETRIE_H
#define CODE_STRUCTNODETRIE_H

#include <stdbool.h>

#include "structDataBase.h"


#define MAX_LETTERS 27

struct NodeTrie{
    bool isWord;
    int numberBirths;
    struct NodeTrie* letters[MAX_LETTERS];
};


//** Creation Function **
struct NodeTrie* createEmptyNodeTrie();

//** Suppression Function **
void deleteNodeTrie(struct NodeTrie* trie); // a tester

//** Access Functions **
struct NodeTrie** getLetters(struct NodeTrie* trie);
bool getIsWord(struct NodeTrie* trie);
bool isEmptyTrie(struct NodeTrie* trie);
int getNumberBirths(struct NodeTrie* trie);

// ** Insertion/Search Functions **
void insertWord(struct NodeTrie* trie, char* word, struct dataBase* data);
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
