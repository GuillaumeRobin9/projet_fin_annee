//
// Project: projet_fin_annee
// Authors: Guillaume ROBIN, Mickaël NERODA
// Creation date: 25/06/2021
// Modification date: 29/06/2021
// Role: create and fill the database from the CSV file => create an empty data base, read the CSV file, create persons from the infos from the CSV,
// and adding the persons created to the data base
//

// Includes
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <time.h>

#include "csvReader.h"
#include "structDataBase.h"
#include "menu.h"

//-------------------------------------------------------------------------
//--- Functions Implementation --------------------------------------------
//-------------------------------------------------------------------------

//
// -=[Function Description]=-
// Function create an empty data base, read the CSV file, create persons from the infos from the CSV,
// and adding the persons created to the data base.
//
struct dataBase* readFile(char *nameFile){
    struct timespec start, end; // clock


    char row[MAX_CHAR];
    char *token;
    char* separators = ",/";

    int count = 0;


    FILE *file = fopen(nameFile,"r");

    if(file == NULL){
        red();
        printf("[ERROR] -- Error in opening the file\n");
        reset();
        printf("--------------------------------------------------\n");
        return NULL;

    }

        // start chrono
    clock_gettime(CLOCK_REALTIME, &start);


    printf("[INFO] -- Reading CSV File..\n");

//    -----------get the first line-----------
    int numberPerson;
    fscanf(file,"%d\n", &numberPerson);

//   -----------creation of the data base-----------
    struct dataBase* data = createDataBase(numberPerson);

//    -----------skipping the NULL person (second line) -----------
//    && adding the null person in the beginning of the person array of the DB
    fgets(row, MAX_CHAR, file);
    getPersonArray(data)[0] = createEmptyPerson();
    data->validIndex += 1;



    while (!feof(file)) { // ** reading the CSV file line per line **

//        -----------get row----------

        fgets(row, MAX_CHAR, file);
        token = strtok(row, separators); // first token

//        ----------get ID----------

        int ID = atoi(token);
        if (count == 1){ // Stop the reading of the file if the file has been already readed one time.
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

//        ----------get last name----------

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


        // **create a person and fill it with extracted values**
        struct Person* p = createPerson(ID, IDf, IDm, lastName, firstName, day, month, year, region);

        free(lastName);
        free(firstName);
        free(region);

        // **add person to the database & update database infos with person infos**
        insertPerson(p, data);
    }

    fclose(file);

//  stop chrono
    clock_gettime(CLOCK_REALTIME, &end);
    double time_spent = (end.tv_sec - start.tv_sec) + (end.tv_nsec - start.tv_nsec) / BILLION;

    green();
    printf("[INFO] -- File \"%s\" Successfully Read in %f s !\n", nameFile, time_spent);
    reset();


    return data; // return the filled dataBase
}