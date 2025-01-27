#ifndef PANKKITILI_H
#define PANKKITILI_H

#include <string>

using namespace std;

class Pankkitili {
public:
    Pankkitili() {}
    Pankkitili(string name);
    ~Pankkitili() {}

    double getBalance();
    virtual bool deposit(double amount);
    virtual bool withdraw(double amount);

protected:
    string omistaja;
    double saldo = 0;
};

#endif // PANKKITILI_H
