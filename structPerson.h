
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
};

//** Creation Function **
struct Person* createPerson(int ID, int IDf, int IDm, char* lastN, char* firstN, int day, int month, int year, char* region);
struct Person* createEmptyPerson();


//** Declarations of Access Functions **

void printPerson(struct Person* p);
int getID(struct Person* p);
int getFatherID(struct Person* p);
int getMotherID(struct Person *p);
char* getLastName(struct Person *p);
char* getFirstName(struct Person *p);
int getDay(struct Person* p);
int getMonth(struct Person* p);
int getYear(struct Person* p);
char* getRegion(struct Person* p);

//** Suppression Function **
void deletePerson(struct Person* p);

#endif //CODE_STRUCTPERSON_H
