#include "ItalianChef.h"

int main()
{
    Chef chef("Gordon");
    chef.makeSalad(11);
    chef.makeSoup(14);

    ItalianChef chef2("Mario");
    chef2.makeSalad(9);
    chef2.askSecret("pizza", 12, 12);

    return 0;
}
