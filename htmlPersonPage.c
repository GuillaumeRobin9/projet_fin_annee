#include <stdlib.h>
#include <string.h>
#include <stdio.h>

#include "structDataBase.h"
#include "dataBase_reader.h"

void createPersonHTMLFile(struct Person* child, struct Person* father, struct Person* mother, struct Person* PaternalGFather, struct Person* PaternalGMother, struct Person* MaternalGFather, struct Person* MaternalGMother) {

    int personID = getID(child);
    char fileName[20];
    sprintf(fileName, "%d", personID);


    // ** CREATION OF THE FILE **
    FILE * htmlFILE;


    htmlFILE = fopen(strcat(fileName, ".html"),  "w"); // "w" defines "writing mode"




    // ** HTML FILE BUILD **
    fprintf(htmlFILE, "<html lang=\"en\">\n");
    fprintf(htmlFILE, "<head>\n    <meta charset=\"UTF-8\">\n    <meta http-equiv=\"X-UA-Compatible\" content=\"IE=edge\">\n    <meta name=\"viewport\" content=\"width=device-width, initial-scale=1.0\">\n    <link rel=\"stylesheet\" href=\"./resources/style2.css\">\n");
    fprintf(htmlFILE, "<title>PROJECT GROUPE 3</title>\n</head>\n<body>\n");
    fprintf(htmlFILE, "    <h2>Welcome to this genealogic tree retriever ! </h2>\n");
    fprintf(htmlFILE, "    <div id=\"personBubble\">\n            <div id=\"name\">Name : %s</div>\n            <div id=\"lastName\">Last Name : %s</div>\n            <div id=\"birthDay\">Birthday : %d/%d/%d</div>\n    </div>\n", getFirstName(child), getLastName(child), getDay(child), getMonth(child), getYear(child));
    fprintf(htmlFILE, "    <div id=\"father\">\n            <div id=\"name\">Name : %s</div>\n            <div id=\"lastName\">Last Name : %s</div>\n            <div id=\"birthDay\">Birthday : %d/%d/%d</div>\n    </div>\n", getFirstName(father), getLastName(father), getDay(father), getMonth(father), getYear(father));
    fprintf(htmlFILE, "    <div id=\"mother\">\n            <div id=\"name\">Name : %s</div>\n            <div id=\"lastName\">Last Name : %s</div>\n            <div id=\"birthDay\">Birthday : %d/%d/%d</div>\n    </div>\n", getFirstName(mother), getLastName(mother), getDay(mother), getMonth(mother), getYear(mother));
    fprintf(htmlFILE, "    <div id=\"fatherGrandFather\">\n            <div id=\"name\">Name : %s</div>\n            <div id=\"lastName\">Last Name : %s</div>\n            <div id=\"birthDay\">Birthday : %d/%d/%d</div>\n    </div>\n", getFirstName(PaternalGFather), getLastName(PaternalGFather), getDay(PaternalGFather), getMonth(PaternalGFather), getYear(PaternalGFather));
    fprintf(htmlFILE, "    <div id=\"fatherGrandMother\">\n            <div id=\"name\">Name : %s</div>\n            <div id=\"lastName\">Last Name : %s</div>\n            <div id=\"birthDay\">Birthday : %d/%d/%d</div>\n    </div>\n", getFirstName(PaternalGMother), getLastName(PaternalGMother), getDay(PaternalGMother), getMonth(PaternalGMother), getYear(PaternalGMother));
    fprintf(htmlFILE, "    <div id=\"motherGrandFather\">\n            <div id=\"name\">Name : %s</div>\n            <div id=\"lastName\">Last Name : %s</div>\n            <div id=\"birthDay\">Birthday : %d/%d/%d</div>\n    </div>\n", getFirstName(MaternalGFather), getLastName(MaternalGFather), getDay(MaternalGFather), getMonth(MaternalGFather), getYear(MaternalGFather));
    fprintf(htmlFILE, "    <div id=\"motherGrandMother\">\n            <div id=\"name\">Name : %s</div>\n            <div id=\"lastName\">Last Name : %s</div>\n            <div id=\"birthDay\">Birthday : %d/%d/%d</div>\n    </div>\n", getFirstName(MaternalGMother), getLastName(MaternalGMother), getDay(MaternalGMother), getMonth(MaternalGMother), getYear(MaternalGMother));
    fclose(htmlFILE);
}

