#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>

#include "structPerson.h"

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
    strcpy(p->lastName, "0");

//    insert first empty Person
    p->firstName = malloc(2 * sizeof(char));
    if (p->firstName == NULL){
        return NULL;
    }
    strcpy(p->firstName, "0");

//    insert region empty Person
    p->region = malloc(2 * sizeof(char));
    if (p->region == NULL){
        return NULL;
    }
    strcpy(p->region, "0");



    return p;
}

//** Access Functions **

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


