#include <iostream>

#include "..\MITARBEITER.h"

int main()
{
    MITARBEITER P1;
    DATUM Gebdat(04, 20, 1889);
    MITARBEITER P2("Otter", "Olaf", Gebdat , 0);

    std::cout << P2.NName << std::endl;
    std::cout << P2.Gebdat.str() << std::endl;

    return 0;
}