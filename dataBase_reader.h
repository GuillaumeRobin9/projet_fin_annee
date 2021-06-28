
#ifndef CODE_DATABASE_READER_H
#define CODE_DATABASE_READER_H

#include "structDataBase.h"

void createPersonHTMLFile(struct Person* child, struct Person* father, struct Person* mother, struct Person* PaternalGFather, struct Person* PaternalGMother, struct Person* MaternalGFather, struct Person* MaternalGMother);
void createHTMLOutput(struct dataBase* data, char *fileName,int TotalPerson);

//  ** query Result File creation **
void createQueryResHTML();

// ** query Result File filling **
void fillHTMLQuery1(int ID, struct dataBase* data);
void fillHTMLQuery2(int ID, struct dataBase* data);
void fillHTMLeQuery3(char* regionName, int numberPersonBorn);
void fillHTMLQuery4(char* regionName);
void fillHTMLQuery5(int day, int month, int numberPerson);

// ** Export query results **
void createFillQueryHTMLFile(struct dataBase* data, int* numberQueries);


#endif //CODE_DATABASE_READER_H
