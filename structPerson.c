//
// Project: projet_fin_annee
// Authors: Antoine SOYDEMIR, Guillaume ROBIN, Mickaël NERODA
// Creation date: 25/06/2021
// Modification date: 29/06/2021
// Role: access/creation/suppression functions
//

// Includes
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>

#include "structPerson.h"


//-------------------------------------------------------------------------
//--- Functions Implementation --------------------------------------------
//-------------------------------------------------------------------------


//** Creation Function **
//
// -=[Function Description]=-
// Function to create a Person.
//
struct Person* createPerson(int ID, int IDf, int IDm, char* lastN, char* firstN, int day, int month, int year, char* region){

    struct Person* p = malloc(sizeof(struct Person));

    if (p == NULL){
        return NULL;
    }

    p->ID = ID;
    p->IDfather = IDf;
    p->IDmother = IDm;
    p->day = day;
    p->month = month;
    p->year = year;


//    copy last name
    p->lastName = malloc( (strlen(lastN) + 1) * sizeof(char));
    if (p->lastName == NULL){
        return NULL;
    }
    strcpy(p->lastName, lastN);

//    copy first name
    p->firstName = malloc( (strlen(firstN) + 1) * sizeof(char));
    if (p->firstName == NULL){
        return NULL;
    }
    strcpy(p->firstName,firstN);

//    copy region name
    p->region = malloc( (strlen(region) + 1) * sizeof(char));
    if (p->region == NULL){
        return NULL;
    }
    strcpy(p->region, region);

    return p;
}


//
// -=[Function Description]=-
// Function to create an Empty Person.
//
struct Person* createEmptyPerson(){

    struct Person* p = malloc(sizeof(struct Person));

    if (p == NULL){
        return NULL;
    }

    p->ID = 0;
    p->IDfather = 0;
    p->IDmother = 0;
    p->day = 0;
    p->month = 0;
    p->year = 0;

//    insert lastName empty Person
    p->lastName = malloc(2 * sizeof(char));
    if (p->lastName == NULL){
        return NULL;
    }
    strcpy(p->lastName, "-");

//    insert first empty Person
    p->firstName = malloc(2 * sizeof(char));
    if (p->firstName == NULL){
        return NULL;
    }
    strcpy(p->firstName, "-");

//    insert region empty Person
    p->region = malloc(2 * sizeof(char));
    if (p->region == NULL){
        return NULL;
    }
    strcpy(p->region, "-");

    return p;
}

//** Access Functions **

//
// -=[Function Description]=-
// Function to print a PErson infos.
//
void printPerson(struct Person* p){

    if (p == NULL){
        printf("the person is empty\n");
        return;
    }

    printf("ID : %d\n", getID(p));
    printf("father's ID : %d\n", getFatherID(p));
    printf("mother's ID : %d\n", getMotherID(p));
    printf("last name : %s\n", getLastName(p));
    printf("first name : %s\n", getFirstName(p));
    printf("day : %d\n", getDay(p));
    printf("month : %d\n", getMonth(p));
    printf("year : %d\n", getYear(p));
    printf("region : %s\n", getRegion(p));
}


//
// -=[Function Description]=-
// Function to get the ID of a Person.
//
int getID(struct Person* p){
    return p->ID;
}


//
// -=[Function Description]=-
// Function to get the father ID of a Person.
//
int getFatherID(struct Person* p){
    return p->IDfather;
}


//
// -=[Function Description]=-
// Function to get the mother ID of a Person.
//
int getMotherID(struct Person* p){
    return p->IDmother;
}


//
// -=[Function Description]=-
// Function to get the last Name of a Person.
//
char* getLastName(struct Person *p){
    return p->lastName;
}


//
// -=[Function Description]=-
// Function to get the first Name of a Person.
//
char* getFirstName(struct Person *p){
    return p->firstName;
}


//
// -=[Function Description]=-
// Function the bith day of the Person.
//
int getDay(struct Person* p){
    return p->day;
}


//
// -=[Function Description]=-
// Function the bith month of the Person.
//
int getMonth(struct Person* p){
    return p->month;
}


//
// -=[Function Description]=-
// Function the bith year of the Person.
//
int getYear(struct Person* p){
    return p->year;
}


//
// -=[Function Description]=-
// Function to get the native Region of a Person.
//
char* getRegion(struct Person* p){
    return p->region;
}

//** Suppression Function **

//
// -=[Function Description]=-
// Function to delete a Person.
//
void deletePerson(struct Person* p){
    free(p->lastName);
    free(p->firstName);
    free(p->region);
    free(p);
}


