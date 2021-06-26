#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>

#include "file_reader.h"
#include "structDataBase.h"
#include "structPerson.h"


#define MAX_CHAR 1000


struct dataBase* read(char *nameFile){


    char row[MAX_CHAR];
    char *token;
    char* separators = ",/";

    int count = 0;


    FILE *file = fopen(nameFile,"r");

    if(file == NULL){
        printf("[INFO] -- Error in opening file\n");
        printf("--------------------------------------------------\n");
        return NULL;

    }

    printf("[INFO] -- Reading CSV File..\n");

//    -----------get the first line-----------
    int numberPerson;
    fscanf(file,"%d\n", &numberPerson);

    //   -----------creation of the data base-----------
    struct dataBase* data = createDataBase(numberPerson);

//    -----------skipping the NULL person (second line) && adding her in the begin of struct-----------
    fgets(row, MAX_CHAR, file);
    getPersonArray(data)[0] = createEmptyPerson();
    data->validIndex += 1;



    while (!feof(file)) {

//        -----------get row----------

        fgets(row, MAX_CHAR, file);
        token = strtok(row, separators); // first token

//        ----------get ID----------

        int ID = atoi(token);
        if (count == 1){
            break;
        }
        if (ID == numberPerson){
            count++;
        }
        token = strtok(NULL, separators);

//        ----------get father's ID----------

        int IDf = atoi(token);
        token = strtok(NULL, separators);

//        ----------get mother's ID----------

        int IDm = atoi(token);
        token = strtok(NULL, separators);

//        g----------et last name----------

        int lenLname = strlen(token);
        char* lastName = malloc( (lenLname + 1) * sizeof(char));
        lastName[lenLname] = '\0';
        strcpy(lastName, token);
        token = strtok(NULL, separators);

//        ----------get first name----------

        int lenFname = strlen(token);
        char* firstName = malloc( (lenFname + 1) * sizeof(char));
        firstName[lenFname] = '\0';
        strcpy(firstName, token);
        token = strtok(NULL, separators);

//        ----------get day----------

        int day = atoi(token);
        token = strtok(NULL, separators);

//        ----------get month----------

        int month = atoi(token);
        token = strtok(NULL, separators);

//        ----------get year----------

        int year = atoi(token);
        token = strtok(NULL, separators);

//        ----------get region----------
//
        int lenRegion = strlen(token);
        char* region = malloc( (lenRegion + 1) * sizeof(char));
        region[lenRegion] = '\0';
        strcpy(region, token);


//        value get printed
//        printf("number person in the file : %d\n\n", numberPerson);
//        printf("ID : %d\n", ID);
//        printf("father's ID : %d\n", IDf);
//        printf("mother's ID : %d\n", IDm);
//        printf("last name : %s\n", lastName);
//        printf("first name : %s\n", firstName);
//        printf("day : %d\n", day);
//        printf("month : %d\n", month);
//        printf("year : %d\n", year);
//        printf("region : %s\n", region);


        // **create a person and fill it with extracted values**
        struct Person* p = createPerson(ID, IDf, IDm, lastName, firstName, day, month, year, region);

//        printPerson(p);

        free(lastName);
        free(firstName);
        free(region);

        // **add person to the database & update database infos with person infos**
        insertPerson(p, data);
        //printPerson(p);


    }

    fclose(file);
    printf("[INFO] -- File %s Successfully Readed !\n", nameFile);

    return data; // return the filled dataBase
}