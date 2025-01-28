#include "luottotili.h"
#include <iostream>


Luottotili::Luottotili(string name, double limit)
    :Pankkitili(name)
{
    omistaja = name;
    luottoRaja = limit;
    this->saldo = limit;
    cout << "Luottotili luotu kayttajalle " << omistaja <<
        ", luottoraja " << luottoRaja << endl;
}

bool Luottotili::deposit(double amount) {
    if(amount > 0 && (this->saldo + amount) < luottoRaja) {
        this->saldo += amount;
        cout << "Luottotili: talletus " << amount << " tehty" << endl;
        return true;
    }
    cout << "Luottotili: talletus ei onnistunut!" << endl;
    return false;
}

bool Luottotili::withdraw(double amount) {
    if((this->saldo - amount) > 0) {
        this->saldo -= amount;
        cout << "Luottotili: nosto " << amount <<
            " tehty, luottoa jaljella " << this->saldo << endl;
        return true;
    }
    cout << "Luottotili: nosto ei onnistunut!" << endl;
    return false;
}
