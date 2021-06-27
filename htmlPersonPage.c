#include <stdlib.h>
#include <string.h>
#include <stdio.h>

#include "structDataBase.h"
#include "dataBase_reader.h"

void createPersonHTMLFile(struct Person* child, struct Person* father, struct Person* mother, struct Person* PaternalGFather, struct Person* PaternalGMother, struct Person* MaternalGFather, struct Person* MaternalGMother) {

    int personID = getID(child);
    char fileName[20];
    char directory[20] = "export/";
    sprintf(fileName, "%d", personID);


    // ** CREATION OF THE FILE **
    FILE * htmlFILE;


    htmlFILE = fopen(strcat(strcat(directory, fileName), ".html"),  "w"); // "w" defines "writing mode"




    // ** HTML FILE BUILD **
    fprintf(htmlFILE, "<html lang=\"en\">\n");
    fprintf(htmlFILE, "<head>\n    <meta charset=\"UTF-8\">\n    <meta http-equiv=\"X-UA-Compatible\" content=\"IE=edge\">\n    <meta name=\"viewport\" content=\"width=device-width, initial-scale=1.0\">\n    <link rel=\"stylesheet\" href=\"../resources/style2.css\">\n");
    fprintf(htmlFILE, "<title>PROJECT GROUPE 3</title>\n</head>\n<body>\n");
    fprintf(htmlFILE, "    <h2>Welcome to this genealogic tree retriever ! </h2>\n");
    fprintf(htmlFILE, "    <div id=\"personBubble\">\n            <div class=\"name\">Name : %s</div>\n            <div class=\"lastName\">Last Name : %s</div>\n            <div class=\"birthDay\">Birthday : %d/%d/%d</div>\n            <div class=\"region\">Region : %s</div>\n           <a href=\"%d.html\">%s Tree</a>\n    </div>\n", getFirstName(child), getLastName(child), getDay(child), getMonth(child), getYear(child), getRegion(child), getID(child), getFirstName(child));
    fprintf(htmlFILE, "    <div id=\"father\">\n            <div class=\"name\">Name : %s</div>\n            <div class=\"lastName\">Last Name : %s</div>\n            <div class=\"birthDay\">Birthday : %d/%d/%d</div>\n            <div class=\"region\">Region : %s</div>\n           <a href=\"%d.html\">%s Tree</a>\n    </div>\n", getFirstName(father), getLastName(father), getDay(father), getMonth(father), getYear(father), getRegion(father), getID(father), getFirstName(father));
    fprintf(htmlFILE, "    <div id=\"mother\">\n            <div class=\"name\">Name : %s</div>\n            <div class=\"lastName\">Last Name : %s</div>\n            <div class=\"birthDay\">Birthday : %d/%d/%d</div>\n            <div class=\"region\">Region : %s</div>\n           <a href=\"%d.html\">%s Tree</a>\n    </div>\n", getFirstName(mother), getLastName(mother), getDay(mother), getMonth(mother), getYear(mother), getRegion(mother), getID(mother), getFirstName(mother));
    fprintf(htmlFILE, "    <div id=\"fatherGrandFather\">\n            <div class=\"name\">Name : %s</div>\n            <div class=\"lastName\">Last Name : %s</div>\n            <div class=\"birthDay\">Birthday : %d/%d/%d</div>\n            <div class=\"region\">Region : %s</div>\n           <a href=\"%d.html\">%s Tree</a>\n    </div>\n", getFirstName(PaternalGFather), getLastName(PaternalGFather), getDay(PaternalGFather), getMonth(PaternalGFather), getYear(PaternalGFather), getRegion(PaternalGFather), getID(PaternalGFather), getFirstName(PaternalGFather));
    fprintf(htmlFILE, "    <div id=\"fatherGrandMother\">\n            <div class=\"name\">Name : %s</div>\n            <div class=\"lastName\">Last Name : %s</div>\n            <div class=\"birthDay\">Birthday : %d/%d/%d</div>\n            <div class=\"region\">Region : %s</div>\n           <a href=\"%d.html\">%s Tree</a>\n    </div>\n", getFirstName(PaternalGMother), getLastName(PaternalGMother), getDay(PaternalGMother), getMonth(PaternalGMother), getYear(PaternalGMother), getRegion(PaternalGMother), getID(PaternalGMother), getFirstName(PaternalGMother));
    fprintf(htmlFILE, "    <div id=\"motherGrandFather\">\n            <div class=\"name\">Name : %s</div>\n            <div class=\"lastName\">Last Name : %s</div>\n            <div class=\"birthDay\">Birthday : %d/%d/%d</div>\n            <div class=\"region\">Region : %s</div>\n           <a href=\"%d.html\">%s Tree</a>\n    </div>\n", getFirstName(MaternalGFather), getLastName(MaternalGFather), getDay(MaternalGFather), getMonth(MaternalGFather), getYear(MaternalGFather), getRegion(MaternalGFather), getID(MaternalGFather), getFirstName(MaternalGFather));
    fprintf(htmlFILE, "    <div id=\"motherGrandMother\">\n            <div class=\"name\">Name : %s</div>\n            <div class=\"lastName\">Last Name : %s</div>\n            <div class=\"birthDay\">Birthday : %d/%d/%d</div>\n            <div class=\"region\">Region : %s</div>\n           <a href=\"%d.html\">%s Tree</a>\n    </div>\n", getFirstName(MaternalGMother), getLastName(MaternalGMother), getDay(MaternalGMother), getMonth(MaternalGMother), getYear(MaternalGMother), getRegion(MaternalGMother), getID(MaternalGMother), getFirstName(MaternalGMother));
    fprintf(htmlFILE, "    <script src=\"../resources/script.js\"></script>\n");
    fclose(htmlFILE);
}

