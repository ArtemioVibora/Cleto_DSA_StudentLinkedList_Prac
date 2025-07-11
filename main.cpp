#include <iostream>
#include <malloc.h>
#include <cstring>
//Single LinkedList

using namespace std;

struct STUDENT {
    char name[100];
    char surname[100];
    char address[100];
    int age;
    int studentID;
    STUDENT *next;
};

// Student operations
bool isEmpty(STUDENT *pStart) {
    if (pStart == NULL) {
        return true;
    }
    return false;
}

int countStudents(STUDENT *pStart) {
    STUDENT *p = pStart;
    int count = 0;
    while (p != NULL) {
        ++count;
    }
    return count;
}

void locateNode(STUDENT *pStart, int studID) {
    STUDENT *p = pStart;
    int count = 1;

    if (isEmpty(p)) {
        cout << "List is empty" << endl;
    }
    else {
        while (p != NULL && p->studentID != studID) {
            p = p->next;
            ++count;
        }
        if (p == NULL) {
            cout << "Student with " << studID << " not found" << endl;
        }
        else {
            cout << "Student with " << studID << " found" << endl;

        }
    }
}

void printStudents(STUDENT *pStart) {
    STUDENT *p = pStart;

    while (p != NULL) {
        cout << p->name << endl;
        cout << p->surname << endl;
        cout << p->address << endl;
        cout << p->age << endl;
        cout << p->studentID << endl;
        p = p->next;
    }
}

void addNewStudent(STUDENT **student, char n[], char sn[], char a[], int age, int studentID) {
    STUDENT *newStudent, *ptr2;
    newStudent = (STUDENT *)malloc(sizeof(STUDENT));
    strcpy(newStudent->name, n);
    strcpy(newStudent->surname, sn);
    strcpy(newStudent->address, a);
    newStudent->age = age;
    newStudent->studentID = studentID;
    newStudent->next = NULL;
    if (*student == NULL) {
        *student = newStudent;
    }
    else {
        ptr2 = *student;
        while (ptr2->next != NULL) {
            ptr2 = ptr2->next;
        }
        ptr2->next = newStudent;
    }
}

void removeStudent(STUDENT **student, int studentID) {
    STUDENT *before, *discard;

    discard = *student;

    if (isEmpty(*student)) {
        cout << "List is empty" << endl;
    }
    else {
        if ((*student)->studentID == studentID) {
            *student = (*student)->next;
            free(discard);
            cout << "Student with " << studentID << " removed" << endl;
        }
        else {
            while (discard != NULL && discard->studentID != studentID) {
                before = discard;
                discard = discard->next;
            }
            if (discard == NULL) {
                cout << "Student with " << studentID << " not found" << endl;
            }
            else {
                before->next = discard->next;
                free(discard);
                cout << "Student with " << studentID << " removed" << endl;
            }
        }
    }


}

//Student operations end
//Filter programs

int agePrompt() {
    int age;
    cout << "Enter your age: ";
    while (!(cin >> age) || age < 3 || age > 99) {
        cin.clear();
        cin.ignore(256, '\n');
        cout << "Enter your age: ";
    }
    return age;
}

int studentIDPrompt() {
    int studentID;
    cout << "Enter your student ID: ";
    while (!(cin >> studentID) || studentID < 1) {
        cin.clear();
        cin.ignore(256, '\n');
        cout << "Enter your student ID: ";
    }
}

//Misc program

void menu(int numberOfStudents) {

}

void runProgram() {

}

int main() {

}