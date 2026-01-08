#include <iostream>
#include <fstream>
#include <cstdio>
#include "Student.h"

using namespace std;

void addStudent() {
    Student s, temp;
    int roll;
    bool exists = false;

    cout << "Enter Roll Number: ";
    cin >> roll;

    ifstream inFile("students.dat", ios::binary);
    while (inFile.read((char*)&temp, sizeof(temp))) {
        if (temp.getRollNo() == roll) {
            exists = true;
            break;
        }
    }
    inFile.close();

    if (exists) {
        cout << "Error: Roll number already exists.\n";
        return;
    }

    s.setRollNo(roll);   //  roll set ONLY ONCE
    s.input();           // input now excludes roll number

    ofstream outFile("students.dat", ios::binary | ios::app);
    outFile.write((char*)&s, sizeof(s));
    outFile.close();

    cout << "Student record added successfully.\n";
}


void viewStudents() {
    Student s;
    ifstream file("students.dat", ios::binary);

    if (!file) {
        cout << "No records found.\n";
        return;
    }

    cout << "\n--- Student Records ---\n";

    while (file.read((char*)&s, sizeof(s))) {
        s.display();
        cout << "\n----------------------\n";
    }

    file.close();
}

void searchStudent() {
    int roll;
    bool found = false;
    Student s;

    cout << "Enter Roll Number to search: ";
    cin >> roll;

    ifstream file("students.dat", ios::binary);

    if (!file) {
        cout << "No records found.\n";
        return;
    }

    while (file.read((char*)&s, sizeof(s))) {
        if (s.getRollNo() == roll) {
            cout << "\nStudent Found:\n";
            s.display();
            found = true;
            break;
        }
    }

    file.close();

    if (!found) {
        cout << "Student not found.\n";
    }
}

void modifyStudent() {
    int roll;
    bool found = false;
    Student s;

    cout << "Enter Roll Number to modify: ";
    cin >> roll;

    fstream file("students.dat", ios::binary | ios::in | ios::out);

    if (!file) {
        cout << "No records found.\n";
        return;
    }

    while (file.read((char*)&s, sizeof(s))) {
        if (s.getRollNo() == roll) {
            cout << "\nExisting Record:\n";
            s.display();

            cout << "\nEnter new details:\n";
            s.input();

            file.seekp(-sizeof(s), ios::cur);
            file.write((char*)&s, sizeof(s));

            cout << "Student record updated successfully.\n";
            found = true;
            break;
        }
    }

    file.close();

    if (!found) {
        cout << "Student not found.\n";
    }
}

void deleteStudent() {
    int roll;
    bool found = false;
    Student s;

    cout << "Enter Roll Number to delete: ";
    cin >> roll;

    ifstream inFile("students.dat", ios::binary);
    ofstream outFile("temp.dat", ios::binary);

    if (!inFile || !outFile) {
        cout << "Error opening file.\n";
        return;
    }

    while (inFile.read((char*)&s, sizeof(s))) {
        if (s.getRollNo() == roll) {
            found = true;
            continue;   // skip this record
        }
        outFile.write((char*)&s, sizeof(s));
    }

    inFile.close();
    outFile.close();

    remove("students.dat");
    rename("temp.dat", "students.dat");

    if (found) {
        cout << "Student record deleted successfully.\n";
    } else {
        cout << "Student not found.\n";
    }
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
            case 2:
                viewStudents();
                break;
            case 3:
                searchStudent();
                break;
            case 4:
                modifyStudent();
                break;
            case 5:
                deleteStudent();
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
