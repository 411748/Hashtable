#include <iostream>
#include <cstring>
#include "Node.h"

using namespace std;

node::node(student* studenttmp) : currentStudent(studenttmp) {
    nextNode = nullptr;
}

node::~node() {
    delete currentStudent;
}

node* node::getNext() {
    return nextNode;
}

student* node::getStudent() {
    return currentStudent;
}

void node::setNext(node* newNode) {
    nextNode = newNode;
}
