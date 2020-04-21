#include <iostream>
#include "../GUI.h"

int main()
{
    // Test Mitarbeiter
    DATUM d1(27, 03, 1969);
    MITARBEITER m1("Otter", "Dori", d1, 0);
    DATUM d2(27, 03, 1970);
    MITARBEITER m2("Meier", "Alfred", d2, 5);
    DATUM d3(27, 03, 1971);
    MITARBEITER m3("PIMMEl", "Vaginer", d3, 0);
    DATUM d4(27, 03, 1971);
    MITARBEITER m4("horst", "Vaginer", d4, 0);
    DATUM d5(27, 03, 1902);
    MITARBEITER m5("horst", "wendl", d5, 35);
    
    GUI Interface;

    Interface.Firma.Register[0] = m1;
    Interface.Firma.Register[3] = m2;
    Interface.Firma.Register[4] = m3;
    Interface.Firma.Register[15] = m4;
    Interface.Firma.Register[19] = m5;
    

    Interface.main();

    return 0; 
}
