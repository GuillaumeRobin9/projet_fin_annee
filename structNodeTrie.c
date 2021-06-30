//
// Project: projet_fin_annee
// Authors: Mickaël NERODA
// Creation date: 25/06/2021
// Modification date: 29/06/2021
// Role: access/creation/suppression functions
//


// Includes
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>

#include "structNodeTrie.h"

//-------------------------------------------------------------------------
//--- Functions Implementation --------------------------------------------
//-------------------------------------------------------------------------

//** Creation Function **
//
// -=[Function Description]=-
// Function to create an Empty node trie.
//
struct NodeTrie* createEmptyNodeTrie(){
    struct NodeTrie* newTrie = malloc(sizeof(struct NodeTrie));

    if (newTrie != NULL) {
        newTrie->numberBirths = 0;
        newTrie->isWord = false;
        for (int i = 0; i < MAX_LETTERS; i++) { // put the letter array to NULL
            newTrie->letters[i] = NULL;
        }
    }
    return newTrie;
}

//** Suppression Function **

//
// -=[Function Description]=-
// Function to delete a node trie.
//
void deleteNodeTrie(struct NodeTrie* trie){

    for (int i = 0; i < MAX_LETTERS; i++){
        if (getLetters(trie)[i] != NULL){
            deleteNodeTrie(getLetters(trie)[i]);
        }
    }
    free(trie);
}

//** Access Functions **

//
// -=[Function Description]=-
// Function to get the letter array of node trie.
//
struct NodeTrie** getLetters(struct NodeTrie* trie){
    return trie->letters;
}

//
// -=[Function Description]=-
// Function that say if the node is the end of a word.
//
bool getIsWord(struct NodeTrie* trie){
    return trie->isWord;
}


//
// -=[Function Description]=-
// Function to value of numberBirth of a node.
//
int getNumberBirths(struct NodeTrie* trie){
    return trie->numberBirths;
}

//
// -=[Function Description]=-
// Function thet say if the trie is empty.
//
bool isEmptyTrie(struct NodeTrie* trie){
    for (int i = 0; i < MAX_LETTERS; i++){
        if (getLetters(trie)[i] != NULL){
            return false;
        }
    }
    return true;
}


// ** Insertion/Search Functions **


//
// -=[Function Description]=-
// Function that give the number of region name in the trie.
//
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


//
// -=[Function Description]=-
// Function that give the number of Births in the gived region.
//
int findBirthsOfRegion(struct NodeTrie* trie, char* word, bool* valid){

    int n = strlen(word);

    for (int i = 0; i < n; i++){ // getting threw all the characters of the word entered

        if (word[i] == POS_SPACE){ // when the char is a space

            if (getLetters(trie)[LAST_POS_ARR] == NULL){ // the space does not exist
                *valid = false;
                return 0;
            }
            trie = getLetters(trie)[LAST_POS_ARR]; // going to the next node
        }

        if (word[i] <= 90 && word[i] >= 65){ // when the  char is uppercase
            if (getLetters(trie)[capitalChartoPos(word[i])] == NULL){
                *valid = false;
                return 0;
            }
            trie = getLetters(trie)[capitalChartoPos(word[i])]; // going to the next node
        }

        if (word[i] <= 122 && word[i] >= 97) { // when the char is in lowercase
            if (getLetters(trie)[charToPos(word[i])] == NULL){
                *valid = false;
                return 0;
            }
            trie = getLetters(trie)[charToPos(word[i])]; // going to the next node
        }

    }
    if (getIsWord(trie)){ // if the last node reached is the end of a word, we return the number of birthday of the actual node
        *valid = true;
        printf("[INFO] -- Region find\n");
        return getNumberBirths(trie);
    }

    *valid = false;
    return 0;
}


//
// -=[Function Description]=-
// Function that show all the regions of the node trie.
//
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

//
// -=[Function Description]=-
// Function to convert a ascii cde of a uppercase letter in a char.
//
char capitalPosToChar(int pos){
    return pos + POS_A_CAPITAL;
}


//
// -=[Function Description]=-
// Function to convert a ascii code of a lowercase letter in a char.
//
char posToChar(int pos){
    return pos + POS_A;
}


//
// -=[Function Description]=-
// Function convert a uppercase char in a index of the letter array
//
int capitalChartoPos(char c){
    return c - POS_A_CAPITAL;
}


//
// -=[Function Description]=-
// Function convert a lowercase char in a index of the letter array
//
int charToPos(char c){
    return c - POS_A;
}

// **update functions **

//
// -=[Function Description]=-
// Function to set a node as a end of the word
//
void setIsWord(struct NodeTrie* trie, bool newBool){
    trie->isWord = newBool;
}


//
// -=[Function Description]=-
// Function to increment the numberBirth value.
//
void incrementNumberBirths(struct NodeTrie* trie){
    trie->numberBirths = trie->numberBirths + 1;
}











