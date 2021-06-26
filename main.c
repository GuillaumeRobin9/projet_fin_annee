#include <stdlib.h>
#include <string.h>
#include <stdio.h>

#include "file_reader.h"
#include "structDataBase.h"

int main() {

    char choice[3];
    char choice2[3];
    char csvName[50];
    struct dataBase* data = NULL;
    bool exitCondition = false;

    while (!exitCondition){
        system("clear");
        printf("Welcome to our Family Tree Project !\n\n");
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
                    data = read(csvName);
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
                    case 2:
                        printf("[INFO] -- 2 ");
                    case 3:
                        printf("[INFO] -- 3 ");
                    case 4:
                        printf("[INFO] -- 4 ");
                    case 5:
                        printf("[INFO] -- 5 ");
                    case 6:
                        printf("[INFO] -- 6 ");
                }
            default:
                system("clear");
                break;
            case 2:
                printf("[INFO] -- Exiting Program\n");
                exitCondition = true;

        }
    }


    return 0;
    printf("[INFO] -- Starting Output Process\n");

    //struct dataBase* data = read("bd_grande.csv");
    printf("[INFO] -- Databse Successfully Readed !\n");

    printDataBase(data);

/*  ________________
    |              |
    |     MENU     |
    |              |
    ----------------
*/

//    END
//    deleteDataBase(data); // marche mal
}








































