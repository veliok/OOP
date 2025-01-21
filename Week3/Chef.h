#ifndef CHEF_H
#define CHEF_H

#include <string>
#include <iostream>

using namespace std;

class Chef {
public:
    Chef();
    Chef(string name);
    ~Chef();

    string getName();
    int makeSalad(int ingredients);
    int makeSoup(int ingredients);

protected:
    string chefName;
};


Chef::Chef(){}

Chef::Chef(string name) {
    chefName = name;
    cout << "Chef " << name << " constructor" << endl;
}

Chef::~Chef() {
    cout << "Chef " << chefName << " destructor" << endl;
}

string Chef::getName(){
    return chefName;
}

int Chef::makeSalad(int ingredients) {
    int portions = (ingredients / 5);
    cout << "Chef " << this->getName() << " with " << ingredients << " items can make " <<
        portions << " portions of salad" << endl;
    return portions;
}

int Chef::makeSoup(int ingredients) {
    int portions = (ingredients / 3);
    cout << "Chef " << this->getName() << " with " << ingredients << " items can make " <<
        portions << " portions of soup" << endl;
    return portions;
};
#endif // CHEF_H
