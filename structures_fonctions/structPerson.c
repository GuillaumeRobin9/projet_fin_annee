#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>

#include "structures_headers/structPerson.h"

//** Creation Function **
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
    strcpy(p->lastName, lastN);

//    copy first name
    p->firstName = malloc( (strlen(firstN) + 1) * sizeof(char));
    strcpy(p->firstName, lastN);

//    copy region name
    p->region = malloc( (strlen(region) + 1) * sizeof(char));
    strcpy(p->region, region);

    return p;
}

struct Person* createEmptyPerson(){

    struct Person* p = malloc(sizeof(struct Person));

    if (p == NULL){
        return NULL;
    }

    p->ID = 0;
    p->IDfather = 0;
    p->IDmother = 0;
    p->lastName = '0';
    p->firstName = '0';
    p->day = 0;
    p->month = 0;
    p->year = 0;
    p->region = '0';

    return p;
}

//** Access Functions **

int getID(struct Person* p){
    return p->ID;
}

int getFatherID(struct Person* p){
    return p->IDfather;
}

int getMotherID(struct Person* p){
    return p->IDmother;
}

char* getLastName(struct Person *p){
    return p->lastName;
}

char* getFirstName(struct Person *p){
    return p->firstName;
}

int getDay(struct Person* p){
    return p->day;
}

int getMonth(struct Person* p){
    return p->month;
}

int getYear(struct Person* p){
    return p->year;
}

char* getRegion(struct Person* p){
    return p->region;
}

//** Suppression Function **
void deletePerson(struct Person* p){
    free(p->lastName);
    free(p->firstName);
    free(p->region);
    free(p);
}


