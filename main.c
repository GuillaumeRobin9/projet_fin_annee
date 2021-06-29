//
// Project: projet_fin_annee
// Authors: Antoine SOYDEMIR, Guillaume ROBIN, Mickaël NERODA
// Creation date: 24/06/2021
// Modification date: 29/06/2021
// Role: display the menu, access to all the function of the project
//


// Includes
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <unistd.h>
#include <time.h>


#include "csvReader.h"
#include "structDataBase.h"
#include "menu.h"

// Global Variables
#define BILLION  1000000000.0
#define MAX_LEN 40


int main() {
    struct timespec start, end; // clock

    int choice;
    int choice2;
    char csvName[MAX_LEN];
    struct dataBase* data = NULL;

    bool exitCondition = false;


    while (!exitCondition){
        // exit condition of the menu HTML export
        bool exitCondition2 = false;
        // counters of HTML exportation
        int exportFamilyCount = 0;
        int exportInfoCount = 0;

        system("clear");
        printf("\n"
               "   ______                      __            _         ______                  ____               _           __ \n"
               "  / ____/__  ____  ___  ____ _/ /___  ____ _(_)____   /_  __/_______  ___     / __ \\_________    (_)__  _____/ /_\n"
               " / / __/ _ \\/ __ \\/ _ \\/ __ `/ / __ \\/ __ `/ / ___/    / / / ___/ _ \\/ _ \\   / /_/ / ___/ __ \\  / / _ \\/ ___/ __/\n"
               "/ /_/ /  __/ / / /  __/ /_/ / / /_/ / /_/ / / /__     / / / /  /  __/  __/  / ____/ /  / /_/ / / /  __/ /__/ /_  \n"
               "\\____/\\___/_/ /_/\\___/\\__,_/_/\\____/\\__, /_/\\___/    /_/ /_/   \\___/\\___/  /_/   /_/   \\____/_/ /\\___/\\___/\\__/  \n"
               "                                   /____/                                                  /___/                 \n");
        printf("What do you want to do ?\n");
// ===========================================================|| PRINCIPAL MENU ||============================================================
        //               ** [DISPLAY PRINCIPAL MENU] **
        printf("--------------------------------------------------\n");
        printf("[MENU] -- 1. Read CSV file\n");
        printf("[MENU] -- 2. Exit\n");
        printf("--------------------------------------------------\n");

        printf("[CHOICE] -- Please enter your selection : ");
        scanf("%d", &choice);
        fgetc(stdin);
        printf("[MENU] -- Selected choice : %d\n", choice);
        printf("--------------------------------------------------\n");
        switch (choice) { // ======================================|| SECOND MENU ||==========================================
            // -------- [CHOICE 1. Read CSV file]
            case 1:
                while (data == NULL){
                    printf("[MENU] -- Enter the name of your CSV File : ");
                    fgets(csvName, MAX_LEN, stdin);
                    csvName[strlen(csvName) - 1] = '\0';
                    printf("[CHOICE] -- Selected file : \"%s\"\n", csvName);
                    data = readFile(csvName); // process recorded
                }

                while (!exitCondition2){
                    //               ** [DISPLAY SECOND MENU] **
                    printf("\nWhat do you want to do ?\n");
                    printf("--------------------------------------------------\n");
                    printf("1. Show family tree info\n");
                    printf("2. Export HTML family tree\n");
                    printf("3. Export HTML info files\n");
                    printf("4. Export all files\n");
                    printf("5. Query family tree\n");
                    printf("6. Go back to principal menu\n");
                    printf("--------------------------------------------------\n");

                    printf("[CHOICE] -- Please enter your selection : ");
                    scanf("%d", &choice2);
                    fgetc(stdin);
                    printf("[MENU] -- Selected choice : %d\n", choice2);
                    printf("--------------------------------------------------\n");
                    switch (choice2) {
                        // -------- [CHOICE 1. Show family tree info]
                        case 1:
                            printf("[INFO] -- 1\n");

                            clock_gettime(CLOCK_REALTIME, &start);

                            showGeneralInfoDataBase(data);

                            clock_gettime(CLOCK_REALTIME, &end);

                            double time_spent2 = (end.tv_sec - start.tv_sec) + (end.tv_nsec - start.tv_nsec) / BILLION;

                            green();
                            printf("[INFO] -- Execution Time : %f s\n", time_spent2);
                            reset();
                            break;
                        // -------- [CHOICE 2. Export HTML family tree]
                        case 2:
                            HTMLFamilyTreeOption(data, &exportFamilyCount);
                            break;
                        //  -------- [CHOICE 3. Export HTML info files]
                        case 3:
                            HTMLIndexCreatorOption(data, &exportInfoCount,csvName);
                            break;
                        //  -------- [CHOICE 4. Export all files]
                        case 4:
                            HTMLFamilyTreeOption(data, &exportFamilyCount);
                            HTMLIndexCreatorOption(data, &exportInfoCount,csvName);
                            break;
                        //  -------- [CHOICE 5. Query family tree]
                        case 5:
                            // ===========================================|| QUERY MENU ||===========================================
                            queryMenu(data); // function that execute the query menu
                            break;
                            // =========================================|| END QUERY MENU ||===========================================
                        //  -------- [CHOICE 6. Go back to principal menu]
                        case 6:
                            printf("[INFO] -- 6 ");
                            printf("[INFO] -- Going back to the principal Menu & deleting the data base...\n");
                            exitCondition2 = true;

                            clock_gettime(CLOCK_REALTIME, &start);

                            deleteDataBase(data);
                            data = NULL;

                            clock_gettime(CLOCK_REALTIME, &end);

                            double time_spent = (end.tv_sec - start.tv_sec) + (end.tv_nsec - start.tv_nsec) / BILLION;
                            green();
                            printf("[INFO] -- data base deleted in %f s\n", time_spent);
                            reset();
                            sleep(3);

                            break;
                        // [CHOICE] INVALID
                        default:
                            red();
                            printf("[ERROR] -- Selecet a valid choice please!!\n");
                            reset();
                            sleep(3);
                            break;
                    }
                }
                break;
                // =========================================================|| END SECOND MENU ||=========================================================
            // -------- [CHOICE 2. Exit The family tree program]
            case 2:
                printf("[INFO] -- Exiting Program\n");
                exitCondition = true;
                printf("\n"
                       "    ____                __   \n"
                       "   / __ )__  _____     / /   \n"
                       "  / __  / / / / _ \\   / /    \n"
                       " / /_/ / /_/ /  __/  /_/     \n"
                       "/_____/\\__, /\\___/  (_)      \n"
                       "      /____/                 ");
                printf("created by NERODA Mickaël, SOYDEMIR Antoine & ROBIN Guillaume @2021\n");
                sleep(4);
                system("clear");
                break;
            // -------- [CHOICE INVALID]
            default:
                red();
                printf("[ERROR] -- Selecet a valid choice please!!\n");
                reset();
                printf("Returning...\n");
                sleep(2);
                system("clear");
                break;
// ============================================================|| END PRINCIPAL MENU ||============================================================
        }
    }


//    if (data != NULL){ // in case if the user does not return to the principal menu
//        deleteDataBase(data);
//        data = NULL;
//    }

    return 0;
}








































