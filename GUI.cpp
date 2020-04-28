#include <iostream>
#include "GUI.h"


void GUI::main()
{
    int Benut;

    do
    {
        Benutzermenue();
        std::cin >> Benut; 

        if (std::cin.fail())
        {
            std::cin.clear();
            std::cin.ignore(1000, '\n');
            Benut = 9; // willkuerliche invalide Nummer
        }

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
                std::cout << "Das eingegebene Kommando ist nicht vorhanden: Bitte geben sie ein neues an.\n";
                break;
        }
        //std::cin.clear();
        //std::cin.ignore(1000, '\n');
    }while(Benut != 0);
}

void GUI::Benutzermenue()
{
    std::cout << "Benutzermenue:" << std::endl;
    std::cout << "(1) Mitarbeiter anlegen" << std::endl;
    std::cout << "(2) Mitarbeiter suchen" << std::endl;
    std::cout << "(3) Urlaub anlegen" << std::endl;
    std::cout << "(4) Mitarbeiter loeschen" << std::endl;
    std::cout << "(5) Mitarbeiterliste anzeigen" << std::endl;
    std::cout << "(0) Programm beenden" << std::endl;
}

void GUI::MB_anlegen()
{
    std::string vn, nn;
    int tg, mg, jg, ut;

    std::cout << "Vorname: ";
    std::cin >> vn;
    std::cout << "Nachname: ";
    std::cin >> nn;
    std::cout << "Tag des Geburtsdatums: ";
    std::cin >> tg;
    std::cout << "Monat des Geburtsdatums: ";
    std::cin >> mg;
    std::cout << "Jahr des Geburtsdatums: ";
    std::cin >> jg;
    std::cout << "Urlaubstage: ";
    std::cin >> ut;

    DATUM Gebdat(tg, mg, jg);
    MITARBEITER temp_MB(nn, vn, Gebdat, ut);

    // std::cout << "DEBUG: "<< Gebdat.str() << std::endl;
    // std::cout << "DEBUG: "<< temp_MB.str() << std::endl;

    Firma.MB_hinzufuegen(temp_MB);

    std::cout << "\nMitarbeiter hinzugefuegt\n\n";
}

void GUI::MB_suche()
{
    int x;

    std::string vn, nn;

    std::cout << "Vorname: ";
    std::cin >> vn;
    std::cout << "Nachname: ";
    std::cin >> nn;
    x = Firma.MB_suchen(vn, nn);
    if (x < 0) 
        std::cout << "\nDer Mitarbeiter: " << vn << " " << nn << " existiert nicht." << std::endl;
    else
        std::cout << std::endl << "Mitarbeiter gefunden:\n" << Firma.Register[x].str();
}

void GUI::MB_Loeschen()
{
    std::string vn, nn;
    int x;

    std::cout << "Vorname: ";
    std::cin >> vn;
    std::cout << "Nachname: ";
    std::cin >> nn;
    x = Firma.MB_suchen(vn, nn);
    if (x < 0) 
        std::cout << "\nDer Mitarbeiter: " << vn << ", " << nn << " existiert nicht.\n\n";
    else
    {
        Firma.MB_loeschen(x);
        std::cout << "Mitarbeiter geloescht.\n" << std::endl;
    }
}

void GUI::UrlaubAnlegen()
{
    bool Benut=0;
    int x;

    do 
    {
        std::string vn, nn;
        int ut;

        std::cout << "    Vorname: ";
        std::cin >> vn;
        std::cout << "   Nachname: ";
        std::cin >> nn;

        x = Firma.MB_suchen(vn, nn);
        if (x < 0) 
            std::cout << std::endl << "Der Mitarbeiter: " << vn << " " << nn << " existiert nicht.\n";
        else
        {
            std::cout << "Urlaubstage: ";
            std::cin >> ut;
            std::cout << std::endl;

            Firma.MB_Urlaubanlegen(x, ut);
        }
        std::cout << std::endl <<  "(1) Weiteren Urlaub anlegen\n";
        std::cout << "(0) Hauptmenue\n\n";
        std::cin >> Benut;
        std::cout << std::endl;

    }while(Benut);
}

void GUI::MB_ListeAnzeigen()
{
    std::cout << "Mitarbeiteranzahl: " << Firma.MBs_anzahl() << std::endl << std::endl;
    std::cout << std::endl << Firma.MBs_stringliste() << std::endl;
}
