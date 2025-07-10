#include <iostream>
#include <malloc.h>
#include <cstring>
//Single LinkedList

struct STUDENT {
    char name[100];
    char surname[100];
    char address[100];
    int age;
    int studentID;
    STUDENT *next;
};

void addNewStudent(STUDENT **student, char n[], char sn[], char a[], int age, int studentID) {
    STUDENT *newStudent, *ptr2;
    newStudent = (STUDENT *)malloc(sizeof(STUDENT));
    strcpy(newStudent->name, n);
    strcpy(newStudent->surname, sn);
    strcpy(newStudent->address, a);
    newStudent->age = age;
    newStudent->studentID = studentID;
}

int main() {

}