
#ifndef CODE_STRUCTNODETRIE_H
#define CODE_STRUCTNODETRIE_H

#include <stdbool.h>

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
void addLetter(struct NodeTrie* trie, char c);
void setIsWord(struct NodeTrie* trie, bool newBool);

void insertWord(struct NodeTrie* trie, char* word);
void deleteWord(struct NodeTrie* trie, char* word);
bool belongs(struct NodeTrie* trie, char* word);
bool isEmptyTrie(struct NodeTrie* trie);
int numberOfWords(struct NodeTrie* trie);
char* findWord(struct NodeTrie* trie, char* written);

char posToChar(int pos);
int charToPos(char c);



#endif //CODE_STRUCTNODETRIE_H
