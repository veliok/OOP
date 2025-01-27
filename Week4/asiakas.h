#ifndef ASIAKAS_H
#define ASIAKAS_H

#include "pankkitili.h"
#include "luottotili.h"

class Asiakas {
public:
    Asiakas(string name, double limit);
    ~Asiakas() {}

    string getNimi();
    void showSaldo();
    bool talletus(double maara);
    bool nosto(double maara);
    bool luotonMaksu(double maara);
    bool luotonNosto(double maara);
    bool tiliSiirto(double maara, Asiakas&);

private:
    string nimi;
    Pankkitili kayttotili;
    Luottotili luottotili;
};

#endif // ASIAKAS_H
