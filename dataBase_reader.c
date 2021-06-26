//
// Created by micka on 26/06/2021.
//
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

#include "dataBase_reader.h"

void getAncestorsID(int IDchild, struct dataBase* data, int* IDfather, int* IDmother, int* IDPaternalGFather,int* IDPaternalGMother,int* IDMaternalGFather,int* IDMaternalGMother){

//    getting the IDs of the child's Ancestors
    *IDfather = getFatherID(getPersonArray(data)[IDchild]);
    *IDmother = getMotherID(getPersonArray(data)[IDchild]);

//    father's parents
    *IDPaternalGFather = getFatherID(getPersonArray(data)[*IDfather]);
    *IDPaternalGMother = getMotherID(getPersonArray(data)[*IDfather]);

//    mother's parents
    *IDMaternalGFather = getFatherID(getPersonArray(data)[*IDmother]);
    *IDMaternalGMother = getMotherID(getPersonArray(data)[*IDmother]);
}
