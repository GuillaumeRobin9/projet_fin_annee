#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "structures_headers/structNodeTrie.h"

#define POS_A 97

struct NodeTrie* createEmptyNodeTrie(){
    struct NodeTrie* newTrie = malloc(sizeof(struct NodeTrie));

    if (newTrie != NULL) {
        int numberBirths = 0;
        newTrie->isWord = false;
        for (int i = 0; i < MAX_LETTERS; i++) {
            newTrie->letters[i] = NULL;
        }
    }
    return newTrie;
}

void deleteNodeTrie(struct NodeTrie* trie){

    for (int i = 0; i < MAX_LETTERS; i++){
        if (getLetters(trie)[i] != NULL){
            deleteNodeTrie(getLetters(trie)[i]);
        }
    }
    free(trie);
    return;
}

struct NodeTrie** getLetters(struct NodeTrie* trie){
    return trie->letters;
}
bool getIsWord(struct NodeTrie* trie){
    return trie->isWord;
}
void addLetter(struct NodeTrie* trie, char c){
    trie->letters[charToPos(c)] = createEmptyNodeTrie();
}
void setIsWord(struct NodeTrie* trie, bool newBool){
    trie->isWord = newBool;
}

void insertWord(struct NodeTrie* trie, char* word){
    int n = strlen(word);
    struct NodeTrie* triePointer = trie;

    for (int i = 0; i < n; i++){
        if (getLetters(triePointer)[charToPos(word[i])] == NULL){
            addLetter(triePointer, word[i]);
        }
        triePointer = getLetters(triePointer)[charToPos(word[i])];
    }

    setIsWord(triePointer, true);
}

void deleteWord(struct NodeTrie* trie, char* word){ // a finir ! a corriger ! a changer !
    if(!belongs(trie, word)){
        printf("In function deleteWord : the word you want to delete does not exist\n");
        return;
    }

    int n = strlen(word);
    struct NodeTrie* triePointer = trie;
    struct NodeTrie* last = trie;
    int lastIndex = 0;
    for (int i = 0; i < n; i++){
        if (getIsWord(triePointer)){
            last = triePointer;
            lastIndex = i;
        }
        triePointer = getLetters(triePointer)[charToPos(word[i])];
    }

    triePointer = getLetters(last)[charToPos(word[lastIndex])];

    struct NodeTrie* next = getLetters(triePointer)[charToPos(word[lastIndex+1])];

    for (int i = lastIndex+1; i < n-1; i++){
        triePointer = next;
        next = getLetters(triePointer)[charToPos(word[i+1])];
        free(triePointer);
    }
    triePointer = next;
    free(triePointer); // vérifier que pas de mots après !!!
}

bool belongs(struct NodeTrie* trie, char* word){
    int n = strlen(word);
    struct NodeTrie* triePointer = trie;

    for (int i = 0; i < n; i++){
        if (getLetters(triePointer)[charToPos(word[i])] == NULL){
            return false;
        }
        triePointer = getLetters(triePointer)[charToPos(word[i])];
    }
    if (getIsWord(triePointer)){
        return true;
    }
    return false;
}

bool isEmptyTrie(struct NodeTrie* trie){
    for (int i = 0; i < MAX_LETTERS; i++){
        if (getLetters(trie)[i] != NULL){
            return false;
        }
    }
    return true;
}

int numberOfWords(struct NodeTrie* trie){
    int n = 0;

    for (int i = 0; i < MAX_LETTERS; i++){
        if (getLetters(trie)[i] != NULL){
            n += numberOfWords(getLetters(trie)[i]);
        }
    }

    if (getIsWord(trie)){
        n++;
    }

    return n;
}

char* findWord(struct NodeTrie* trie, char* written){
    int n = strlen(written);
    struct NodeTrie* triePointer = trie;
    for (int i = 0; i < n; i++){
        triePointer = getLetters(triePointer)[charToPos(written[i])];
    }

    char chars[30];
    int nb = 0;
    while (!getIsWord(triePointer)){
        int i = 0;
        while (getLetters(triePointer)[i] == NULL){
            i++;
        }
        chars[nb] = posToChar(i);
        nb++;
        triePointer = getLetters(triePointer)[i];
    }

    char* word = malloc((n + nb + 1) * sizeof(char));

    for (int i = 0; i < n; i++){
        word[i] = written[i];
    }
    for (int i = 0; i < nb; i++){
        word[i + n] = chars[i];
    }

    return word;
}

char posToChar(int pos){
    return pos+POS_A;
}
int charToPos(char c){
    return c-POS_A;
}