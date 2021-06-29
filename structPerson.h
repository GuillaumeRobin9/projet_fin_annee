//
// Project: projet_fin_annee
// Authors: Antoine SOYDEMIR, Guillaume ROBIN, Mickaël NERODA
// Creation date: 25/06/2021
// Modification date: 29/06/2021
// Role: declare struct Person, and access/creation/suppression functions
//

#ifndef CODE_STRUCTPERSON_H
#define CODE_STRUCTPERSON_H


//-------------------------------------------------------------------------
//--- Structure Definition ------------------------------------------------
//-------------------------------------------------------------------------
struct Person {
    int ID;
    int IDfather;
    int IDmother;
//    int children[];
    char* lastName;
    char* firstName;
    int day;
    int month;
    int year;
    char* region;
};

//-------------------------------------------------------------------------
//--- Functions Definitions -----------------------------------------------
//-------------------------------------------------------------------------

//** Creation Function **
struct Person* createPerson(int ID, int IDf, int IDm, char* lastN, char* firstN, int day, int month, int year, char* region);
struct Person* createEmptyPerson();


//** Access Functions **

void printPerson(struct Person* p);
int getID(struct Person* p);
int getFatherID(struct Person* p);
int getMotherID(struct Person *p);
char* getLastName(struct Person *p);
char* getFirstName(struct Person *p);
int getDay(struct Person* p);
int getMonth(struct Person* p);
int getYear(struct Person* p);
char* getRegion(struct Person* p);

//** Suppression Function **
void deletePerson(struct Person* p);

#endif //CODE_STRUCTPERSON_H
