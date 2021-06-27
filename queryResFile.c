//
// Created by micka on 27/06/2021.
//
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

#include "dataBase_reader.h"
#include "structDataBase.h"

void createQueryResFile(){ // creation of the  file
    FILE * queryFILE;
    queryFILE = fopen("queryResults.txt", "w");

    fclose(queryFILE);
}

void fillFileQuery1(int ID, struct dataBase* data){
    // ** OPENING  FILE **
    FILE * queryFILE;
    queryFILE = fopen("queryResults.txt", "a");

    // **  FILE BUILD **
                             //n°query(getFirstBornInTheTree):firstname:lastname:day:month:year:region
    fprintf(queryFILE, "1:%s:%s:%d:%d:%d:%s", getFirstName(getPersonArray(data)[ID]), getLastName(getPersonArray(data)[ID]), getDay(getPersonArray(data)[ID]), getMonth(getPersonArray(data)[ID]), getYear(getPersonArray(data)[ID]), getRegion(getPersonArray(data)[ID]));
    fclose(queryFILE);
}


void fillFileQuery2(int ID, struct dataBase* data){
    // ** OPENING  FILE **
    FILE * queryFILE;
    queryFILE = fopen("queryResults.txt", "a");

    // **  FILE BUILD **
                                //n°query(getLastBornInTheTree):firstname:lastname:day:month:year:region
    fprintf(queryFILE, "2:%s:%s:%d:%d:%d:%s", getFirstName(getPersonArray(data)[ID]), getLastName(getPersonArray(data)[ID]), getDay(getPersonArray(data)[ID]), getMonth(getPersonArray(data)[ID]), getYear(getPersonArray(data)[ID]), getRegion(getPersonArray(data)[ID]));
    fclose(queryFILE);
}


void fillFileQuery3(char* regionName, int numberPersonBorn){
    // ** OPENING  FILE **
    FILE * queryFILE;
    queryFILE = fopen("queryResults.txt", "a");

    // **  FILE BUILD **
                      //n°query(NumberPersonBornInARegion):nameRegion:numberBorn
    fprintf(queryFILE, "3:%s:%d", regionName, numberPersonBorn);
    fclose(queryFILE);

}


void fillFileQuery4(char* regionName){
    // ** OPENING  FILE **
    FILE * queryFILE;
    queryFILE = fopen("queryResults.txt", "a");

    // **  FILE BUILD **
                    //n°query(regionWithHighestNumberBirths):nameRegion
    fprintf(queryFILE, "4:%s", regionName);
    fclose(queryFILE);
}


void fillFileQuery5(int day, int month, int numberPerson){
    // ** OPENING  FILE **
    FILE * queryFILE;
    queryFILE = fopen("queryResults.txt", "a");

    // **  FILE BUILD **
                    //n°query(numberPeopleBornInDayMonthGiven):day:month:numberBorn
    fprintf(queryFILE, "5:%d:%d:%d", day, month, numberPerson);
    fclose(queryFILE);
}






