#ifndef LUOTTOTILI_H
#define LUOTTOTILI_H

#include "pankkitili.h"

class Luottotili : public Pankkitili {
public:
    Luottotili(string name, double limit);
    ~Luottotili() {}

    virtual bool deposit(double amount) override;
    virtual bool withdraw(double amount) override;
protected:
    double luottoRaja = 0;
};

#endif // LUOTTOTILI_H
