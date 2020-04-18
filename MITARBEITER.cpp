#include "MITARBEITER.h"


MITARBEITER::MITARBEITER()
{
    NName, VName="x";
    Gebdat.Jahr, Gebdat.Monat, Gebdat.Tag = 0;
    Urlaubstage = 0;
}

MITARBEITER::MITARBEITER(std::string nn, std::string vn, DATUM gd, int ut)
{
    NName = nn;
    VName = vn;
    Gebdat = gd;
    Urlaubstage = ut;
}

