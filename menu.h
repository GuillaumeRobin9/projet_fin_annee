//
// Created by micka on 27/06/2021.
//

#ifndef CODE_MENU_H
#define CODE_MENU_H

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <unistd.h>

#include "structDataBase.h"
#include "dataBase_reader.h"

#define MAX_LEN 40
#define BILLION  1000000000.0


// ** menu fonction **
void queryMenu(struct dataBase* data);

// ** option choice Functions
void HTMLFamilyTreeOption(struct dataBase* data, int* exportFamilyCount);
void HTMLInfoTreeOption(struct dataBase* data, int* exportInfoCount,char* fileName);

// ** pure execution functions **
void exportHTMLFamilyTree(struct dataBase* data);

// ** color font functions **  
void red ();
void green ();
void reset ();

#endif //CODE_MENU_H
