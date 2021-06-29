#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>

#include "structNodeTrie.h"

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



bool belongs(struct NodeTrie* trie, char* word){
    int n = strlen(word);

    for (int i = 0; i < n; i++){

        if (word[i] == POS_SPACE){ // when the char is a space
            if (getLetters(trie)[LAST_POS_ARR] == NULL){ // the space does not exist
                return false;
            }
            trie = getLetters(trie)[LAST_POS_ARR];
        }

        if (word[i] <= 90 && word[i] >= 65){ // when the  char is uppercase
            if (getLetters(trie)[capitalChartoPos(word[i])] == NULL){
                return false;
            }
            trie = getLetters(trie)[capitalChartoPos(word[i])];
        }

        if (word[i] <= 122 && word[i] >= 97) { // when the char is in lowercase
            if (getLetters(trie)[charToPos(word[i])] == NULL) {
                return false;
            }
            trie = getLetters(trie)[charToPos(word[i])];
        }

    }
    if (getIsWord(trie)){
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

        if (word[i] == POS_SPACE){ // when the char is a space

            if (getLetters(trie)[LAST_POS_ARR] == NULL){ // the space does not exist
                *valid = false;
                return 0;
            }
            trie = getLetters(trie)[LAST_POS_ARR];
        }

        if (word[i] <= 90 && word[i] >= 65){ // when the  char is uppercase
            if (getLetters(trie)[capitalChartoPos(word[i])] == NULL){
                *valid = false;
                return 0;
            }
            trie = getLetters(trie)[capitalChartoPos(word[i])];
        }

        if (word[i] <= 122 && word[i] >= 97) { // when the char is in lowercase
            if (getLetters(trie)[charToPos(word[i])] == NULL){
                *valid = false;
                return 0;
            }
            trie = getLetters(trie)[charToPos(word[i])];
        }

    }
    if (getIsWord(trie)){
        *valid = true;
        printf("[INFO] -- Region finded\n");
        return getNumberBirths(trie);
    }

    *valid = false;
    return 0;
}

void displayRegions(struct NodeTrie* trie, int index, char* word){

    if (getIsWord(trie)){
        word[index] = '\0';
        printf("%s - ", word);
    }

    for (int i = 0; i < MAX_LETTERS; i++){

        if (getLetters(trie)[i] != NULL){ // there is a char in this position

            if (word[i] == POS_SPACE){ // when the char is a space
               word[index] = ' ';
               displayRegions(getLetters(trie)[i], index + 1, word);
            }

            if (word[i] <= 90 && word[i] >= 65){ // when the  char is uppercase
                word[index] = capitalPosToChar(i);
                displayRegions(getLetters(trie)[i], index + 1, word);
            }

            if (word[i] <= 122 && word[i] >= 97) { // when the char is in lowercase
                word[index] = posToChar(i);
                displayRegions(getLetters(trie)[i], index + 1, word);
            }
        }
    }

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









