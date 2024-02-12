// main.cpp

#include <iostream>
#include <cstring>
#include "HashTable.h"

using namespace std;

int main() {
    HashTable hashTable(100); // Creating original hashtable with 100
    char choice[2]; 

    while (true) {
        cout << "Enter choice (A for ADD, P for PRINT, D for DELETE, Q for QUIT): ";
        cin >> choice;

        if (strcmp(choice, "A") == 0 || strcmp(choice, "a") == 0) {
            int studentIDValue;
            cout << "Enter student ID: ";
            cin >> studentIDValue;
            char firstName[80];
            char lastName[80];
            double GPA;
            cout << "Enter first name: ";
            cin >> firstName;
            cout << "Enter last name: ";
            cin >> lastName;
            cout << "Enter GPA: ";
            cin >> GPA;
            cin.ignore(80, '\n');
            hashTable.addStudent(studentIDValue, firstName, lastName, GPA);
        } else if (strcmp(choice, "P") == 0 || strcmp(choice, "p") == 0) {
            hashTable.printTable();
        } else if (strcmp(choice, "D") == 0 || strcmp(choice, "d") == 0) {
            int studentID;
            cout << "Enter student ID to delete: ";
            cin >> studentID;
            hashTable.deleteStudent(studentID);
        } else if (strcmp(choice, "Q") == 0 || strcmp(choice, "q") == 0) {
            break;
        } else {
            cout << "Invalid choice. Try again." << endl;
        }
    }

    return 0;
}
