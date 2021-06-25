#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>

#include "structures_headers/structPerson.h"

//** Creation Function **
struct Person* createEmptyPerson(int ID, int IDf, int IDm, char* lastN, char* firstN, int day, int month, int year, char* region){

    struct Person* p = malloc(sizeof(struct Person));

    if (p == NULL){
        return NULL;
    }

    p->ID = ID;
    p->IDfather = IDf;
    p->IDmother = IDm;
    p->lastName = lastN;
    p->firstName = firstN;
    p->day = day;
    p->month = month;
    p->year = year;
    p->region = region;

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


