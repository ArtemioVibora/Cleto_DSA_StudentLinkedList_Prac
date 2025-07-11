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

void locateStudent(STUDENT *pStart, int studID) {
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
    cout << "==============================" << endl;
    cout << "<1> Add a student" << endl;
    cout << "<2> Remove a student" << endl;
    cout << "<3> Locate a student" << endl;
    cout << "<4> Print all students" << endl;
    cout << "<5> Exit" << endl;
    cout << "==============================" << endl;
    cout << "There are " << numberOfStudents << " students" << endl;
    cout << "------------------------------" << endl;
    cout << ">>>> ";
}

void runProgram() {
    STUDENT *student;
    student = NULL;

    char name[100], surname[100], address[100];

    int studentID, age, input, numberOfStudents;

    numberOfStudents = countStudents(student);

    while (input != 5) {
        numberOfStudents = countStudents(student);
        menu(numberOfStudents);
        while (!(cin >> input)) {
            cin.clear();
            cin.ignore(256, '\n');
            cout << "ERROR!" << endl;
            menu(numberOfStudents);
        }
        switch (input) {
            case 1:
                cout << "Enter Name: ";
                cin.get(name, 100);
                cin.get();
                cout << "Enter Surname: ";
                cin.get(surname, 100);
                cin.get();
                cout << "Enter Address: ";
                cin.get(address, 100);
                cin.get();
                age = agePrompt();
                studentID = studentIDPrompt();
                addNewStudent(&student, name, surname, address, age, studentID);
                break;
            case 2:
                cout << "Enter Student ID: ";
                studentID = studentIDPrompt();
                removeStudent(&student, studentID);
                break;
            case 3:
                cout << "Enter Student ID: ";
                studentID = studentIDPrompt();
                locateStudent(student, studentID);
                break;
            case 4:
                cout << "PRINT ALL STUDENTS" << endl;
                printStudents(student);
                break;
            case 5:
                break;
            default:
                break;
        }
    }
}

int main() {
    runProgram();
}