#include "asiakas.h"
#include <iostream>


Asiakas::Asiakas(string name, double limit)
    : luottotili(name, limit)
{
    nimi = name;
    cout << "Asiakkuus luotu " << nimi << endl;
}

string Asiakas::getNimi() {
    return nimi;
}

void Asiakas::showSaldo() {
    cout << "Kayttotilin saldo " <<  kayttotili.getBalance() << endl;
    cout << "Luottotilin saldo " << luottotili.getBalance() << endl;
}

bool Asiakas::talletus(double maara) {
    kayttotili.deposit(maara);
    return true;
}

bool Asiakas::nosto(double maara) {
    kayttotili.withdraw(maara);
    return true;
}

bool Asiakas::luotonMaksu(double maara) {
    luottotili.deposit(maara);
    return true;
}

bool Asiakas::luotonNosto(double maara) {
    luottotili.withdraw(maara);
    return true;
}

bool Asiakas::tiliSiirto(double maara, Asiakas& asiakas) {
    if(kayttotili.getBalance() > maara) {
        cout << "Pankkitili: " << nimi << " siirtaa " <<
            maara << " kayttajalle " << asiakas.getNimi() << endl;
        cout << this->getNimi() << " ";
        this->nosto(maara);
        cout << asiakas.getNimi() << " ";
        asiakas.talletus(maara);
        return true;
    }
    return false;
}
