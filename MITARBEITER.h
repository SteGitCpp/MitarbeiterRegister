#include <string>
#include <ctime>

#include "Datum.h"

#ifndef MITARBEITER_H
#define MITARBEITER_H

//Konstruktor: Nachname, Vorname, Geburtsdatum, Urlaubtstage.
struct MITARBEITER
{
        std::string NName, VName;
        DATUM Gebdat;
        int Urlaubstage;
        bool Overwrite{false};

        MITARBEITER();
        MITARBEITER(std::string nn, std::string vn, DATUM gd, int ut);

        void reset();
        std::string str();
        int restUrlaub();
};

#endif
