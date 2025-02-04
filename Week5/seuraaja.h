#ifndef SEURAAJA_H
#define SEURAAJA_H

#include <string>
#include <iostream>

using namespace std;

class Seuraaja
{
public:
    Seuraaja();
    Seuraaja(string n);

    string getNimi();
    void paivitys(string s);

    Seuraaja* next = nullptr;

private:
    string nimi;
};

#endif // SEURAAJA_H
