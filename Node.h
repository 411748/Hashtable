// Node.h

#ifndef NODE_H
#define NODE_H

#include <cstring>

struct Student {
    int studentID;
    char firstName[80];
    char lastName[80];
    double GPA;

    // Constructor
    Student(int id, const char* fName, const char* lName, double gpa) : studentID(id), GPA(gpa) {
        std::strcpy(firstName, fName);
        std::strcpy(lastName, lName);
    }
};

class Node {
public:
    Node(Student* newStudent);
    ~Node();

    Student* getStudent() const;
    Node* getNext() const;
    void setNext(Node* newNext);

private:
    Student* currentStudent;
    Node* next;
};

#endif // NODE_H

