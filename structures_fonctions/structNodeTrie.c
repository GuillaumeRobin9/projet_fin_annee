#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "structures_headers/structNodeTrie.h"

struct NodeTrie* createEmptyNodeTrie(){
    struct NodeTrie* newTrie = malloc(sizeof(struct NodeTrie));

    if (newTrie != NULL) {
        int numberBirths;
        //newTrie->isWord = false;
        for (int i = 0; i < MAX_LETTERS; i++) {
            newTrie->tab[i] = NULL;
        }
    }

    return newTrie;
}
