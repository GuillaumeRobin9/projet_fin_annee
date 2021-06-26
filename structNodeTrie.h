
#ifndef CODE_STRUCTNODETRIE_H
#define CODE_STRUCTNODETRIE_H

#include <stdbool.h>

#include "structDataBase.h"


#define MAX_LETTERS 26

struct NodeTrie{
    bool isWord;
    int numberBirths;
    struct NodeTrie* letters[MAX_LETTERS];
};


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
void addLetter(struct NodeTrie* trie, char c);
void insertWord(struct NodeTrie* trie, char* word, struct dataBase* data);
void deleteWord(struct NodeTrie* trie, char* word);
bool belongs(struct NodeTrie* trie, char* word);
int numberOfWords(struct NodeTrie* trie);
void numberOfWords2(struct NodeTrie* trie, int* count);
char* findWord(struct NodeTrie* trie, char* written);
int findBirthsOfRegion(struct NodeTrie* trie, char* word, bool* valid);

//** Convertions **
char posToChar(int pos);
int charToPos(char c);
int capitalChartoPos(char c);

// **update functions **
void setIsWord(struct NodeTrie* trie, bool newBool);
void incrementNumberBirths(struct NodeTrie* trie);



#endif //CODE_STRUCTNODETRIE_H
