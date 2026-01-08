#include <iostream>
#include <fstream>
#include "Student.h"

using namespace std;

void addStudent() {
    Student s;
    fstream file("students.dat", ios::binary | ios::in | ios::out | ios::app);

    if (!file) {
        cout << "Error opening file.\n";
        return;
    }

    s.input();
    file.write((char*)&s, sizeof(s));
    file.close();

    cout << "Student record added successfully.\n";
}

int main() {
    int choice;

    do {
        cout << "\n--- Student Record Management System ---\n";
        cout << "1. Add Student\n";
        cout << "2. View Students\n";
        cout << "3. Search Student\n";
        cout << "4. Modify Student\n";
        cout << "5. Delete Student\n";
        cout << "6. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                addStudent();
                break;
            case 6:
                cout << "Exiting program...\n";
                break;
            default:
                cout << "Option not implemented yet.\n";
        }

    } while (choice != 6);

    return 0;
}
