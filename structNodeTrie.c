#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "structNodeTrie.h"

#define POS_A 97
#define POS_A_CAPITAL 65

struct NodeTrie* createEmptyNodeTrie(){
    struct NodeTrie* newTrie = malloc(sizeof(struct NodeTrie));

    if (newTrie != NULL) {
        newTrie->numberBirths = 0;
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
}

struct NodeTrie** getLetters(struct NodeTrie* trie){
    return trie->letters;
}
bool getIsWord(struct NodeTrie* trie){
    return trie->isWord;
}

int getNumberBirths(struct NodeTrie* trie){
    return trie->numberBirths;
}

void setIsWord(struct NodeTrie* trie, bool newBool){
    trie->isWord = newBool;
}

void incrementNumberBirths(struct NodeTrie* trie){
    trie->numberBirths = trie->numberBirths + 1;
}

void insertWord(struct NodeTrie* trie, char* word, struct dataBase* data){
    int n = strlen(word);

    for (int i = 0; i < n; i++){

        if (word[i] <= 90 && word[i] >= 65){ // when the  char is uppercase

            if (getLetters(trie)[capitalChartoPos(word[i])] == NULL){ // when the char is not in the Trie
                struct NodeTrie* newTrie = createEmptyNodeTrie();
                getLetters(trie)[capitalChartoPos(word[i])] = newTrie;
                trie = newTrie;

//                printf("%c\n", capitalPosToChar(word[i]));
            }
            else { // when the char is already in the trie
                trie = getLetters(trie)[capitalChartoPos(word[i])];

                printf("%c\n", capitalPosToChar(word[i]));
            }
        }
        else {

            if (word[i] <= 122 && word[i] >= 97) { // when the char is in lowercase
                if (getLetters(trie)[charToPos(word[i])] == NULL) { // when the char is not in the Trie
                    struct NodeTrie *newTrie = createEmptyNodeTrie();
                    getLetters(trie)[charToPos(word[i])] = newTrie;
                    trie = newTrie;

//                    printf("%c\n", posToChar(word[i]));
                } else { // when the char is already in the trie
                    trie = getLetters(trie)[charToPos(word[i])];

//                    printf("%c\n", posToChar(word[i]));
                }
            }
            // here the char is a space, so we go to the next char of the word without adding something to the Trie
        }
    }
    setIsWord(trie, true); // mark the end of the word
    incrementNumberBirths(trie); // add a birth to the name of the region

    if (getNumberBirths(trie) > getMaxBirths(data)){ // update fertileRegion
        data->fertileRegion = malloc( (n + 1) * sizeof(char));
        if (data->fertileRegion == NULL){
            return;
        }
        strcpy(data->fertileRegion, word); // update region name

        data->maxBirths = getNumberBirths(trie); // update value of maxBirths
    }
}


bool belongs(struct NodeTrie* trie, char* word){
    int n = strlen(word);
    struct NodeTrie* triePointer = trie;

    for (int i = 0; i < n; i++){

        if (word[i] <= 90 && word[i] >= 65){ // when the  char is uppercase
            if (getLetters(triePointer)[capitalChartoPos(word[i])] == NULL){
                return false;
            }
            triePointer = getLetters(triePointer)[capitalChartoPos(word[i])];
        }
        else {
            if (word[i] <= 122 && word[i] >= 97) { // when the char is in lowercase
                if (getLetters(triePointer)[charToPos(word[i])] == NULL) {
                    return false;
                }
                triePointer = getLetters(triePointer)[charToPos(word[i])];
            }
        }
        // here the char is a space, so we go to the next char of the word without adding something to the Trie
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

int numberOfWords(struct NodeTrie* trie){ // Option 1 numberOfWords
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


int findBirthsOfRegion(struct NodeTrie* trie, char* word, bool* valid){

    int n = strlen(word);

    for (int i = 0; i < n; i++){
        printf("%c\n", word[i]);

        if (word[i] <= 90 && word[i] >= 65){ // when the  char is uppercase
//            printf("%c\n", word[i]);
            if (getLetters(trie)[capitalChartoPos(word[i])] == NULL){
                *valid = false;
                return 0;
            }
            trie = getLetters(trie)[capitalChartoPos(word[i])];
        }
        else {
            if (word[i] <= 122 && word[i] >= 97) { // when the char is in lowercase
//                printf("%c\n", word[i]);
                *valid = false;
                return 0;
            }
            trie = getLetters(trie)[charToPos(word[i])];
        }
//        printf("%c\n", word[i]);

        // here the char is a space, so we go to the next char of the word without adding something to the Trie
    }
    if (getIsWord(trie)){
        *valid = true;
        return getNumberBirths(trie);
    }

    *valid = false;
    return 0;
}

//** Convertions **
char capitalPosToChar(int pos){
    return pos + POS_A_CAPITAL;
}

char posToChar(int pos){
    return pos + POS_A;
}

int capitalChartoPos(char c){
    return c - POS_A_CAPITAL;
}

int charToPos(char c){
    return c - POS_A;
}









