//
// Project: projet_fin_annee
// Authors: Antoine SOYDEMIR, Guillaume ROBIN, Mickaël NERODA
// Creation date: 25/06/2021
// Modification date: 29/06/2021
// Role: functions that creates the HTML pages
//

//-------------------------------------------------------------------------
//--- Functions Implementation --------------------------------------------
//-------------------------------------------------------------------------

// Includes
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <time.h>

#include "structDataBase.h"
#include "htmlGenerator.h"
#include "menu.h"

//
// -=[Function Description]=-
// Function that creates HTML file that contains the tree of a person.
//
void createPersonHTMLFile(struct Person* child, struct Person* father, struct Person* mother, struct Person* PaternalGFather, struct Person* PaternalGMother, struct Person* MaternalGFather, struct Person* MaternalGMother) {

    int personID = getID(child);
    char fileName[20];
    char directory[20] = "export/";
    sprintf(fileName, "%d", personID);


    // ** CREATION OF THE PERSON FILE **
    FILE * htmlFILE;


    htmlFILE = fopen(strcat(strcat(directory, fileName), ".html"),  "w"); // "w" defines "writing mode"

    // ** HTML FILE BUILD **
    fprintf(htmlFILE, "<html lang=\"en\">\n");
    fprintf(htmlFILE, "<head>\n    <meta charset=\"UTF-8\">\n    <meta http-equiv=\"X-UA-Compatible\" content=\"IE=edge\">\n    <meta name=\"viewport\" content=\"width=device-width, initial-scale=1.0\">\n    <link rel=\"stylesheet\" href=\"../resources/stylePersonPage.css\">\n");
    fprintf(htmlFILE, "    <title>PROJECT GROUPE 3</title>\n</head>\n<body>\n");
    fprintf(htmlFILE,"    <div class=\"topnav\" id=\"myTopnav\">\n");
    fprintf(htmlFILE,"        <a href=\"tree.html\"class=\"active\">Index</a>\n");
    fprintf(htmlFILE,"        <a href=\"query.html\">Query</a>\n");
    fprintf(htmlFILE,"    </div>\n");
    fprintf(htmlFILE, "    <div id=\"personBubble\" onmouseover=\"clicked('personBubble')\">\n            <div class=\"name\">Name : <a href=\"%d.html\">%s</a></div>\n            <div class=\"lastName\">Last Name : %s</div>\n            <div class=\"birthDay\">Birthday : %d/%d/%d</div>\n            <div class=\"region\">Region : %s</div>\n            <div class=\"infobulle\">\n                <div id=\"displayLocation\"></div>\n                <div id=\"latitude\"></div>\n                <div id=\"longitude\"></div>\n           </div>\n    </div>\n",getID(child), getFirstName(child), getLastName(child), getDay(child), getMonth(child), getYear(child), getRegion(child));
    fprintf(htmlFILE, "    <div id=\"father\" onmouseover=\"clicked('father')\">\n            <div class=\"name\">Name : <a href=\"%d.html\">%s</a></div>\n            <div class=\"lastName\">Last Name : %s</div>\n            <div class=\"birthDay\">Birthday : %d/%d/%d</div>\n            <div class=\"region\">Region : %s</div>\n            <div class=\"infobulle\">\n                <div id=\"displayLocation\"></div>\n                <div id=\"latitude\"></div>\n                <div id=\"longitude\"></div>\n           </div>\n    </div>\n", getID(father), getFirstName(father), getLastName(father), getDay(father), getMonth(father), getYear(father), getRegion(father));
    fprintf(htmlFILE, "    <div id=\"mother\" onmouseover=\"clicked('mother')\">\n            <div class=\"name\">Name : <a href=\"%d.html\">%s</a></div>\n            <div class=\"lastName\">Last Name : %s</div>\n            <div class=\"birthDay\">Birthday : %d/%d/%d</div>\n            <div class=\"region\">Region : %s</div>\n            <div class=\"infobulle\">\n                <div id=\"displayLocation\"></div>\n                <div id=\"latitude\"></div>\n                <div id=\"longitude\"></div>\n           </div>\n    </div>\n", getID(mother),getFirstName(mother), getLastName(mother), getDay(mother), getMonth(mother), getYear(mother), getRegion(mother));
    fprintf(htmlFILE, "    <div id=\"fatherGrandFather\" onmouseover=\"clicked('fatherGrandFather')\">\n            <div class=\"name\">Name : <a href=\"%d.html\">%s</a></div>\n            <div class=\"lastName\">Last Name : %s</div>\n            <div class=\"birthDay\">Birthday : %d/%d/%d</div>\n            <div class=\"region\">Region : %s</div>\n            <div class=\"infobulle\">\n                <div id=\"displayLocation\"></div>\n                <div id=\"latitude\"></div>\n                <div id=\"longitude\"></div>\n           </div>\n    </div>\n", getID(PaternalGFather), getFirstName(PaternalGFather), getLastName(PaternalGFather), getDay(PaternalGFather), getMonth(PaternalGFather), getYear(PaternalGFather), getRegion(PaternalGFather));
    fprintf(htmlFILE, "    <div id=\"fatherGrandMother\" onmouseover=\"clicked('fatherGrandMother')\">\n            <div class=\"name\">Name : <a href=\"%d.html\">%s</a></div>\n            <div class=\"lastName\">Last Name : %s</div>\n            <div class=\"birthDay\">Birthday : %d/%d/%d</div>\n            <div class=\"region\">Region : %s</div>\n            <div class=\"infobulle\">\n                <div id=\"displayLocation\"></div>\n                <div id=\"latitude\"></div>\n                <div id=\"longitude\"></div>\n           </div>\n    </div>\n", getID(PaternalGMother), getFirstName(PaternalGMother), getLastName(PaternalGMother), getDay(PaternalGMother), getMonth(PaternalGMother), getYear(PaternalGMother), getRegion(PaternalGMother));
    fprintf(htmlFILE, "    <div id=\"motherGrandFather\" onmouseover=\"clicked('motherGrandFather')\">\n            <div class=\"name\">Name : <a href=\"%d.html\">%s</a></div>\n            <div class=\"lastName\">Last Name : %s</div>\n            <div class=\"birthDay\">Birthday : %d/%d/%d</div>\n            <div class=\"region\">Region : %s</div>\n            <div class=\"infobulle\">\n                <div id=\"displayLocation\"></div>\n                <div id=\"latitude\"></div>\n                <div id=\"longitude\"></div>\n           </div>\n    </div>\n", getID(MaternalGFather), getFirstName(MaternalGFather), getLastName(MaternalGFather), getDay(MaternalGFather), getMonth(MaternalGFather), getYear(MaternalGFather), getRegion(MaternalGFather));
    fprintf(htmlFILE, "    <div id=\"motherGrandMother\" onmouseover=\"clicked('motherGrandMother')\">\n            <div class=\"name\">Name : <a href=\"%d.html\">%s</a></div>\n            <div class=\"lastName\">Last Name : %s</div>\n            <div class=\"birthDay\">Birthday : %d/%d/%d</div>\n            <div class=\"region\">Region : %s</div>\n            <div class=\"infobulle\">\n                <div id=\"displayLocation\"></div>\n                <div id=\"latitude\"></div>\n                <div id=\"longitude\"></div>\n           </div>\n    </div>\n", getID(MaternalGMother), getFirstName(MaternalGMother), getLastName(MaternalGMother), getDay(MaternalGMother), getMonth(MaternalGMother), getYear(MaternalGMother), getRegion(MaternalGMother));
    fprintf(htmlFILE, "    <script src=\"../resources/scriptIndex.js\"></script>\n");
    fprintf(htmlFILE, "</body>\n</html>");
    fclose(htmlFILE);
}

//
// -=[Function Description]=-
// Function to create the index HTML page with the general informations about the genealogical tree, the tree search by name function, and the feature to show a random tree.
//
void createIndexHTMLFile(struct dataBase* data, char *fileName, int numberOfPerson) {

    // ** CREATION OF THE INDEX FILE **
    char directory[20] = "export/";

    printf("[INFO] -- Starting Output Process\n");
    FILE * htmlFILE;
    htmlFILE = fopen(strcat(strcat(directory, "tree"), ".html"), "w"); // "w" defines "writing mode"

    int day;
    int month;

    // ** HTML FILE BUILD **
    fprintf(htmlFILE, "<html lang=\"en\">\n");
    fprintf(htmlFILE, "<head>\n    <meta charset=\"UTF-8\">\n    <meta http-equiv=\"X-UA-Compatible\" content=\"IE=edge\">\n    <meta name=\"viewport\" content=\"width=device-width, initial-scale=1.0\">\n    <link rel=\"stylesheet\" href=\"https://cdn.jsdelivr.net/npm/bootstrap@4.6.0/dist/css/bootstrap.min.css\">\n     <link rel=\"stylesheet\" href=\"https://cdn.jsdelivr.net/npm/bootstrap-icons@1.5.0/font/bootstrap-icons.css\">\n    <link rel=\"stylesheet\" href=\"../resources/styleIndexPage.css\">\n");
    fprintf(htmlFILE, "<title>PROJECT GROUPE 3</title>\n</head>\n<body>\n");
    fprintf(htmlFILE, "    <h2>Welcome to this genealogical tree retriever ! </h2>\n");
    fprintf(htmlFILE,"    <br><br>\n");
    fprintf(htmlFILE,"    <ul>\n");
    fprintf(htmlFILE, "        <span id=\"startText\"><i class=\"bi bi-search\"></i>    Enter a Name to Start :</span> \n        <input id=\"personName\" type=\"text\" placeholder=\"Dupont...\"><button type=\"button\" id=\"searchBtn\" onclick=\"foundPerson()\">Search</button>\n        <br><br>\n"); // feature of tree search by the name of the person
    fprintf(htmlFILE, "        <li><div><i class=\"bi bi-file-text\"></i>   Statistics about your CSV File :</div></li>\n");
    fprintf(htmlFILE, "        <li><div id=\"csvName\"><i class=\"bi bi-file-text-fill\"></i>   File Name : %s</div></li>\n", fileName); // START -writting in the HTML file the general informations about the tree
    fprintf(htmlFILE, "        <li><div id=\"totalPerson\"><i class=\"bi bi-list-ol\"></i>  Number of Person : %d </div></li>\n",numberOfPerson);
    fprintf(htmlFILE, "        <li><div><i class=\"bi bi-geo-alt\"></i> The most fertile region : %s </div></li>\n", getFertileRegion(data));
    fprintf(htmlFILE, "        <li><div><i class=\"bi bi-map\"></i> number of different natal regions : %d</div></li>\n", numberOfWords(getTrie(data)));
    fprintf(htmlFILE,"        <li><div><i class=\"bi bi-gift\"></i> number of different birthdays dates : %d</div></li>\n", numberBirthDates(data));
    getDateWithMostBirths(data, &day, &month);
    fprintf(htmlFILE,"        <li><div><i class=\"bi bi-calendar-event\"></i>   date with the most of births : %d/%d</div></li>\n", day, month); // START -writting in the HTML file the general informations about the tree
    fprintf(htmlFILE,"        <li><div><button id=\"randomBtn\" onclick=\"randomPerson()\">Redirect to a random Person</button></div></li>\n"); // adding to the HTML the button that redirect to a random tree
    fprintf(htmlFILE,"    </ul>\n");
    fprintf(htmlFILE, "    <div class=\"bg\"></div>\n    <div class=\"bg bg2\"></div>\n    <div class=\"bg bg3\"></div>\n    <script src=\"../resources/scriptPerson.js\"></script>\n</body>\n</html>");
    fclose(htmlFILE);
}

// ** Query **

//
// -=[Function Description]=-
// Function that execute all the queries of the query menu, and create an HTML page according to the queries asked by the user.
//
void createQueryHTMLFile(struct dataBase* data, int* numberQueries){
    struct timespec start, end; // clock

    openQueryHTMLFile(); // creation of the HTML

    char regionName[MAX_LEN]; // values initialisation
    int month;
    int day;

// -------- [QUERY n°1. Get first born in the tree]
    green();
    printf("[INFO] -- 1 -- Here is the first person born\n\n");
    reset();

     // START chrono
    clock_gettime(CLOCK_REALTIME, &start);

    int IDoldest = getOldestID(data);
    printPerson(getPersonArray(data)[IDoldest]);
    fillHTMLQuery1(IDoldest, data); // writing the result of the query in the HTML file

    //  STOP chrono
    clock_gettime(CLOCK_REALTIME, &end);

    double time_spent = (end.tv_sec - start.tv_sec) + (end.tv_nsec - start.tv_nsec) / BILLION;

    green();
    printf("[INFO] -- Execution Time & writing in the HTML took : %f s\n", time_spent);
    reset();
    *numberQueries = *numberQueries + 1; //update number queries
    printf("--------------------------------------------------\n");

// -------- [QUERY n°2. Get last born in the tree]
    green();
    printf("[INFO] -- 1 -- Here is the last person born\n\n");
    reset();

    // START chrono
    clock_gettime(CLOCK_REALTIME, &start);

    int IDyoungest = getyoungestID(data);
    printPerson(getPersonArray(data)[IDyoungest]);
    fillHTMLQuery2(IDyoungest, data); // writing the result of the query in the HTML file

    //  STOP chrono
    clock_gettime(CLOCK_REALTIME, &end);

    double time_spent2 = (end.tv_sec - start.tv_sec) + (end.tv_nsec - start.tv_nsec) / BILLION;

    green();
    printf("[INFO] -- Execution Time & writing in the HTML took : %f s\n", time_spent2);
    reset();

    *numberQueries = *numberQueries + 1; //update number queries
    printf("--------------------------------------------------\n");

// -------- [QUERY n°3. Get number of people born in a region]
    printf("[choice] -- 3 -- Please enter the region name : \n");
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
        fillHTMLeQuery3(regionName, numberPeople); // writing the result of the query in the HTML file
    }

    //  STOP chrono
    clock_gettime(CLOCK_REALTIME, &end);
    double time_spent3 = (end.tv_sec - start.tv_sec) + (end.tv_nsec - start.tv_nsec) / BILLION;

    green();
    printf("[INFO] -- Execution Time & writing in the HTML took : %f s\n", time_spent3);
    reset();
    printf("--------------------------------------------------\n");

// -------- [QUERY n°4. Get the region with the highest number of births]
    // START chrono
    clock_gettime(CLOCK_REALTIME, &start);

    green();
    printf("[INFO] -- 4 --the region with the highest number of biths is named %s with %d births\n", getFertileRegion(data), getMaxBirths(data));
    reset();
    fillHTMLQuery4(getFertileRegion(data)); // writing the result of the query in the HTML file

    //  STOP chrono
    clock_gettime(CLOCK_REALTIME, &end);
    double time_spent4 = (end.tv_sec - start.tv_sec) + (end.tv_nsec - start.tv_nsec) / BILLION;

    green();
    printf("[INFO] -- Execution Time & writing in the HTML took : %f s\n", time_spent4);
    reset();
    *numberQueries = *numberQueries + 1; //update number queries
    printf("--------------------------------------------------\n");

// -------- [QUERY n°5. Get the number of people born in a given day and month]
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

            fillHTMLQuery5(day, month, data->birthdays[month][day]); // writing the result of the query in the HTML file

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

// ** query Result File filling **

//
// -=[Function Description]=-
// Function create the query result HTML file.
//
void openQueryHTMLFile() {
    FILE *queryHtml;
    queryHtml = fopen("export/query.html", "w"); // creationg the HTML queryRes file
    fprintf(queryHtml, "<html lang=\"en\">\n");
    fprintf(queryHtml,"<head>\n    <meta charset=\"UTF-8\">\n    <meta http-equiv=\"X-UA-Compatible\" content=\"IE=edge\">\n    <meta name=\"viewport\" content=\"width=device-width, initial-scale=1.0\">\n    <link rel=\"stylesheet\" href=\"https://cdn.jsdelivr.net/npm/bootstrap@4.6.0/dist/css/bootstrap.min.css\">\n   <link rel=\"stylesheet\" href=\"https://cdn.jsdelivr.net/npm/bootstrap-icons@1.5.0/font/bootstrap-icons.css\">\n   <link rel=\"stylesheet\" href=\"../resources/styleQueryPage.css\">\n");
    fprintf(queryHtml, "    <title>PROJECT GROUPE 3</title>\n</head>\n<body>\n");
    fprintf(queryHtml,"    <div class=\"topnav\" id=\"myTopnav\">\n");
    fprintf(queryHtml,"        <a href=\"tree.html\"class=\"active\">Index</a>\n");
    fprintf(queryHtml,"        <a href=\"query.html\">Query</a>\n");
    fprintf(queryHtml,"    </div>\n");
    fprintf(queryHtml, "    <h2>Welcome to the Query Result Page ! </h2>\n");
    fprintf(queryHtml,"    <div id=\"shape\">\n");
    fprintf(queryHtml, "    <div class=\"bg\"></div>\n    <div class=\"bg bg2\"></div>\n    <div class=\"bg bg3\"></div>\n");
    fclose(queryHtml); // closing file
}

//
// -=[Function Description]=-
// Function to write the result of the query  n°1. "Get first born in the tree" in the HTML file.
//
void fillHTMLQuery1(int ID, struct dataBase* data){
    // ** OPENING  FILE **
    FILE * queryHtml;
    queryHtml = fopen("export/query.html", "a");

    // **  FILE BUILD **
    fprintf(queryHtml,"     <div class=\"titleInfo\"><i class=\"bi bi-file-person\"></i> Here is the first person born :</div>  <div class=\"info\">First Name : %s, Last Name : %s, Birthday : %d/%d/%d, Natal Region : %s</div>\n", getFirstName(getPersonArray(data)[ID]), getLastName(getPersonArray(data)[ID]), getDay(getPersonArray(data)[ID]), getMonth(getPersonArray(data)[ID]), getYear(getPersonArray(data)[ID]), getRegion(getPersonArray(data)[ID]));
    fclose(queryHtml);
}


//
// -=[Function Description]=-
// Function to write the result of the query  n°2. "Get last born in the tree" in the HTML file.
//
void fillHTMLQuery2(int ID, struct dataBase* data){
    // ** OPENING  FILE **
    FILE * queryHtml;
    queryHtml = fopen("export/query.html", "a");

    // **  FILE BUILD **
    fprintf(queryHtml,"     <div class=\"titleInfo\"><i class=\"bi bi-file-person-fill\"></i>Here is the last person born :</div>  <div class=\"info\">First Name : %s, Last Name : %s, Birthday : %d/%d/%d, Natal Region : %s</div>\n", getFirstName(getPersonArray(data)[ID]), getLastName(getPersonArray(data)[ID]), getDay(getPersonArray(data)[ID]), getMonth(getPersonArray(data)[ID]), getYear(getPersonArray(data)[ID]), getRegion(getPersonArray(data)[ID]));
    fclose(queryHtml);
}


//
// -=[Function Description]=-
// Function to write the result of the query  n°3. "Get number of people born in a region" in the HTML file.
//
void fillHTMLeQuery3(char* regionName, int numberPersonBorn){
    // ** OPENING  FILE **
    FILE * queryHtml;
    queryHtml = fopen("export/query.html", "a");

    // **  FILE BUILD **
    fprintf(queryHtml,"     <div class=\"titleInfo\">    <i class=\"bi bi-file-person-fill\"></i>    Result Number people born in the Region %s :</div>  <div class=\"info\">%d</div>\n", regionName, numberPersonBorn);
    fclose(queryHtml);
}


//
// -=[Function Description]=-
// Function to write the result of the query  n°4. "Get the region with the highest number of births" in the HTML file.
//
void fillHTMLQuery4(char* regionName){
    // ** OPENING  FILE **
    FILE * queryHtml;
    queryHtml = fopen("export/query.html", "a");

    // **  FILE BUILD **
    fprintf(queryHtml,"     <div class=\"titleInfo\"><i class=\"bi bi-map\"></i>    The Region with highest number of births is  :</div>  <div class=\"info\">%s</div>\n", regionName);
    fclose(queryHtml);
}



//
// -=[Function Description]=-
// Function to write the result of the query  n°5. "Get the number of people born in a given day and month" in the HTML file.
//
void fillHTMLQuery5(int day, int month, int numberPerson){
    // ** OPENING  FILE **
    FILE * queryHtml;
    queryHtml = fopen("export/query.html", "a");

    // **  FILE BUILD **
    fprintf(queryHtml,"     <div class=\"titleInfo\"><i class=\"bi bi-calendar\"></i>    Result of the number of people born on %d/%d :</div>  <div class=\"info\">%d</div>\n</body>\n</html>\n", day, month, numberPerson);
    fclose(queryHtml);
}


