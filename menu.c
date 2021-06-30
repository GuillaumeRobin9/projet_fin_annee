//
// Project: projet_fin_annee
// Authors: Antoine SOYDEMIR, Guillaume ROBIN, Mickaël NERODA
// Creation date: 27/06/2021
// Modification date: 29/06/2021
// Role: Functions to display the query menu, and to execute options that create HTML files.
//


// Includes
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <unistd.h>
#include <time.h>

#include "structDataBase.h"
#include "htmlGenerator.h"
#include "menu.h"


//-------------------------------------------------------------------------
//--- Functions Implementation --------------------------------------------
//-------------------------------------------------------------------------

// ** color font functions **

//
// -=[Function Description]=-
// Function to write in red in the console.
//
void red () {
    printf("\033[1;31m");
}

//
// -=[Function Description]=-
// Function to write in greeb in the console.
//
void green () {
    printf("\033[0;32m");
}

//
// -=[Function Description]=-
// Function to reset the default color of the console.
//
void reset () {
    printf("\033[0m");
}


// ** query menu **

//
// -=[Function Description]=-
// Function that execute the query menu.
//
void queryMenu(struct dataBase* data){
    struct timespec start, end; // clock

    int queryChoice; // variables initialisation
    bool exitConditionQuery = false;
    char regionName[MAX_LEN];
    int month;
    int day;

    int numberQueries = 0;

    while (!exitConditionQuery) {

//               ** [DISPLAY QUERY MENU] **
        //displayBirthTable(data);
        printf("[INFO] -- 5 ");
        printf("\n\nQuery the family tree!\n\n");
        printf("What do you want to do?\n");
        printf("--------------------------------------------------\n");
        printf("1. Get first born in the tree\n");
        printf("2. Get last born in the tree\n");
        printf("3. Get number of people born in a region\n");
        printf("4. Get the region with the highest number of births\n");
        printf("5. Get the number of people born in a given day and month\n");
        printf("6. optional query\n");
        printf("7. export query results to HTML file\n");
        printf("8. back to previous menu\n");
        printf("--------------------------------------------------\n");
        printf("[INFO] -- You have made %d valid Queries\n", numberQueries);
        printf("--------------------------------------------------\n");
        printf("[CHOICE] -- Please enter your selection : ");
        scanf("%d", &queryChoice);
        fgetc(stdin);
        printf("[MENU] -- Selected choice : %d\n", queryChoice);
        printf("--------------------------------------------------\n");

        switch (queryChoice) {
            // -------- [CHOICE 1. Get first born in the tree]
            case 1:
                green();
                printf("[INFO] -- 1 -- Here is the first person born\n\n");
                reset();

                clock_gettime(CLOCK_REALTIME, &start);  // -- START chrono --

                int IDoldest = getOldestID(data);
                printPerson(getPersonArray(data)[IDoldest]);

                clock_gettime(CLOCK_REALTIME, &end); //  --- STOP chrono --
                double time_spent = (end.tv_sec - start.tv_sec) + (end.tv_nsec - start.tv_nsec) / BILLION;

                green();
                printf("[INFO] -- Execution Time : %f s\n", time_spent);
                reset();

                numberQueries++; //update number queries
                printf("--------------------------------------------------\n");
                break;
            // -------- [CHOICE 2. Get last born in the tree]
            case 2:
                green();
                printf("[INFO] -- 2 -- Here is the last person born\n\n");
                reset();

                clock_gettime(CLOCK_REALTIME, &start);  // -- START chrono --

                int IDyoungest = getyoungestID(data);
                printPerson(getPersonArray(data)[IDyoungest]);

                clock_gettime(CLOCK_REALTIME, &end); //  --- STOP chrono --
                double time_spent2 = (end.tv_sec - start.tv_sec) + (end.tv_nsec - start.tv_nsec) / BILLION;

                green();
                printf("[INFO] -- Execution Time : %f s\n", time_spent2);
                reset();

                numberQueries++; //update number queries
                printf("--------------------------------------------------\n");
                break;
            // -------- [CHOICE 3. Get number of people born in a region]
            case 3:
                printf("[CHOICE] -- 3 -- Please enter the region name : ");
                fgets(regionName, MAX_LEN, stdin);
                regionName[strlen(regionName) - 1] = '\0';
                bool valid;

                clock_gettime(CLOCK_REALTIME, &start);  // -- START chrono --

                int numberPeople = findBirthsOfRegion(getTrie(data), regionName, &valid);

                clock_gettime(CLOCK_REALTIME, &end); //  --- STOP chrono --
                double time_spent3 = (end.tv_sec - start.tv_sec) + (end.tv_nsec - start.tv_nsec) / BILLION;

                if (valid == false) {
                    red();
                    printf("\n[ERROR] -- the region entered does not exist\n");
                    reset();
                    break;
                } else {
                    green();
                    printf("[INFO] --  %d persons are born in the region named %s\n", numberPeople,regionName);
                    reset();
                    numberQueries++; //update number queries
                }
                green();
                printf("[INFO] -- Execution Time : %f s\n", time_spent3);
                reset();
                printf("--------------------------------------------------\n");
                break;
            // -------- [CHOICE 4. Get the region with the highest number of births]
            case 4:
                printf("[INFO] -- 4\n");
                clock_gettime(CLOCK_REALTIME, &start);  // -- START chrono --

                green();
                printf("[INFO] the region with the highest number of births is named %s with %d births\n", getFertileRegion(data), getMaxBirths(data));

                clock_gettime(CLOCK_REALTIME, &end); //  --- STOP chrono --
                double time_spent4 = (end.tv_sec - start.tv_sec) + (end.tv_nsec - start.tv_nsec) / BILLION;
                printf("[INFO] -- Execution Time : %f s\n", time_spent4);
                reset();
                numberQueries++; //update number queries
                printf("--------------------------------------------------\n");
                break;
            // -------- [CHOICE 5. Get the number of people born in a given day and month]
            case 5:
                printf("[INFO] -- 5 \n");
                printf("[CHOICE] -- Please enter the day : ");
                scanf("%d", &day);
                fgetc(stdin);
                if (day <= 0 || day >= 32) {
                    red();
                    printf("\n[ERROR] -- invalid day\n");
                    reset();
                    printf("--------------------------------------------------\n");
                    break;
                }
                printf("[CHOICE] -- Please enter the month : ");
                scanf("%d", &month);
                fgetc(stdin);
                if (month <= 0 || month >= 13) {
                    red();
                    printf("\n[ERROR] -- invalid month\n");
                    reset();
                    printf("--------------------------------------------------\n");
                    break;
                }
                clock_gettime(CLOCK_REALTIME, &start);  // -- START chrono --

                green();
                printf("\n[INFO] -- on %d/%d, %d peoples are born\n", day, month, getValBirthTable(data, day, month));
                reset();

                clock_gettime(CLOCK_REALTIME, &end); //  --- STOP chrono --
                double time_spent5 = (end.tv_sec - start.tv_sec) + (end.tv_nsec - start.tv_nsec) / BILLION;

                green();
                printf("[INFO] -- Execution Time : %f s\n", time_spent5);
                reset();

                numberQueries++; //update number queries
                printf("--------------------------------------------------\n");
                break;
            // -------- [CHOICE 6. optionnal querys]
            case 6:
                printf("[MENU] -- 6 -- The option is not available yet :(\n");
                printf("--------------------------------------------------\n");
                break;
            // -------- [CHOICE 7. export query results to HTML file]
            case 7:
                printf("[MENU] -- 7 -- Execution of all the Queries\n");
                createQueryHTMLFile(data, &numberQueries);
                printf("--------------------------------------------------\n");
                break;
            // -------- [CHOICE 8. back to previous menu]
            case 8:
                printf("[MENU] -- 8 -- Exiting Query Menu\n");
                exitConditionQuery = true;
                break;
            // -------- [CHOICE INVALID]
            default:
                red();
                printf("[ERROR] -- Select a valid choice please!!\n");
                reset();
                printf("--------------------------------------------------\n");
                sleep(3);
                break;
        }
    }
}



// ** option choice Functions **

//
// -=[Function Description]=-
// Function to execute the option 2 Export HTML info files of the second MENU.
//
void HTMLFamilyTreeOption(struct dataBase* data, int* exportFamilyCount){
    struct timespec start, end; // clock

    printf("[INFO] -- 2 -- Exporting HTML family tree files...\n");
    if (*exportFamilyCount == 0){
        clock_gettime(CLOCK_REALTIME, &start);  // -- START chrono --

        exportHTMLFamilyTree(data);

        clock_gettime(CLOCK_REALTIME, &end); //  --- STOP chrono --
        double time_spent = (end.tv_sec - start.tv_sec) + (end.tv_nsec - start.tv_nsec) / BILLION;


        green();
        printf("[INFO] -- Successfully Generated %d HTML Files in %f s!\n", getNumberPerson(data), time_spent);
        reset();
        *exportFamilyCount = *exportFamilyCount + 1;
    }
    else {
        red();
        printf("[ERROR] -- The HTML files are already exported !\n");
        reset();
    }

}

//
// -=[Function Description]=-
// Function to execute the option 2 Export HTML family tree of the second MENU.
//
void HTMLIndexCreatorOption(struct dataBase* data, int* exportInfoCount,char* fileName){
    struct timespec start, end; // clock

    printf("[INFO] -- 3 -- Exporting HTML info files...\n");
    if (*exportInfoCount == 0){
        clock_gettime(CLOCK_REALTIME, &start);  // -- START chrono --

        createIndexHTMLFile(data, fileName, getNumberPerson(data));

        clock_gettime(CLOCK_REALTIME, &end); //  --- STOP chrono --
        double time_spent = (end.tv_sec - start.tv_sec) + (end.tv_nsec - start.tv_nsec) / BILLION;
        green();
        printf("[INFO] -- Successfully Generated HTML Info File in %f s!\n", time_spent);
        reset();
        *exportInfoCount = *exportInfoCount + 1;
    }
    else {
        red();
        printf("[ERROR] -- The HTML files are already exported !\n");
        reset();
    }

}

// ** other execution functions **

//
// -=[Function Description]=-
// Function to get the ID of the ancestors of a person, and create the HTML file of all the persons of the data base.
//
void exportHTMLFamilyTree(struct dataBase* data){
    struct Person* child; // declaration of the ancestors IDs
    struct Person* father;
    struct Person* mother;
    struct Person* PaternalGFather;
    struct Person* PaternalGMother;
    struct Person* MaternalGFather;
    struct Person* MaternalGMother;

    for (int i = 1; i < getNumberPerson(data); i++){ // going threw the data base person array

        // getting the ID of the child of the tree
        child = getPersonArray(data)[i];

        //    getting the IDs of the child's Ancestors
        father = getPersonArray(data)[getFatherID(child)];
        mother = getPersonArray(data)[getMotherID(child)];

        //    getting the IDs of the father's parents
        PaternalGFather = getPersonArray(data)[getFatherID(father)];
        PaternalGMother = getPersonArray(data)[getMotherID(father)];

        //    getting the IDs of the mother's parents
        MaternalGFather = getPersonArray(data)[getFatherID(mother)];
        MaternalGMother = getPersonArray(data)[getMotherID(mother)];

        //    creation of the person's HTML page tree
        createPersonHTMLFile(child, father, mother, PaternalGFather, PaternalGMother, MaternalGFather, MaternalGMother);
    }
}

