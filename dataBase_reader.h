
#ifndef CODE_DATABASE_READER_H
#define CODE_DATABASE_READER_H

#include "structDataBase.h"

void createPersonHTMLFile(struct Person* child, struct Person* father, struct Person* mother, struct Person* PaternalGFather, struct Person* PaternalGMother, struct Person* MaternalGFather, struct Person* MaternalGMother);
void createHTMLOutput(struct dataBase* data, char *fileName);
// query Result File creation
void createQueryResFile();

// query Result File filling
void fillFileQuery1(int ID, struct dataBase* data);
void fillFileQuery2(int ID, struct dataBase* data);
void fillFileQuery3(char* regionName, int numberPersonBorn);
void fillFileQuery4(char* regionName);
void fillFileQuery5(int day, int month, int numberPerson);

#endif //CODE_DATABASE_READER_H
