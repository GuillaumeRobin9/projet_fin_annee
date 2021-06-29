//
// Project: projet_fin_annee
// Authors: Guillaume ROBIN, Mickaël NERODA
// Creation date: 25/06/2021
// Modification date: 29/06/2021
// Role: create and fill the database from the CSV file => create an empty data base, read the CSV file, create persons from the infos from the CSV,
// and adding the persons created to the data base
//

#ifndef PROJET_FILE_READER_H
#define PROJET_FILE_READER_H

// Global Variables
#define MAX_CHAR 1000
#define BILLION  1000000000.0

//-------------------------------------------------------------------------
//--- Functions Definitions -----------------------------------------------
//-------------------------------------------------------------------------

struct dataBase* readFile(char *nameFile);

#endif 
