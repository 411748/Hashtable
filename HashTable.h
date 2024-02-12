// HashTable.h

#ifndef HASHTABLE_H
#define HASHTABLE_H

#include "Node.h"

class HashTable {
public:
    HashTable(int initialCapacity);
    ~HashTable();

    void addStudent(int studentID, const char* firstName, const char* lastName, double GPA);
    void deleteStudent(int studentID);
    void printTable() const;

private:
    Node** table;
    int capacity;

    int hashFunction(int key) const;
    void resize(int newCapacity);
};

#endif // HASHTABLE_H
