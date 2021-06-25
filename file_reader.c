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

    //char data[40];
    char ID[25];
    char IDf[25];
    char IDm[25];
    char lastName[25];
    char firstName[25];
    char day[25];
    char month[25];
    char year[25];
    char region[25];


    while (feof(file) != true) { //sauf 1er l

//        show row
        fgets(row, MAX_CHAR, file);
        printf("Row: %s", row);

//        get ID
        token = strtok(row, separators);
        printf("ID : %s\n", token);
        token = strtok(NULL, separators);

//        get father's ID
        token = strtok(row, separators);
        printf("father's ID : %s\n", token);
        token = strtok(NULL, separators);

//        get mother's ID
        token = strtok(row, separators);
        printf("mother's ID : %s\n", token);
        token = strtok(NULL, separators);

//        get last name
        token = strtok(row, separators);
        printf("last name : %s\n", token);
        token = strtok(NULL, separators);

//        get first name
        token = strtok(row, separators);
        printf("first name : %s\n", token);
        token = strtok(NULL, separators);

//        get day
        token = strtok(row, separators);
        printf("day : %s\n", token);
        token = strtok(NULL, separators);

//        get month
        token = strtok(row, separators);
        printf("month : %s\n", token);
        token = strtok(NULL, separators);

//        get year
        token = strtok(row, separators);
        printf("year : %s\n", token);
        token = strtok(NULL, separators);

//        get region
        token = strtok(row, separators);
        printf("region : %s\n", token);
        token = strtok(NULL, separators);






//        printf("%d",strlen(token));
//        token = strtok(NULL, separators);


    }

    return;
}

