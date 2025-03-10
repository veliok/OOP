#include "notifikaattori.h"

Notifikaattori::Notifikaattori() {
    cout << "Luodaan notifikaattori" << endl;
}

void Notifikaattori::lisaa(Seuraaja* s) {
    cout << "Notifikaattori lisaa seuraajan " << s->getNimi() << endl;
    if(seuraajat == nullptr) {
        s->next = nullptr;
    }
    else {
        s->next = seuraajat;
    }
    seuraajat = s;
}

void Notifikaattori::poista(Seuraaja* s) {
    cout << "Notifikaattori poistaa seuraajan " << s->getNimi() << endl;
    Seuraaja* i = seuraajat;
    if(i == s) seuraajat = s->next;
    else {
        while(i != nullptr) {
            if(i->next == s) i->next = s->next;
            i = i->next;
        }
    }
}

void Notifikaattori::tulosta() {
    cout << "Notifikaattorin seuraajat:" << endl;
    Seuraaja* s = seuraajat;
    while(s!= nullptr) {
        cout << "Seuraaja: " << s->getNimi() << endl;
        s = s->next;
    }
}

void Notifikaattori::postita(string p) {
    cout << "Notifikaattori postittaa viestin " << p << endl;
    Seuraaja* s = seuraajat;
    while(s!= nullptr) {
        s->paivitys(p);
        s = s->next;
    }
}
