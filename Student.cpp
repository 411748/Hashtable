#include "Student.h"

//Building student
student::student(const char* firstName, const char* lastName, int studentID, double GPA) {
    this->firstName = new char[strlen(firstName) + 1];
    strcpy(this->firstName, firstName);

    this->lastName = new char[strlen(lastName) + 1];
    strcpy(this->lastName, lastName);

    this->studentID = studentID;
    this->GPA = GPA;
}
//Deleting student
student::~student() {
    delete[] firstName;
    delete[] lastName;
}
//Functions to build student
const char* student::getFirstName() {
    return firstName;
}

const char* student::getLastName() {
    return lastName;
}

int student::getStudentID() {
    return studentID;
}

double student::getGPA() {
    return GPA;
}
