#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "file_reader.h"
//#include <bd_petite.csv>

#define MAX_CHAR 1000


void read(char *nameFile){

    char row[MAX_CHAR];
    char *token;
    char* separators = ",/";
    int l;
    int index = 0;

    //fill database ->createEmpty
    FILE *file = fopen(nameFile,"r");

    if(file == NULL){
        printf("Error in opening file");
        return NULL;
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

        fgets(row, MAX_CHAR, file);
        //printf("Row: %s", row);

        token = strtok(row, separators);

        printf("Token: %s   ", token);
        printf("%d",strlen(token));
        token = strtok(NULL, separators);


    }

    return NULL;
}

