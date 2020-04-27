#include <iostream>

#include "..\MITARBEITER.h"

int main()
{
    // Konstruktor
    MITARBEITER P1;
    std::cout << "Mitarbeiter P1()" << std::endl;
    std::cout << P1.str() << std::endl;

    DATUM Gebdat(04, 20, 1989);
    MITARBEITER P2("Otter", "Olaf", Gebdat , 5);
    std::cout << "Mitarbeiter MB1(\"Olaf\", \"Otter\", 04.20.1989, 5):" << std::endl;
    std::cout << P2.str() << std::endl;
    
    // Urlaub 
    std::cout << "P1.Urlaubstage = " << P1.Urlaubstage << std::endl;
    std::cout << "P2.Urlaubstage = " << P2.Urlaubstage << std::endl;

    std::cout << "P1.restUrlaub() = " << P1.restUrlaub() << std::endl;
    std::cout << "P2.restUrlaub() = " << P2.restUrlaub() << std::endl;

    // Geburtsdatum

    DATUM d1(27, 03, 1969);
    MITARBEITER m1("Otter", "Dori", d1, 0);
    DATUM d2(27, 03, 1970);
    MITARBEITER m2("Meier", "Alfred", d2, 5);
    
    std::cout << "m1(27.03.1969) + m2(27.03.1970)" << std::endl;
    std::cout << "m1.Gebdat.str() = " << m1.Gebdat.str() << std::endl;
    std::cout << "m2.Gebdat.str() = " << m2.Gebdat.str() << std::endl;
    
    return 0;
}