//
// Created by micka on 26/06/2021.
//

#ifndef CODE_DATABASE_READER_H
#define CODE_DATABASE_READER_H

#include "structDataBase.h"

void getAncestorsID(int IDchild, struct dataBase* data, int* IDfather, int* IDmother, int* IDPaternalGFather,int* IDPaternalGMother,int* IDMaternalGFather,int* IDMaternalGMother);

#endif //CODE_DATABASE_READER_H
