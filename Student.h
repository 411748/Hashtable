#ifndef STUDENT_H
#define STUDENT_H

#include <iostream>
#include <cstring>
//Class for building students functions
class student {
public:
    student(const char* firstName, const char* lastName, int studentID, double GPA);
    ~student();
    
    const char* getFirstName();
    const char* getLastName();
    int getStudentID();
    double getGPA();

private:
    char* firstName;
    char* lastName;
    int studentID;
    double GPA;
};

#endif
