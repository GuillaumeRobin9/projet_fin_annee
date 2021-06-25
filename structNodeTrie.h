//
// Created by micka on 25/06/2021.
//

#ifndef CODE_STRUCTNODETRIE_H
#define CODE_STRUCTNODETRIE_H

#include <stdbool.h>

#define MAX_LETTERS 26

struct NodeTrie{
    bool end;
    int numberBirths;
    struct NodeTrie* tab[MAX_LETTERS];
};

#endif //CODE_STRUCTNODETRIE_H
