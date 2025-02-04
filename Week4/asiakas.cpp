#include "asiakas.h"
#include <iostream>


Asiakas::Asiakas(string name, double limit)
    : kayttotili(name), luottotili(name, limit)
{
    nimi = name;
    cout << "Asiakkuus luotu " << nimi << endl;
}

string Asiakas::getNimi() {
    return nimi;
}

void Asiakas::showSaldo() {
    cout << "Kayttotilin saldo " << kayttotili.getBalance() << endl;
    cout << "Luottotilin saldo " << luottotili.getBalance() << endl;
}

bool Asiakas::talletus(double maara) {
    if(kayttotili.deposit(maara)) {
        return true;
    }
    return false;
}

bool Asiakas::nosto(double maara) {
    if(kayttotili.withdraw(maara)) {
       return true;
    }
    return false;
}

bool Asiakas::luotonMaksu(double maara) {
    if(luottotili.deposit(maara)) {
        return true;
    }
    return false;
}

bool Asiakas::luotonNosto(double maara) {
    if(luottotili.withdraw(maara)) {
        return true;
    }
    return false;
}

bool Asiakas::tiliSiirto(double maara, Asiakas& asiakas) {
    if(kayttotili.getBalance() > maara) {
        cout << "Pankkitili: " << nimi << " siirtaa " <<
            maara << " kayttajalle " << asiakas.getNimi() << endl;

        cout << getNimi() << " ";
        nosto(maara);
        cout << asiakas.getNimi() << " ";
        asiakas.talletus(maara);
        return true;
    }
    cout << "Tilisiirto epäonnistui!" << endl;
    return false;
}
