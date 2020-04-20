#include <iostream>

#include "..\MITARBEITER.h"

int main()
{
    // Konstruktor
    MITARBEITER P1;
    DATUM Gebdat(04, 20, 1989);
    MITARBEITER P2("Otter", "Olaf", Gebdat , 5);

    std::cout << P2.NName << std::endl;
    std::cout << P2.Gebdat.str() << std::endl << std::endl;
    
    // str() und reset()
    // P2.reset();
    // std::cout << P2.str() << std::endl << std::endl; 

    // restUrlaub und Urlaub_add
    std::cout << P1.restUrlaub() << std::endl;
    std::cout << P2.restUrlaub() << std::endl;
    
    return 0;
}