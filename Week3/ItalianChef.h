#ifndef ITALIANCHEF_H
#define ITALIANCHEF_H

#include "Chef.h"

class ItalianChef : public Chef {
public:
    ItalianChef();
    ItalianChef(string name);
    ~ItalianChef();

    bool askSecret(string pass, int flour, int water);

private:
    string password = "pizza";
    int flour;
    int water;

    int makePizza();
};



ItalianChef::ItalianChef() {}

ItalianChef::ItalianChef(string name)
    : Chef(name)
{
    chefName = name;
    cout << "ItalianChef " << name << " constructor" << endl;
}

ItalianChef::~ItalianChef() {
    cout << "ItalianChef " << chefName << " destructor" << endl;
}


bool ItalianChef::askSecret(string pass, int flour, int water) {
    if(pass.compare(password) == 0) {
        cout << "Password OK!" << endl;
        this->flour = flour;
        this->water = water;
        makePizza();
        return true;
    }
    else {
        cout << "Password False!" << endl;
        return false;
    }
}

int ItalianChef::makePizza() {
    int portions = min(flour,water) / 5;
    cout << "ItalianChef " << this->getName() << " with " << this->flour << " flour and " <<
        this->water << " water can make " << portions << " pizzas" << endl;
    return portions;
};

#endif // ITALIANCHEF_H
