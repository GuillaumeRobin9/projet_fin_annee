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
    fprintf(htmlFILE, "    <div id=\"personBubble\" onmouseover=\"clicked('personBubble')\">\n            <div class=\"name\">Name : <a href=\"%d.html\">%s</a></div>\n            <div class=\"lastName\">Last Name : %s</div>\n            <div class=\"birthDay\">Birthday : %d/%d/%d</div>\n            <div class=\"region\">Region : %s</div>\n            <div class=\"infobulle\">\n                <div id=\"displayLocation\"></div>\n                <div id=\"latitude\"></div>\n                <div id=\"longitude\"></div>\n           </div>\n    </div>\n",getID(child), getFirstName(child), getLastName(child), getDay(child), getMonth(child), getYear(child), getRegion(child));
    fprintf(htmlFILE, "    <div id=\"father\" onmouseover=\"clicked('father')\">\n            <div class=\"name\">Name : <a href=\"%d.html\">%s</a></div>\n            <div class=\"lastName\">Last Name : %s</div>\n            <div class=\"birthDay\">Birthday : %d/%d/%d</div>\n            <div class=\"region\">Region : %s</div>\n            <div class=\"infobulle\">\n                <div id=\"displayLocation\"></div>\n                <div id=\"latitude\"></div>\n                <div id=\"longitude\"></div>\n           </div>\n    </div>\n", getID(father), getFirstName(father), getLastName(father), getDay(father), getMonth(father), getYear(father), getRegion(father));
    fprintf(htmlFILE, "    <div id=\"mother\" onmouseover=\"clicked('mother')\">\n            <div class=\"name\">Name : <a href=\"%d.html\">%s</a></div>\n            <div class=\"lastName\">Last Name : %s</div>\n            <div class=\"birthDay\">Birthday : %d/%d/%d</div>\n            <div class=\"region\">Region : %s</div>\n            <div class=\"infobulle\">\n                <div id=\"displayLocation\"></div>\n                <div id=\"latitude\"></div>\n                <div id=\"longitude\"></div>\n           </div>\n    </div>\n", getID(mother),getFirstName(mother), getLastName(mother), getDay(mother), getMonth(mother), getYear(mother), getRegion(mother));
    fprintf(htmlFILE, "    <div id=\"fatherGrandFather\" onmouseover=\"clicked('fatherGrandFather')\">\n            <div class=\"name\">Name : <a href=\"%d.html\">%s</a></div>\n            <div class=\"lastName\">Last Name : %s</div>\n            <div class=\"birthDay\">Birthday : %d/%d/%d</div>\n            <div class=\"region\">Region : %s</div>\n            <div class=\"infobulle\">\n                <div id=\"displayLocation\"></div>\n                <div id=\"latitude\"></div>\n                <div id=\"longitude\"></div>\n           </div>\n    </div>\n", getID(PaternalGFather), getFirstName(PaternalGFather), getLastName(PaternalGFather), getDay(PaternalGFather), getMonth(PaternalGFather), getYear(PaternalGFather), getRegion(PaternalGFather));
    fprintf(htmlFILE, "    <div id=\"fatherGrandMother\" onmouseover=\"clicked('fatherGrandMother')\">\n            <div class=\"name\">Name : <a href=\"%d.html\">%s</a></div>\n            <div class=\"lastName\">Last Name : %s</div>\n            <div class=\"birthDay\">Birthday : %d/%d/%d</div>\n            <div class=\"region\">Region : %s</div>\n            <div class=\"infobulle\">\n                <div id=\"displayLocation\"></div>\n                <div id=\"latitude\"></div>\n                <div id=\"longitude\"></div>\n           </div>\n    </div>\n", getID(PaternalGMother), getFirstName(PaternalGMother), getLastName(PaternalGMother), getDay(PaternalGMother), getMonth(PaternalGMother), getYear(PaternalGMother), getRegion(PaternalGMother));
    fprintf(htmlFILE, "    <div id=\"motherGrandFather\" onmouseover=\"clicked('motherGrandFather')\">\n            <div class=\"name\">Name : <a href=\"%d.html\">%s</a></div>\n            <div class=\"lastName\">Last Name : %s</div>\n            <div class=\"birthDay\">Birthday : %d/%d/%d</div>\n            <div class=\"region\">Region : %s</div>\n            <div class=\"infobulle\">\n                <div id=\"displayLocation\"></div>\n                <div id=\"latitude\"></div>\n                <div id=\"longitude\"></div>\n           </div>\n    </div>\n", getID(MaternalGFather), getFirstName(MaternalGFather), getLastName(MaternalGFather), getDay(MaternalGFather), getMonth(MaternalGFather), getYear(MaternalGFather), getRegion(MaternalGFather));
    fprintf(htmlFILE, "    <div id=\"motherGrandMother\" onmouseover=\"clicked('motherGrandMother')\">\n            <div class=\"name\">Name : <a href=\"%d.html\">%s</a></div>\n            <div class=\"lastName\">Last Name : %s</div>\n            <div class=\"birthDay\">Birthday : %d/%d/%d</div>\n            <div class=\"region\">Region : %s</div>\n            <div class=\"infobulle\">\n                <div id=\"displayLocation\"></div>\n                <div id=\"latitude\"></div>\n                <div id=\"longitude\"></div>\n           </div>\n    </div>\n", getID(MaternalGMother), getFirstName(MaternalGMother), getLastName(MaternalGMother), getDay(MaternalGMother), getMonth(MaternalGMother), getYear(MaternalGMother), getRegion(MaternalGMother));
    fprintf(htmlFILE, "    <script src=\"../resources/script.js\"></script>\n");
    fclose(htmlFILE);
}

void createHTMLOutput(struct dataBase* data, char *fileName) {

    // ** CREATION OF THE FILE **
    char directory[20] = "export/";

    printf("[INFO] -- Starting Output Process\n");
    FILE * htmlFILE;
    htmlFILE = fopen(strcat(strcat(directory, "tree"), ".html"), "w"); // "w" defines "writing mode"


    // ** HTML FILE BUILD **
    fprintf(htmlFILE, "<html lang=\"en\">\n");
    fprintf(htmlFILE, "<head>\n    <meta charset=\"UTF-8\">\n    <meta http-equiv=\"X-UA-Compatible\" content=\"IE=edge\">\n    <meta name=\"viewport\" content=\"width=device-width, initial-scale=1.0\">\n    <link rel=\"stylesheet\" href=\"../resources/style.css\">\n");
    fprintf(htmlFILE, "<title>PROJECT GROUPE 3</title>\n</head>\n<body>\n");
    fprintf(htmlFILE, "    <h2>Welcome to this genealogic tree retriever ! </h2>\n");
    fprintf(htmlFILE, "    <span id=\"startText\">Enter a Name to Start :</span> <input id=\"personName\" type=\"text\" placeholder=\"Dupont...\"><button type=\"button\" id=\"searchBtn\">Search</button>\n    <br><br>\n");
    fprintf(htmlFILE, "    <div>Statistics about your CSV File :</div>\n");
    fprintf(htmlFILE, "    <div id=\"csvName\">File Name : %s</div>\n", fileName);
    fprintf(htmlFILE, "    <div id=\"dataBaseLength\">Number of Person : [PERSON QUANTITY]</div>\n");
    fprintf(htmlFILE, "    <div class=\"bg\"></div>\n    <div class=\"bg bg2\"></div>\n    <div class=\"bg bg3\"></div>\n</body>\n</html>");
    fclose(htmlFILE);
}

