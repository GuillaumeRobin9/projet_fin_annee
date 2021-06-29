#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <time.h>

#include "structDataBase.h"
#include "dataBase_reader.h"
#include "menu.h"


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
    fprintf(htmlFILE,"    <div class=\"topnav\" id=\"myTopnav\">\n");
    fprintf(htmlFILE,"        <a href=\"tree.html\"class=\"active\">Index</a>\n");
    fprintf(htmlFILE,"        <a href=\"query.html\">Query</a>\n");
    fprintf(htmlFILE,"        <a href=\"about.html\">About</a>\n");
    fprintf(htmlFILE,"    </div>\n");
    /*fprintf(htmlFILE, "    <h2>Welcome to this genealogic tree retriever ! </h2>\n");*/
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

void createHTMLOutput(struct dataBase* data, char *fileName, int numberOfPerson) {

    // ** CREATION OF THE FILE **
    char directory[20] = "export/";

    printf("[INFO] -- Starting Output Process\n");
    FILE * htmlFILE;
    htmlFILE = fopen(strcat(strcat(directory, "tree"), ".html"), "w"); // "w" defines "writing mode"

    int day;
    int month;

    // ** HTML FILE BUILD **
    fprintf(htmlFILE, "<html lang=\"en\">\n");
    fprintf(htmlFILE, "<head>\n    <meta charset=\"UTF-8\">\n    <meta http-equiv=\"X-UA-Compatible\" content=\"IE=edge\">\n    <meta name=\"viewport\" content=\"width=device-width, initial-scale=1.0\">\n    <link rel=\"stylesheet\" href=\"../resources/style.css\">\n");
    fprintf(htmlFILE, "<title>PROJECT GROUPE 3</title>\n</head>\n<body>\n");
    fprintf(htmlFILE, "    <h2>Welcome to this genealogic tree retriever ! </h2>\n");
    fprintf(htmlFILE,"    <ul>\n");
    fprintf(htmlFILE, "        <span id=\"startText\">Enter a Name to Start :</span> \n    <input id=\"personName\" type=\"text\" placeholder=\"Dupont...\"><button type=\"button\" id=\"searchBtn\" onclick=\"foundPerson()\">Search</button>\n    <br><br>\n");
    fprintf(htmlFILE, "        <li><div>Statistics about your CSV File :</div></li>\n");
    fprintf(htmlFILE, "        <li><div id=\"csvName\">File Name : %s</div></li>\n", fileName);
    fprintf(htmlFILE, "        <li><div id=\"totalPerson\">Number of Person : %d </div></li>\n",numberOfPerson);
    fprintf(htmlFILE, "        <li><div>The most fertile region : %s </div></li>\n", getFertileRegion(data));
    fprintf(htmlFILE, "        <li><div>number of different natal regions : %d</div></li>\n", numberOfWords(getTrie(data)));
    fprintf(htmlFILE,"        <li><div>number of different birthdays dates : %d</div></li>\n", numberBirthDates(data));
    getDateWithMostBirths(data, &day, &month);
    fprintf(htmlFILE,"        <li><div>date with the most of births : %d/%d</div></li>\n", day, month);
    fprintf(htmlFILE,"        <li><div><button id=\"randomBtn\" onclick=\"randomPerson()\">Redirect to a random Person</button></div></li>\n");
    fprintf(htmlFILE,"    </ul>\n");
    fprintf(htmlFILE, "    <div class=\"bg\"></div>\n    <div class=\"bg bg2\"></div>\n    <div class=\"bg bg3\"></div>\n    <script src=\"../resources/treeScript.js\"></script>\n</body>\n</html>");
    fclose(htmlFILE);
}

// ** Query **
void createFillQueryHTMLFile(struct dataBase* data, int* numberQueries){
    struct timespec start, end; // clock

    createQueryResHTML(); // creation of the HTML

    char regionName[MAX_LEN]; // values initialisation
    int month;
    int day;

//    ** query 1 **
    green();
    printf("[INFO] -- 1 -- Here is the first person born\n\n");
    reset();

     // START chrono
    clock_gettime(CLOCK_REALTIME, &start);

    int IDoldest = getOldestID(data);
    printPerson(getPersonArray(data)[IDoldest]);
    fillHTMLQuery1(IDoldest, data); // adding the query to the HTML

    //  STOP chrono
    clock_gettime(CLOCK_REALTIME, &end);

    double time_spent = (end.tv_sec - start.tv_sec) + (end.tv_nsec - start.tv_nsec) / BILLION;

    green();
    printf("[INFO] -- Execution Time & writing in the HTML took : %f s\n", time_spent);
    reset();
    *numberQueries = *numberQueries + 1; //update number queries
    printf("--------------------------------------------------\n");

//    ** query 2 **
    green();
    printf("[INFO] -- 1 -- Here is the first person born\n\n");
    reset();

    // START chrono
    clock_gettime(CLOCK_REALTIME, &start);

    int IDyoungest = getyoungestID(data);
    printPerson(getPersonArray(data)[IDyoungest]);
    fillHTMLQuery2(IDyoungest, data); // adding the query to the file

    //  STOP chrono
    clock_gettime(CLOCK_REALTIME, &end);

    double time_spent2 = (end.tv_sec - start.tv_sec) + (end.tv_nsec - start.tv_nsec) / BILLION;

    green();
    printf("[INFO] -- Execution Time & writing in the HTML took : %f s\n", time_spent2);
    reset();

    *numberQueries = *numberQueries + 1; //update number queries
    printf("--------------------------------------------------\n");

//    ** query 3 **
    printf("[CHOICE] -- 3 -- Please enter the region name : \n");
    fgets(regionName, MAX_LEN, stdin);
    regionName[strlen(regionName) - 1] = '\0';
    bool valid;

    // START chrono
    clock_gettime(CLOCK_REALTIME, &start);

    int numberPeople = findBirthsOfRegion(getTrie(data), regionName, &valid);


    if (valid == false) {
        red();
        printf("[ERROR] -- the region entered does not exist\n");
        reset();
    } else {
        green();
        printf("[INFO] --  %d persons are born in the region named %s\n", numberPeople,regionName);
        reset();
        *numberQueries = *numberQueries + 1; //update number queries
        fillHTMLeQuery3(regionName, numberPeople); // adding the query to the file
    }

    //  STOP chrono
    clock_gettime(CLOCK_REALTIME, &end);
    double time_spent3 = (end.tv_sec - start.tv_sec) + (end.tv_nsec - start.tv_nsec) / BILLION;

    green();
    printf("[INFO] -- Execution Time & writing in the HTML took : %f s\n", time_spent3);
    reset();
    printf("--------------------------------------------------\n");

//    ** query 4 **
    // START chrono
    clock_gettime(CLOCK_REALTIME, &start);

    green();
    printf("[INFO] -- 4 --the region with the highest number of biths is named %s with %d births\n", getFertileRegion(data), getMaxBirths(data));
    reset();
    fillHTMLQuery4(getFertileRegion(data)); // adding the query to the file

    //  STOP chrono
    clock_gettime(CLOCK_REALTIME, &end);
    double time_spent4 = (end.tv_sec - start.tv_sec) + (end.tv_nsec - start.tv_nsec) / BILLION;

    green();
    printf("[INFO] -- Execution Time & writing in the HTML took : %f s\n", time_spent4);
    reset();
    *numberQueries = *numberQueries + 1; //update number queries
    printf("--------------------------------------------------\n");

//    ** query 5 **
    printf("[INFO] -- 5 \n");
    printf("[CHOICE] -- Please enter the day : ");
    scanf("%d", &day);
    fgetc(stdin);
    if (day <= 0 || day >= 32) {
        red();
        printf("\n[ERROR] -- invalid day\n");
        reset();
        printf("--------------------------------------------------\n");
    }
    else {
        printf("[CHOICE] -- Please enter the month : ");
        scanf("%d", &month);
        fgetc(stdin);
        if (month <= 0 || month >= 13) {
            red();
            printf("\n[ERROR] -- invalid month\n");
            reset();
            printf("--------------------------------------------------\n");
        }
        else {
            clock_gettime(CLOCK_REALTIME, &start);  // -- START chrono --
            green();
            printf("\n[INFO] -- %d peoples are born on %d/%d\n", data->birthdays[month][day], day, month);
            reset();

            fillHTMLQuery5(day, month, data->birthdays[month][day]); // adding the query to the HTML file

            clock_gettime(CLOCK_REALTIME, &end); //  --- STOP chrono --
            double time_spent5 = (end.tv_sec - start.tv_sec) + (end.tv_nsec - start.tv_nsec) / BILLION;

            green();
            printf("[INFO] -- Execution Time : %f s\n", time_spent5);
            reset();

            printf("--------------------------------------------------\n");
            printf("[INFO] -- Generating a HTML page with the Results of the previous Queries...\n");
            sleep(2);
            green();
            printf("[INFO] -- Successfully Generated Info Queries HTML Files in !\n");
            printf("[INFO] -- Total execution time of all the queries + filling HTML file : %f s !\n", time_spent + time_spent2 + time_spent3 + time_spent4 + time_spent5);
            reset();
            *numberQueries = *numberQueries + 1; //update number queries
        }
    }
}


