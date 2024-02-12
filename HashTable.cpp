// HashTable.cpp

//includes
#include "HashTable.h"
#include <iostream>
#include <cstring>

using namespace std;

//Constructor
HashTable::HashTable(int initialCapacity) : capacity(initialCapacity) {
    table = new Node*[capacity]();
}

//Deconstructor
HashTable::~HashTable() {
    for (int i = 0; i < capacity; ++i) {
        Node* current = table[i];
        while (current != nullptr) {
            Node* next = current->getNext();
            delete current;
            current = next;
        }
    }
    delete[] table;
}

//Function to add student to hashtable
void HashTable::addStudent(int studentID, const char* firstName, const char* lastName, double GPA) {
    int index = hashFunction(studentID);
    Node* newNode = new Node(new Student(studentID, firstName, lastName, GPA));

    if (table[index] == nullptr) {
        table[index] = newNode;
    } else {
        Node* current = table[index];
        while (current->getNext() != nullptr) {
            current = current->getNext();
        }
        current->setNext(newNode);
    }
}

//Function to delete student from hashtable
void HashTable::deleteStudent(int studentID) {
    int index = hashFunction(studentID);
    Node* current = table[index];
    Node* prev = nullptr;

    while (current != nullptr && current->getStudent()->studentID != studentID) {
        prev = current;
        current = current->getNext();
    }

    if (current == nullptr) {
        std::cout << "Student with ID " << studentID << " not found." << std::endl;
        return;
    }

    if (prev == nullptr) {
        table[index] = current->getNext();
    } else {
        prev->setNext(current->getNext());
    }

    delete current;
}

void HashTable::printTable() const {
    for (int i = 0; i < capacity; ++i) {
        Node* current = table[i];
        while (current != nullptr) {
            std::cout << "Student ID: " << current->getStudent()->studentID << ", ";
            std::cout << "Name: " << current->getStudent()->firstName << " " << current->getStudent()->lastName << ", ";
            std::cout << "GPA: " << current->getStudent()->GPA << std::endl;
            current = current->getNext();
        }
    }
}

//Function to hash 
int HashTable::hashFunction(int key) const {
    return key % capacity;
}

//Function to resize after 3 collisions
void HashTable::resize(int newCapacity) {
    Node** newTable = new Node*[newCapacity]();
    
    for (int i = 0; i < capacity; ++i) {
        Node* current = table[i];
        while (current != nullptr) {
            Node* next = current->getNext();
            int newIndex = hashFunction(current->getStudent()->studentID) % newCapacity;
            current->setNext(newTable[newIndex]);
            newTable[newIndex] = current;
            current = next;
        }
    }
    
    delete[] table;
    table = newTable;
    capacity = newCapacity;
}
