// Node.cpp

#include "Node.h"

Node::Node(Student* newStudent) : currentStudent(newStudent), next(nullptr) {}

Node::~Node() {
    delete currentStudent;
}

Student* Node::getStudent() const {
    return currentStudent;
}

Node* Node::getNext() const {
    return next;
}

void Node::setNext(Node* newNext) {
    next = newNext;
}
