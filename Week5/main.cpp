#include "notifikaattori.h"

using namespace std;

int main()
{
    Notifikaattori n;

    Seuraaja a("A");
    Seuraaja b("B");
    Seuraaja c("C");
    Seuraaja d("D");

    n.lisaa(&a);
    n.lisaa(&b);
    n.lisaa(&c);
    n.lisaa(&d);
    n.tulosta();

    n.postita("Tama on viesti 1");

    n.poista(&b);

    n.postita("Tama on viesti 2");

    return 0;
}
