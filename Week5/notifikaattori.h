#ifndef NOTIFIKAATTORI_H
#define NOTIFIKAATTORI_H

#include "seuraaja.h"

class Notifikaattori
{
public:
    Notifikaattori();

    void lisaa(Seuraaja* s);
    void poista(Seuraaja* s);
    void tulosta();
    void postita(string p);
private:
    Seuraaja* seuraajat = nullptr;

};

#endif // NOTIFIKAATTORI_H
