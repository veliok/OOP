#include <string>

using namespace std;

class Student {
public:
    Student(string n, int a);

    void setAge(int);
    void setName(string);
    string getName() { return name; }
    int getAge() { return age; }
    void printStudentInfo();

private:
    string name;
    int age;
};
