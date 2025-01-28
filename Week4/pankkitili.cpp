#include "pankkitili.h"
#include <iostream>


Pankkitili::Pankkitili(string name) {
    omistaja = name;
    cout << "Pankkitili luotu kayttajalle " << omistaja << endl;
}

double Pankkitili::getBalance() {
    return saldo;
}

bool Pankkitili::deposit(double amount) {
    if(amount > 0) {
        this->saldo += amount;
        cout << "Pankkitili: talletus " << amount << " tehty" << endl;
        return true;
    }
    cout << "Pankkitili: talletus ei onnistunut!" << endl;
    return false;
}

bool Pankkitili::withdraw(double amount) {
    if(this->saldo > amount) {
        this->saldo -= amount;
        cout << "Pankkitili: nosto " << amount << " tehty" << endl;
        return true;
    }
    cout << "Pankkitili: nosto ei onnistunut!" << endl;
    return false;
}
