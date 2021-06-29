//
// Project: projet_fin_annee
// Authors: Antoine SOYDEMIR, Guillaume ROBIN, Mickaël NERODA
// Creation date: 27/06/2021
// Modification date: 29/06/2021
// Role: Functions to display the query menu, .
//

#ifndef CODE_MENU_H
#define CODE_MENU_H

// Includes
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <unistd.h>

#include "structDataBase.h"
#include "htmlGenerator.h"

// Global Variables
#define MAX_LEN 40
#define BILLION  1000000000.0


//-------------------------------------------------------------------------
//--- Functions Definitions -----------------------------------------------
//-------------------------------------------------------------------------

// ** color font functions **
void red ();
void green ();
void reset ();

// ** query menu **
void queryMenu(struct dataBase* data);

// ** option choice Functions **
void HTMLFamilyTreeOption(struct dataBase* data, int* exportFamilyCount);
void HTMLInfoTreeOption(struct dataBase* data, int* exportInfoCount,char* fileName);

// ** other execution functions **
void exportHTMLFamilyTree(struct dataBase* data);


#endif //CODE_MENU_H
