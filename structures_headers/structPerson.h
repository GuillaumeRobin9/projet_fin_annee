
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

//** Creation Function **
struct Person* createEmptyPerson(int ID, int IDf, int IDm, char* lastN, char* firstN, int day, int month, int year, char* region);


//** Declarations of Access Functions **

int getID(struct Person* p);
int getFatherID(struct Person* p);
int getMotherID(struct Person *p);
char* getLastName(struct Person *p);
char* getFirstName(struct Person *p);
int getDay(struct Person* p);
int getMonth(struct Person* p);
int getYear(struct Person* p);
char* getRegion(struct Person* p);

#endif //CODE_STRUCTPERSON_H
