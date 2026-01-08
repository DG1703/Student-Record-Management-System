#ifndef STUDENT_H
#define STUDENT_H

class Student {
private:
int rollNo;
char name[50];
int age;
char course[30];
public:
void input();
void display();
int getRollNo();
void setRollNo(int r);
};

#endif
