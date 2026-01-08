#include <iostream>
#include "Student.h"
using namespace std;

void Student::input() {
cout << "Enter Roll Number: ";
cin >> rollNo;
cout << "Enter Name: ";
cin.ignore();
cin.getline(name, 50);
cout << "Enter Age: ";
cin >> age;
cout << "Enter Course: ";
cin.ignore();
cin.getline(course, 30);
}

void Student::display() {
cout << "\nRoll Number: " << rollNo;
cout << "\nName: " << name;
cout << "\nAge: " << age;
cout << "\nCourse: " << course << endl;
}

int Student::getRollNo() {
return rollNo;
}
