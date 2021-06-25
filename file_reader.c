#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "file_reader.h"


#define MAX_CHAR 1000


void read(char *nameFile){

    char row[MAX_CHAR];
    char *token;
    char* separators = ",/";

    //fill database ->createEmpty.

    FILE *file = fopen(nameFile,"r");

    if(file == NULL){
        printf("Error in opening file");
        return;
    }


    while (feof(file) != true) { //sauf 1er l

//        show row
        fgets(row, MAX_CHAR, file);
        printf("Row: %s\n\n", row);

//        get ID
        token = strtok(row, separators);
        int ID = atoi(token);
        printf("ID : %d\n", token);
        token = strtok(NULL, separators);

//        get father's ID
        token = strtok(row, separators);
        int IDf = atoi(token);
        printf("father's ID : %d\n", token);
        token = strtok(NULL, separators);






//        get mother's ID
        token = strtok(row, separators);
        int IDm = atoi(token);
        printf("mother's ID : %d\n", token);
        token = strtok(NULL, separators);

//        get last name
        token = strtok(row, separators);
        int lenLname = strlen(token);
        char* lastName = malloc( (lenLname + 1) * sizeof(char));
        lastName[lenLname] = '\0';
        strcpy(lastName, token);
        printf("last name : %s\n", token);
        token = strtok(NULL, separators);

//        get first name
        token = strtok(row, separators);
        int lenFname = strlen(token);
        char* firstName = malloc( (lenFname + 1) * sizeof(char));
        firstName[lenFname] = '\0';
        strcpy(firstName, token);
        printf("first name : %s\n", token);
        token = strtok(NULL, separators);

//        get day
        token = strtok(row, separators);
        int day = atoi(token);
        printf("day : %s\n", token);
        token = strtok(NULL, separators);

//        get month
        token = strtok(row, separators);
        int month = atoi(token);
        printf("month : %d\n", token);
        token = strtok(NULL, separators);

//        get year
        token = strtok(row, separators);
        int year = atoi(token);
        printf("year : %d\n", token);
        token = strtok(NULL, separators);

//        get region
        token = strtok(row, separators);
        int lenRegion = strlen(token);
        char* region = malloc( (lenRegion + 1) * sizeof(char));
        region[lenRegion] = '\0';
        strcpy(region, token);
        printf("region : %s\n", token);
        token = strtok(NULL, separators);


//        printf("%d",strlen(token));
//        token = strtok(NULL, separators);


    }

    return;
}

