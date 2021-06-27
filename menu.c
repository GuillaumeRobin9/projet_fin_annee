//
// Created by micka on 27/06/2021.
//
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <unistd.h>

#include "structDataBase.h"
#include "dataBase_reader.h"
#include "menu.h"

#define MAX_LEN 40

void red () {
    printf("\\033[1;31m");
}

void green () {
    printf("\033[0;32m");
}

void reset () {
    printf("\033[0m");
}

void queryMenu(struct dataBase* data){

    int queryChoice;
    bool exitConditionQuery = false;
    char regionName[MAX_LEN];
    int month;
    int day;

    while (!exitConditionQuery) {

        createQueryResFile(); // creation of the  result file query

        printf("[INFO] -- 5 ");
        printf("\n\nQuery the family tree!\n\n");
        printf("What do you want to do?\n");
        printf("--------------------------------------------------\n");
        printf("1. Get first born in the tree\n");
        printf("2. Get last born in the tree\n");
        printf("3. Get number of people born in a region\n");
        printf("4. Get the region with the highest number of births\n");
        printf("5. Get the number of people born in a given day and month\n");
        printf("6. optionnal querys\n");
        printf("7. export query results to HTML file\n");
        printf("8. back to previous menu\n");
        printf("--------------------------------------------------\n");
        printf("[CHOICE] -- Please enter your selection : ");
        scanf("%d", &queryChoice);
        fgetc(stdin);
        printf("[MENU] -- Selected choice : %d\n", queryChoice);
        printf("--------------------------------------------------\n");

        switch (queryChoice) {
            case 1:
                green();
                printf("[INFO] -- 1 -- Here is the first person born\n\n");
                reset();
                int IDoldest = getOldestID(data);
                printPerson(getPersonArray(data)[IDoldest]);
                fillFileQuery1(IDoldest, data); // adding the query to the file
                printf("--------------------------------------------------\n");
                break;
            case 2:
                green();
                printf("[INFO] -- 2 -- Here is the last person born\n\n");
                reset();
                int IDyoungest = getyoungestID(data);
                printPerson(getPersonArray(data)[IDyoungest]);
                fillFileQuery2(IDyoungest, data); // adding the query to the file
                printf("--------------------------------------------------\n");
                break;
            case 3:
                printf("[CHOICE] -- 3 -- Please enter the region name : \n");
                fgets(regionName, MAX_LEN, stdin);
                regionName[strlen(regionName) - 1] = '\0';

                bool valid;
                int numberPeople = findBirthsOfRegion(getTrie(data), regionName, &valid);
                if (valid == false) {
                    red();
                    printf("[ERROR] -- the region entered does not exist\n");
                    reset();
                    printf("--------------------------------------------------\n");
                    break;
                } else {
                    green();
                    printf("[INFO] --  %d persons are born in the region named %s\n", numberPeople,regionName);
                    reset();
                    fillFileQuery3(regionName, numberPeople); // adding the query to the file
                }
                printf("--------------------------------------------------\n");
                break;
            case 4:
                green();
                printf("[INFO] -- 4 --the region with the highest numner of biths is named %s with %d births\n", getFertileRegion(data), getMaxBirths(data));
                reset();
                fillFileQuery4(getFertileRegion(data)); // adding the query to the file
                printf("--------------------------------------------------\n");
                break;
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
                green();
                printf("\n[INFO] -- %d peoples are born on %d/%d\n", data->birthdays[month][day], day, month);
                reset();
                fillFileQuery5(day, month, data->birthdays[month][day]); // adding the query to the HTML file
                printf("--------------------------------------------------\n");
                break;
            case 6:
                printf("[MENU] -- 6 -- The options are not available yet :(\n");
                printf("--------------------------------------------------\n");
                break;
            case 7: // EXPORT QUERY RESULTS IN TO A HTML FILE
                printf("[MENU] -- 7 -- exporting query results to HTML file ");
                printf("--------------------------------------------------\n");
                break;
            case 8:
                printf("[MENU] -- 8 -- Exiting Query Menu\n");
                exitConditionQuery = true;
                break;
            default:
                red();
                printf("[ERROR] -- Selecet a valid choice please!!\n");
                reset();
                printf("--------------------------------------------------\n");
                sleep(3);
                break;
        }
    }
}

void exportHTMLFamilyTree(struct dataBase* data){
    struct Person* child;
    struct Person* father;
    struct Person* mother;
    struct Person* PaternalGFather;
    struct Person* PaternalGMother;
    struct Person* MaternalGFather;
    struct Person* MaternalGMother;

    for (int i = 1; i < getNumberPerson(data); i++){

        child = getPersonArray(data)[i];

        //    getting the IDs of the child's Ancestors
        father = getPersonArray(data)[getFatherID(child)];
        mother = getPersonArray(data)[getMotherID(child)];

        //    father's parents
        PaternalGFather = getPersonArray(data)[getFatherID(father)];
        PaternalGMother = getPersonArray(data)[getMotherID(father)];

        //    mother's parents
        MaternalGFather = getPersonArray(data)[getFatherID(mother)];
        MaternalGMother = getPersonArray(data)[getMotherID(mother)];
        createPersonHTMLFile(child, father, mother, PaternalGFather, PaternalGMother, MaternalGFather, MaternalGMother);
    }
}

void HTMLFamilyTreeOption(struct dataBase* data, int* exportFamilyCount){

    printf("[INFO] -- 2 -- Exporting HTML family tree files...\n"); // AJOUTER CHRONO
    if (*exportFamilyCount == 0){
        exportHTMLFamilyTree(data);
        green();
        printf("[INFO] -- Successfully Generated %d HTML Files !\n", getNumberPerson(data));
        reset();
        *exportFamilyCount = *exportFamilyCount + 1;
    }
    else {
        red();
        printf("[ERROR] -- The HTML files are already exported !\n");
        reset();
    }

}

void HTMLInfoTreeOption(struct dataBase* data, int* exportInfoCount){

    printf("[INFO] -- 3 -- Exporting HTML info files...\n");
    if (*exportInfoCount == 0){
        // ajouter la fonction mettant les infos de l'option 1 dans un fichier HTML
        green();
        printf("[INFO] -- Successfully Generated HTML Files !\n");
        reset();
        *exportInfoCount = *exportInfoCount + 1;
    }
    else {
        red();
        printf("[ERROR] -- The HTML files are already exported !\n");
        reset();
    }

}
