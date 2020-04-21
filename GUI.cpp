#include <iostream>
#include "GUI.h"

void GUI::main()
{
    int Benut;

    do
    {
        Benutzermenue();
        std::cin >> Benut; 

        switch(Benut)
        {
            case 1:
                MB_anlegen();
                break;
            
            case 2:
                MB_suche();
                break;

            case 3:
                UrlaubAnlegen();
                break;

            case 4:
                MB_Loeschen();
                break;

            case 5:
                MB_ListeAnzeigen();
                break;
            
            case 0:
                 std::cout << "Programm beendet!\n";
                 break;

            default:
                std::cout << "Das eingegebene Kommando ist nicht vorhanden : Bitte geben sie ein neues an\n";
                break;
        }
    }while(Benut!=0);
}

void GUI::Benutzermenue()
{
    std::cout << "Benutzermenue:" << std::endl;
    std::cout << "Um einen Mitarbeiter anzulegen: \t\t1" << std::endl;
    std::cout << "Um einen Mitarbeiter zu suchen: \t\t2" << std::endl;
    std::cout << "Um Urlaub fuer einen Mitarbeiter anzulegen: \t3" << std::endl;
    std::cout << "Um einen Mitarbeiter zu loeschen: \t\t4" << std::endl;
    std::cout << "Um die gesamte Mitarbeiterliste anzuzeigen: \t5" << std::endl;
    std::cout << "Um das Programm zu beenden:\t\t\t0" << std::endl;
}

void GUI::MB_anlegen()
{
    std::string vn, nn;
    int tg, mg, jg, ut;

    std::cout << "Geben sie den Vornamen ein:" << std::endl;
    std::cin >> vn;
    std::cout << "Geben sie den Nachnamen ein:" << std::endl;
    std::cin >> nn;
    std::cout << "Geben sie den Tag Geburtsdatums ein:" << std::endl;
    std::cin >> tg;
    std::cout << "Geben sie den Monat des Geburtsdatums ein:" << std::endl;
    std::cin >> mg;
    std::cout << "Geben sie das Jahr Geburtsdatums ein:" << std::endl;
    std::cin >> jg;
    std::cout << "Geben sie die bereits in anspruch genommenen Urlaubstage ein:" << std::endl;
    std::cin >> ut;

    DATUM Gebdat(tg, mg, jg);
    MITARBEITER X(vn, nn, Gebdat, ut);
    Firma.MB_hinzufuegen(X);
}

void GUI::MB_suche()
{
    int x;

    do
    {
        std::string vn, nn;

        std::cout << "Geben sie den Vornamen des Mitarbeiters ein:" << std::endl;
        std::cin >> vn;
        std::cout << "Geben sie den Nachnamen ein:" << std::endl;
        std::cin >> nn;
        x = Firma.MB_suchen(vn, nn);
        if (x<0) 
            std::cout << "Der Mitarbeiter: " << vn << ", " << nn << "existiert nicht." << std::endl;
        else
            std::cout << Firma.Register[x].str();
    }while(x<0);
}

void GUI::MB_Loeschen()
{
    std::string vn, nn;
    int x;

    do
    {
        std::cout << "Geben sie den Vornamen des Mitarbeiters ein:" << std::endl;
        std::cin >> vn;
        std::cout << "Geben sie den Nachnamen ein:" << std::endl;
        std::cin >> nn;
        x = Firma.MB_suchen(vn, nn);
        if (x<0) 
            std::cout << "Der Mitarbeiter: " << vn << ", " << nn << " existiert nicht." << std::endl;
        else
        {
            Firma.MB_loeschen(x);
            std::cout << "Der Mitarbeiter wurde geloescht." << std::endl;
        }
    }while(x<0);
}

void GUI::UrlaubAnlegen()
{
    bool Benut=0;
    int x;

    do 
    {
        
        std::string vn, nn;
        int ut;

        std::cout << "Geben sie den Vornamen des Mitarbeiters ein:" << std::endl;
        std::cin >> vn;
        std::cout << "Geben sie den Nachnamen ein:" << std::endl;
        std::cin >> nn;
        std::cout << "Geben sie den in anspruch genommenen Urlaub ein\n";
        std::cin >> ut;
        x = Firma.MB_suchen(vn, nn);
        if (x<0) 
            std::cout << "Der Mitarbeiter: " << vn << ", " << nn << "existiert nicht.";
        else
        {
            Firma.MB_Urlaubanlegen(x, ut);

            std::cout << "Um einen weiteren Urlaub anzulegen: 1\n";
            std::cout << "Um zum Hauptmenue zurueckzukehren:  0\n";
            std::cin >> Benut;
        }

    }while(Benut && x>=0);
}

void GUI::MB_ListeAnzeigen()
{
    std::cout << "Mitarbeiteranzahl: " << Firma.MBs_anzahl() << std::endl << std::endl;
    std::cout << "Mitarbeiterliste: \n\n" << Firma.MBs_stringliste() << std::endl;
}
