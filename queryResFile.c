//
// Created by micka on 27/06/2021.
//
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

#include "dataBase_reader.h"
#include "structDataBase.h"
#include "menu.h"

void createQueryResHTML() { // creation of the  file
    FILE *queryHtml;
    queryHtml = fopen("export/query.html", "w"); // creationg the HTML queryRes file
    fprintf(queryHtml, "<html lang=\"en\">\n");
    fprintf(queryHtml,"<head>\n    <meta charset=\"UTF-8\">\n    <meta http-equiv=\"X-UA-Compatible\" content=\"IE=edge\">\n    <meta name=\"viewport\" content=\"width=device-width, initial-scale=1.0\">\n    <link rel=\"stylesheet\" href=\"../resources/styleQueryPage.css\">\n");
    fprintf(queryHtml, "<title>PROJECT GROUPE 3</title>\n</head>\n<body>\n");
    fprintf(queryHtml, "    <h2>Welcome to the Query Result Page ! </h2>\n");
    fclose(queryHtml); // closing file
}

void fillHTMLQuery1(int ID, struct dataBase* data){
    // ** OPENING  FILE **
    FILE * queryHtml;
    queryHtml = fopen("export/query.html", "a");

    // **  FILE BUILD **
    fprintf(queryHtml,"<div class=\"titleInfo\">Here is the first person born :</div>  <div class=\"info\">First Name : %s, Last Name : %s, Birthday : %d/%d/%d, Natal Region : %s</div>\n", getFirstName(getPersonArray(data)[ID]), getLastName(getPersonArray(data)[ID]), getDay(getPersonArray(data)[ID]), getMonth(getPersonArray(data)[ID]), getYear(getPersonArray(data)[ID]), getRegion(getPersonArray(data)[ID]));
    fclose(queryHtml);
}


void fillHTMLQuery2(int ID, struct dataBase* data){
    // ** OPENING  FILE **
    FILE * queryHtml;
    queryHtml = fopen("export/query.html", "a");

    // **  FILE BUILD **
    fprintf(queryHtml,"<div class=\"titleInfo\">Here is the last person born :</div>  <div class=\"info\">First Name : %s, Last Name : %s, Birthday : %d/%d/%d, Natal Region : %s</div>\n", getFirstName(getPersonArray(data)[ID]), getLastName(getPersonArray(data)[ID]), getDay(getPersonArray(data)[ID]), getMonth(getPersonArray(data)[ID]), getYear(getPersonArray(data)[ID]), getRegion(getPersonArray(data)[ID]));
    fclose(queryHtml);
}


void fillHTMLeQuery3(char* regionName, int numberPersonBorn){
    // ** OPENING  FILE **
    FILE * queryHtml;
    queryHtml = fopen("export/query.html", "a");

    // **  FILE BUILD **
    fprintf(queryHtml,"<div class=\"titleInfo\">Result Number people born in the Region %s :</div>  <div class=\"info\">%d</div>\n", regionName, numberPersonBorn);
    fclose(queryHtml);
}


void fillHTMLQuery4(char* regionName){
    // ** OPENING  FILE **
    FILE * queryHtml;
    queryHtml = fopen("export/query.html", "a");

    // **  FILE BUILD **
    fprintf(queryHtml,"<div class=\"titleInfo\">The Region with highest number of births is  :</div>  <div class=\"info\">%s</div>\n", regionName);
    fclose(queryHtml);
}


void fillHTMLQuery5(int day, int month, int numberPerson){
    // ** OPENING  FILE **
    FILE * queryHtml;
    queryHtml = fopen("export/query.html", "a");

    // **  FILE BUILD **
    fprintf(queryHtml,"<div class=\"titleInfo\">Result of the number of people born on %d/%d :</div>  <div class=\"info\">%d</div>\n", day, month, numberPerson);
    fclose(queryHtml);
}








