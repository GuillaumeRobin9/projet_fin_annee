//
// Project: projet_fin_annee
// Authors: Antoine SOYDEMIR, Guillaume ROBIN, Mickaël NERODA
// Creation date: //2021
// Modification date: //2021
// Role: Functions to create the HTML files listed here :
//      - HTML page with the result of the queries.
//      - HTML index page with the general informations about the trees
//      - HTML tree pages for each person of the data base.

#ifndef CODE_HTMLGENERATOR_H
#define CODE_HTMLGENERATOR_H

// Global Variables
#define MAX_LEN 40
#define BILLION  1000000000.0

// Includes
#include "structDataBase.h"

//-------------------------------------------------------------------------
//--- Functions Definitions -----------------------------------------------
//-------------------------------------------------------------------------

void createPersonHTMLFile(struct Person* child, struct Person* father, struct Person* mother, struct Person* PaternalGFather, struct Person* PaternalGMother, struct Person* MaternalGFather, struct Person* MaternalGMother);
void createIndexHTMLFile(struct dataBase* data, char *fileName,int TotalPerson);

//  ** query Result File creation **
void createQueryResHTML();


// ** Export query results **
void createFillQueryHTMLFile(struct dataBase* data, int* numberQueries);

// ** query Result File filling **
void fillHTMLQuery1(int ID, struct dataBase* data);
void fillHTMLQuery2(int ID, struct dataBase* data);
void fillHTMLeQuery3(char* regionName, int numberPersonBorn);
void fillHTMLQuery4(char* regionName);
void fillHTMLQuery5(int day, int month, int numberPerson);

#endif //CODE_HTMLGENERATOR_H
