#include <stdlib.h>
#include <string.h>
#include <stdio.h>

int createHTMLOutput() {

    // ** CREATION OF THE FILE **
    printf("[INFO] -- Starting Output Process\n");
    FILE * htmlFILE;
    htmlFILE = fopen("tree.html", "w"); // "w" defines "writing mode"
    printf("[INFO] -- File Successfully Created !\n");


    // ** HTML FILE BUILD **
    fprintf(htmlFILE, "<html lang=\"en\">\n");
    fprintf(htmlFILE, "<head>\n    <meta charset=\"UTF-8\">\n    <meta http-equiv=\"X-UA-Compatible\" content=\"IE=edge\">\n    <meta name=\"viewport\" content=\"width=device-width, initial-scale=1.0\">\n    <link rel=\"stylesheet\" href=\"style.css\">\n");
    fprintf(htmlFILE, "<title>PROJECT GROUPE 3</title>\n</head>\n<body>\n");
    fprintf(htmlFILE, "    <h2>Welcome to this genealogic tree retriever ! </h2>\n");
    fprintf(htmlFILE, "    <span id=\"startText\">Enter a Name to Start :</span> <input id=\"personName\" type=\"text\" placeholder=\"Dupont...\">\n<br><br>");
    fprintf(htmlFILE, "    <div>Statistics about your CSV File :</div>\n");
    fprintf(htmlFILE, "    <div id=\"csvName\">File Name : [FILE NAME HERE]</div>\n");
    fprintf(htmlFILE, "    <div id=\"dataBaseLength\">Number of Person : [PERSON QUANTITY]</div>\n");
    fprintf(htmlFILE, "    <div class=\"bg\"></div>\n    <div class=\"bg bg2\"></div>\n    <div class=\"bg bg3\"></div>\n</body>\n</html>");
    fclose(htmlFILE);
    return 0;
}



