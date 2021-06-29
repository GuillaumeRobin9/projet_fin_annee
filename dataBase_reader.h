//
// Project: projet_fin_annee
// Authors: Antoine SOYDEMIR, Guillaume ROBIN, Mickaël NERODA
// Creation date: //2021
// Modification date: //2021
// Role: Functions to display, compute the mean and invert a set of numbers.
//

#ifndef CODE_DATABASE_READER_H
#define CODE_DATABASE_READER_H

// Global Variables
#define MAX_LEN 40
#define BILLION  1000000000.0

// Includes
#include "structDataBase.h"

//-------------------------------------------------------------------------
//--- Functions Definitions -----------------------------------------------
//-------------------------------------------------------------------------

void createPersonHTMLFile(struct Person* child, struct Person* father, struct Person* mother, struct Person* PaternalGFather, struct Person* PaternalGMother, struct Person* MaternalGFather, struct Person* MaternalGMother);
void createHTMLOutput(struct dataBase* data, char *fileName,int TotalPerson);

//  ** query Result File creation **
void createQueryResHTML();

// ** query Result File filling **
void fillHTMLQuery1(int ID, struct dataBase* data);
void fillHTMLQuery2(int ID, struct dataBase* data);
void fillHTMLeQuery3(char* regionName, int numberPersonBorn);
void fillHTMLQuery4(char* regionName);
void fillHTMLQuery5(int day, int month, int numberPerson);

// ** Export query results **
void createFillQueryHTMLFile(struct dataBase* data, int* numberQueries);


#endif //CODE_DATABASE_READER_H
