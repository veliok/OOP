#include "luottotili.h"
#include <iostream>


Luottotili::Luottotili(string name, double limit)
{
    omistaja = name;
    luottoRaja = limit;
    saldo = limit;
    cout << "Luottotili luotu kayttajalle " << omistaja <<
        ", luottoraja " << luottoRaja << endl;
}

bool Luottotili::deposit(double amount) {
    if(amount > 0 && (saldo + amount) < luottoRaja) {
        saldo += amount;
        cout << "Luottotili: talletus " << amount << " tehty" << endl;
        return true;
    }
    cout << "Luottotili: talletus ei onnistunut!" << endl;
    return false;
}

bool Luottotili::withdraw(double amount) {
    if((saldo - amount) > 0) {
        saldo -= amount;
        cout << "Luottotili: nosto " << amount <<
            " tehty, luottoa jaljella " << saldo << endl;
        return true;
    }
    cout << "Luottotili: nosto ei onnistunut!" << endl;
    return false;
}
