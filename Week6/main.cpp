#include <algorithm>
#include <vector>
#include <iostream>
#include "student.h"

using namespace std;

int main ()
{
    int selection =0;
    int age;
    string name;
    vector<Student*>studentList;
    vector<Student*>::iterator it = studentList.begin();
    Student *s = nullptr;

    do
    {
        cout << endl;
        cout << "Select"<< endl;
        cout << "Add students = 0" << endl;
        cout << "Print all students = 1" << endl;
        cout << "Sort and print students according to Name = 2" << endl;
        cout << "Sort and print students according to Age = 3" << endl;
        cout << "Find and print student = 4" << endl;
        cin >> selection;

        switch(selection)
        {
            case 0:
                cout << "Student name ?" << endl;
                cin >> name;
                cout << "Student age ?" << endl;
                cin >> age;
                s = new Student(name, age);
                studentList.push_back(s);
                break;

            case 1:
                for (Student *s : studentList) {
                    cout << "Student " << s->getName() << " " << s->getAge() <<endl;
                }
                break;

            case 2:
                sort(studentList.begin(), studentList.end(), [] (Student *a, Student *b) {
                    return a->getName() < b->getName();
                });
                for(Student *s : studentList) {
                    s->printStudentInfo();
                }
                break;

            case 3:
                sort(studentList.begin(), studentList.end(), [] (Student *a, Student *b) {
                    return a->getAge() < b->getAge();
                });
                for(Student *s : studentList) {
                    s->printStudentInfo();
                }
                break;

            case 4:
                cout << "Student to be found = ?" << endl;
                cin >> name;

                it = find_if(studentList.begin(), studentList.end(), [name] (Student *s) {
                    return s->getName() == name;
                });

                if(it != studentList.end()) {
                    cout << "Student found: " << endl;
                    studentList[it-studentList.begin()]->printStudentInfo();
                }
                else {
                    cout << "Student not found" << endl;
                }
                break;

            default:
                cout<< "Wrong selection, stopping..."<< endl;
                break;
        }
    }while(selection < 5);

    for(Student *s : studentList) delete s;

    return 0;
}
