#include <iostream>
#include "..\MITARBEITERREGISTER.h"

int main ()
{
    MITARBEITERREGISTER Firma;
    DATUM Gebdat(27, 03, 1900);
    MITARBEITER Dori("Otter", "Dori", Gebdat, 0);
    MITARBEITER Alfred("Meier", "Alfred", Gebdat, 5);
    MITARBEITER Andre ("PIMMEl", "Vaginer", Gebdat, 0);

    Firma.MB_hinzufuegen(Dori);
    for (int i = 0; i < 50; i++)
    {
        Firma.MB_hinzufuegen(Andre);
    }
    
    Firma.MB_hinzufuegen(Alfred);
    std::cout << "Mitarbeiteranzahl: " << Firma.MBs_anzahl() << std::endl << std::endl;

    std::cout << Firma.MBs_stringliste() << std::endl;

    std::cout << "Nach Hinzufuegen von Urlaub:" << std::endl;
    Firma.MB_Urlaubanlegen(Firma.MB_suchen("Dori", "Otter"), 10);

    std::cout << Firma.MBs_stringliste() << std::endl;

    //Firma.MB_loeschen(Firma.MB_suchen("Dori", "Otter"));
    //std::cout << "Nach loeschen:" << std::endl << Firma.MBs_stringliste() << std::endl;

    std::cout << "Nach hinzufuegen von neuem Mitarbeiter:" << std::endl;
    Firma.MB_hinzufuegen(Andre);
    std::cout << Firma.MBs_stringliste() << std::endl;


    std::cout << Firma.MB_suchen("Dori", "Oter") << std::endl;
    std::cout << Firma.MB_suchen("Doi", "Otter") << std::endl;

    return 0;
}