#include "student.h"
#include <iostream>

Student::Student(string n, int a)
{
    name = n, age = a;
}

void Student::printStudentInfo()
{
    cout << "Student " << name << " " << age << endl;
}
