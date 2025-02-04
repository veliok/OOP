#include "seuraaja.h"

Seuraaja::Seuraaja() {}

Seuraaja::Seuraaja(string n) {
    nimi = n;
    cout << "Luodaan seuraaja " << nimi << endl;
}

string Seuraaja::getNimi() {
    return nimi;
}

void Seuraaja::paivitys(string s) {
    cout << "Seuraaja " << nimi << " sai viestin " << s << endl;
}
