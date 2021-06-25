//
// Created by micka on 25/06/2021.
//

#ifndef CODE_STRUCTPERSON_H
#define CODE_STRUCTPERSON_H

struct Person {
    int ID;
    int IDfather;
    int IDmother;
//    int children[];
    char* lastName;
    char* firstName;
    int day;
    int month;
    int year;
    char* region;
}

#endif //CODE_STRUCTPERSON_H
