#include <stdlib>
#include <string.h>
#include <stdio.h>

void read(int row, int col, char *nameFile,){

    FILE *file;
    database = fopen(nameFile,"bd_petite");
    if(database == NULL){
        printf("Error in opening file");
        return;
    }
    char data[40];
    int row = 0;
    int column = 0;
    while (fgets(data,40,file)) {
        column = 0;
        row++;
        if (row == 1){
            continue;
        }
        char* value = strtok(data, ", "); //split the chain between the coma

        while (value) {
            switch (column) {   //check a every colum separate by a coma
                case'0':
                    printf("ID :");
                    break;
                case'1':
                    printf("ID_father :");
                    break;
                case'2':
                    printf("ID_mother :");
                    break;
                case'3':
                    printf("name :");
                    break;
                case'4':
                    printf("surname :");
                    break;
                case'5':
                    printf("surname :");
                    break;
                case'6':
                    printf("Date :")
                    break;
                case'7':
                    printf("Region :");
                    break;


            }
            printf("%s", value);
            value = strtok(NULL, ", ");
            column++;
        }
        }
    fclose(file);

}