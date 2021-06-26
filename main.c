#include <stdlib.h>
#include <string.h>
#include <stdio.h>

#include "file_reader.h"
#include "structDataBase.h"
//#include "file_reader.c"


int main() {

    printf("[INFO] -- Starting Output Process\n");

    struct dataBase* data = read("bd_petite.csv");
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
    return 0;
}









































