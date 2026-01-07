#include <iostream>
#include "Student.h"
using namespace std;

int main() {
int choice;
do {
cout << "\nStudent Record Management System\n";
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
cout << "Add Student selected\n";
break;
case 2:
cout << "View Students selected\n";
break;
case 3:
cout << "Search Student selected\n";
break;
case 4:
cout << "Modify Student selected\n";
break;
case 5:
cout << "Delete Student selected\n";
break;
case 6:
cout << "Exiting program...\n";
break;
default:
cout << "Invalid choice. Try again.\n";
}} while (choice != 6);
 return 0;
}
