#include <iostream>
#include <malloc.h>
//Single LinkedList

struct STUDENT {
    char name[100];
    char surname[100];
    int age;
    int studentID;
    STUDENT *next;
};