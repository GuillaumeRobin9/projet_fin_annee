#include <stdlib.h>
#include <string.h>
#include <stdio.h>


int main() {

    // ** CREATION OF THE FILE **
    printf("[INFO] -- Starting Output Process\n");
    FILE * htmlFILE;

    char personID[] = "2";


    htmlFILE = fopen(strcat(&personID, ".html"),  "w"); // "w" defines "writing mode"

    printf("[INFO] -- File Successfully Created !\n");


    // ** HTML FILE BUILD **
    fprintf(htmlFILE, "<html lang=\"en\">\n");
    fprintf(htmlFILE, "<head>\n    <meta charset=\"UTF-8\">\n    <meta http-equiv=\"X-UA-Compatible\" content=\"IE=edge\">\n    <meta name=\"viewport\" content=\"width=device-width, initial-scale=1.0\">\n    <link rel=\"stylesheet\" href=\"./resources/style2.css\">\n");
    fprintf(htmlFILE, "<title>PROJECT GROUPE 3</title>\n</head>\n<body>\n");
    fprintf(htmlFILE, "    <h2>Welcome to this genealogic tree retriever ! </h2>\n");
    fprintf(htmlFILE, "    <div id=\"personBubble\">\n            <div id=\"name\">Name : Mathis</div>\n            <div id=\"lastName\">Last Name : Bours</div>\n            <div id=\"birthDay\">Birthday : 15/03/2000</div>\n    </div>\n");
    fprintf(htmlFILE, "    <div id=\"father\">\n            <div id=\"name\">Name : Francis</div>\n            <div id=\"lastName\">Last Name : Montagne</div>\n            <div id=\"birthDay\">Birthday : 15/03/2003</div>\n    </div>\n");
    fprintf(htmlFILE, "    <div id=\"mother\">\n            <div id=\"name\">Name : Jeanne</div>\n            <div id=\"lastName\">Last Name : Montagne</div>\n            <div id=\"birthDay\">Birthday : 15/03/1997</div>\n    </div>\n");
    fprintf(htmlFILE, "    <div id=\"fatherGrandFather\">\n            <div id=\"name\">Name : Jeanne</div>\n            <div id=\"lastName\">Last Name : Montagne</div>\n            <div id=\"birthDay\">Birthday : 15/03/1997</div>\n    </div>\n");
    fprintf(htmlFILE, "    <div id=\"fatherGrandMother\">\n            <div id=\"name\">Name : Jeanne</div>\n            <div id=\"lastName\">Last Name : Montagne</div>\n            <div id=\"birthDay\">Birthday : 15/03/1997</div>\n    </div>\n");
    fprintf(htmlFILE, "    <div id=\"motherGrandFather\">\n            <div id=\"name\">Name : Jeanne</div>\n            <div id=\"lastName\">Last Name : Montagne</div>\n            <div id=\"birthDay\">Birthday : 15/03/1997</div>\n    </div>\n");
    fprintf(htmlFILE, "    <div id=\"motherGrandMother\">\n            <div id=\"name\">Name : Jeanne</div>\n            <div id=\"lastName\">Last Name : Montagne</div>\n            <div id=\"birthDay\">Birthday : 15/03/1997</div>\n    </div>\n");
    fclose(htmlFILE);
    return 0;
}

