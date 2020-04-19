#include "MITARBEITER.h"


MITARBEITER::MITARBEITER()
{
    reset();
}

MITARBEITER::MITARBEITER(std::string nn, std::string vn, DATUM gd, int ut)
{
    NName = nn;
    VName = vn;
    Gebdat = gd;
    Urlaubstage = ut;
}

void MITARBEITER::reset()
{
    NName = "x";
    VName="x";
    Gebdat.Jahr= 0;
    Gebdat.Monat = 0;
    Gebdat.Tag = 0;
    Urlaubstage = 0;
    Overwrite = true;
}

std::string MITARBEITER::str()
{   
    return NName + ", " + VName + "\n" + Gebdat.str() + "\n" + std::to_string(Urlaubstage); 
}
