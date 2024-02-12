// main.cpp

// Nick Braun
// 2/12/2024
// HashTable - Similar to student list, but it hashes information. After 3 collisions, it will rehash. It also can read in from text files to generate random students.

// https://cplusplus.com/forum/beginner/151894/
// https://cplusplus.com/forum/beginner/262127/
// https://www.codecademy.com/resources/docs/cpp/random
// https://cplusplus.com/reference/string/string/substr/


// Adding all includes
#include "HashTable.h"
#include <iostream>
#include <fstream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <cstring>

using namespace std;

// Pulling names from text files
const char* FIRST_NAMES_FILE = "First_names.txt";
const char* LAST_NAMES_FILE = "Last_names.txt";

// Opening names and assining them for use
vector<string> readNamesFromFile(const char* filename) {
    vector<string> names;
    ifstream file(filename);
    if (file.is_open()) {
        string name;
        while (getline(file, name)) {
            names.push_back(name);
        }
        file.close();
    }
    return names;
}

//Creating a random 5 digit student ID 
int generateStudentID() {
    return rand() % 90000 + 10000; 
}

//Creating a random gpa
double generateGPA() {
    return static_cast<double>(rand() % 401) / 100;
}

//Creating the random students name from the text files
string generateStudentName(const vector<string>& firstNames, const vector<string>& lastNames) {
    string firstName = firstNames[rand() % firstNames.size()];
    string lastName = lastNames[rand() % lastNames.size()];
    return firstName + " " + lastName;
}

//Function to create a random amount of students
void generateRandomStudents(HashTable& hashTable, const vector<string>& firstNames, const vector<string>& lastNames, int numStudents) {
    srand(time(nullptr)); // Seed the random number generator
    for (int i = 0; i < numStudents; ++i) {
        int studentID = generateStudentID();
        string fullName = generateStudentName(firstNames, lastNames);
        double GPA = generateGPA();
	char* firstName = new char[50];
	strcpy(firstName, fullName.substr(0, fullName.find(' ')).c_str());
        const char* lastName = fullName.substr(fullName.find(' ') + 1).c_str();
        hashTable.addStudent(studentID, firstName, lastName, GPA);
    }
}

//Main function
int main() {
    vector<string> firstNames = readNamesFromFile(FIRST_NAMES_FILE);
    vector<string> lastNames = readNamesFromFile(LAST_NAMES_FILE);

    // Creating original hashtable
    HashTable hashTable(100);

    char choice[80];

    while (true) {
        // Getting the users choice
        cout << "Enter choice (A for ADD, P for PRINT, D for DELETE, R for ADD RANDOM STUDENTS, Q for QUIT): ";
        cin >> choice;
	// Adding student to hashtable
        if (strcmp(choice, "A") == 0) {
            int studentID;
            cout << "Enter student ID: ";
            cin >> studentID;
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
            hashTable.addStudent(studentID, firstName, lastName, GPA);
        } else if (strcmp(choice, "P") == 0) { //Print hashtable
            hashTable.printTable();
        } else if (strcmp(choice, "D") == 0) { //Delete student in hashtable
            int studentID;
            cout << "Enter student ID to delete: ";
            cin >> studentID;
            hashTable.deleteStudent(studentID);
        } else if (strcmp(choice, "R") == 0) { //Generate a random amount of students
            int numStudents;
            cout << "Enter number of random students to add: ";
            cin >> numStudents;
            generateRandomStudents(hashTable, firstNames, lastNames, numStudents);
        } else if (strcmp(choice, "Q") == 0) { //Quit
            break;
        } else {
            cout << "Invalid choice. Try again." << endl;
        }
    }

    return 0;
}
