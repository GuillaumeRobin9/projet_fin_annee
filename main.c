#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <unistd.h>

#include "file_reader.h"
#include "structDataBase.h"
#include "dataBase_reader.h"


void red () {
    printf("\033[1;31m");
}
void reset () {
    printf("\033[0m");
}


int main() {

    char choice[3];
    char choice2[3];
    char queryChoice[3];
    char csvName[50];
    char regionName[50];
    struct dataBase* data = NULL;
    bool exitCondition = false;

    struct Person* child;
    struct Person* father;
    struct Person* mother;
    struct Person* PaternalGFather;
    struct Person* PaternalGMother;
    struct Person* MaternalGFather;
    struct Person* MaternalGMother;

    while (!exitCondition){
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
        scanf("%s", choice);
        printf("[MENU] -- Selected choice : %d\n", atoi(choice));
        printf("--------------------------------------------------\n");
        switch (atoi(choice)) {
            case 1:
                while (data == NULL){
                    printf("[MENU] -- Enter the name of your CSV File : ");
                    scanf("%s", csvName);
                    printf("[CHOICE] -- Selected file : %s\n", csvName);
                    data = readFile(csvName);
                }

                printf("--------------------------------------------------\n");
                printf("1. Show family tree info\n");
                printf("2. Export HTML family tree\n");
                printf("3. Export HTML info files\n");
                printf("4. Export all files\n");
                printf("5. Query family tree\n");
                printf("6. Go back to principal menu\n");
                printf("--------------------------------------------------\n");

                printf("[CHOICE] -- Please enter your selection : ");
                scanf("%s", choice2);
                printf("[MENU] -- Selected choice : %d\n", atoi(choice2));
                printf("--------------------------------------------------\n");
                switch (atoi(choice2)) {
                    case 1:
                        printf("[INFO] -- 1 ");
                    case 2: //  CREATION HTML FILES

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
                        red();
                        printf("[INFO] -- Successfully Generated %d HTML Files !\n", getNumberPerson(data));
                        reset();
                        break;
                    case 3:
                        printf("[INFO] -- 3 ");
                    case 4:
                        printf("[INFO] -- 4 ");
                    case 5:                            // QUERY MENU
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
                        printf("8. bach to previous menu\n");
                        printf("--------------------------------------------------\n");
                        scanf("%s", queryChoice);
                        printf("[MENU] -- Selected choice : %d\n", atoi(queryChoice));
                        printf("--------------------------------------------------\n");

                        switch(atoi(queryChoice)){
                            case 1:
                                printf("[INFO] -- 1 ");
                                printf("[INFO] -- Here is the first person born\n\n");
                                printPerson(getPersonArray(data)[getOldestID(data)]);
                                break;
                            case 2:
                                printf("[INFO] -- 2 ");
                                printf("[INFO] --   Here is the last person born\n\n");
                                printPerson(getPersonArray(data)[getyoungestID(data)]);
                                break;
                            case 3:
                                printf("[INFO] -- 3 ");
                                printf("[CHOICE] -- Please enter the region name : \n");
                                scanf("%s", regionName);
                                bool valid;
                                int numberPeople = findBirthsOfRegion(getTrie(data), regionName, &valid);
                                if (valid == false){
                                    printf("[ERROR] -- the region entered does not exist\n");
                                    break;
                                }
                                else {
                                    printf("[INFO] --  %d persons are born in the region named %s\n", numberPeople, regionName);
                                }
                                break;
                            case 4:
                                printf("[INFO] -- 4 ");
                                printf("[INFO] -- the region with the highest numner of biths is named %s with %d births\n", getFertileRegion(data), getMaxBirths(data));
                                break;
                            case 5:
                                printf("[INFO] -- 5 ");
                                int month;
                                int day;
                                printf("[CHOICE] -- Please enter the day : \n");
                                scanf("%d", &day);
                                if(day <= 0 || day >= 32){
                                    printf("[ERROR] -- invalid day\n");
                                    break;
                                }
                                scanf("%d", &month);
                                if(month <= 0 || day >= 13){
                                    printf("[ERROR] -- invalid day\n");
                                    break;
                                }
                                printf("[INFO] -- %d peoples are born on %d/%d\n", getBirthdayArray(data)[month][day], day, month);
                                break;
                            case 6:
                                printf("[INFO] -- 6 ");
                                break;
                            case 7:
                                printf("[INFO] -- 7 ");
                                break;
                            case 8:
                                printf("[INFO] -- 8 ");
                                break;
                            default:
                                system("clear");
                                break;
                        }

                    case 6:
                        printf("[INFO] -- 6 ");
                        break;
                }
            default:
                sleep(5);
                printf("Returning..\n");
                system("clear");
                break;
            case 2:
                printf("[INFO] -- Exiting Program\n");
                exitCondition = true;

        }
    }


    return 0;

// test NodeTrie
//    bool valid = false;
//    char* word = "Worcestershire";
//    int numberB = findBirthsOfRegion(getTrie(data), word, &valid);

//    printf("valid : %d\n", valid);
//    printf("number births in the region %s : %d\n", word, numberB);


/*  ________________
    |              |
    |     MENU     |
    |              |
    ----------------
*/

//    END
//    deleteDataBase(data);
}








































