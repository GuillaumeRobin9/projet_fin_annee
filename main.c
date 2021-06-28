#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <unistd.h>
#include <time.h>

#include "file_reader.h"
#include "structDataBase.h"
#include "dataBase_reader.h"
#include "menu.h"


#define MAX_LEN 40



int main() {

    char choice[3];
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

        printf("--------------------------------------------------\n");
        printf("[MENU] -- 1. Read CSV file\n");
        printf("[MENU] -- 2. Exit\n");
        printf("--------------------------------------------------\n");

        printf("[CHOICE] -- Please enter your selection : ");
        scanf("%s", &choice);
        fgetc(stdin);
        printf("[MENU] -- Selected choice : %d\n", atoi(choice));
        printf("--------------------------------------------------\n");
        switch (atoi(choice)) { // -------------------------=|| MAIN MENU ||=-------------------------

            case 1:
                while (data == NULL){
                    printf("[MENU] -- Enter the name of your CSV File : ");
                    fgets(csvName, MAX_LEN, stdin);
                    csvName[strlen(csvName) - 1] = '\0';
                    printf("[CHOICE] -- Selected file : \"%s\"\n", csvName);
                    data = readFile(csvName); // process recorded
                }

                while (!exitCondition2){
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
                    switch (choice2) { // -------------------------=|| CREATION HTML FILES MENU ||=-------------------------
                        case 1:
                            printf("[INFO] -- 1\n");
                            double time_spent2 = 0.0; // start chrono
                            clock_t begin2 = clock();

                            showGeneralInfoDataBase(data);

                            clock_t end2 = clock(); //  stop chrono
                            time_spent2 += (double)(end2 - begin2) * 1000.0 / CLOCKS_PER_SEC;
                            green();
                            printf("[INFO] -- Execution Time : %f ms\n", time_spent2);
                            reset();
                            break;
                        case 2:
                            HTMLFamilyTreeOption(data, &exportFamilyCount);
                            break;
                        case 3:
                            HTMLInfoTreeOption(data, &exportInfoCount,csvName);
                            break;
                        case 4:
                            HTMLFamilyTreeOption(data, &exportFamilyCount);
                            HTMLInfoTreeOption(data, &exportInfoCount,csvName);
                            break;
                        case 5:
                            // -------------------------=|| QUERY MENU ||=-------------------------
                            queryMenu(data);
                            break;
                            // -------------------------=|| END QUERY MENU ||=-------------------------
                        case 6:
                            printf("[INFO] -- 6 ");
                            printf("[INFO] -- Going back to the principal Menu & deleting the data base...\n");
                            exitCondition2 = true;

                            double time_spent3 = 0.0; // start chrono
                            clock_t begin3 = clock();

                            deleteDataBase(data);
                            data = NULL;

                            clock_t end3 = clock(); //  stop chrono
                            time_spent3 += (double)(end3 - begin3) * 1000.0 / CLOCKS_PER_SEC;
                            green();
                            printf("[INFO] -- data base deleted in %f ms\n", time_spent3);
                            reset();
                            sleep(3);
                            break;
                        default:
                            red();
                            printf("[ERROR] -- Selecet a valid choice please!!\n");
                            reset();
                            sleep(3);
                            break;
                        // -------------------------=|| END CREATION HTML FILES MENU ||=-------------------------
                    }
                }
                break;

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
            default:
                red();
                printf("[ERROR] -- Selecet a valid choice please!!\n");
                reset();
                printf("Returning...\n");
                sleep(2);
                system("clear");
                break;
        // -------------------------=|| END MAIN MENU ||=-------------------------
        }
    }


//    if (data != NULL){ // in case if the user does not return to the principal menu
//        deleteDataBase(data);
//    }

    return 0;
}








































