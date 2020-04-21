#include "MITARBEITER.h"


MITARBEITER::MITARBEITER()
{
    reset();
}

MITARBEITER::MITARBEITER(std::string nn, std::string vn, DATUM gd, int ut):
NName(nn), VName(vn), Gebdat(gd), Urlaubstage(ut) {}

void MITARBEITER::reset()
{
    NName = "x";
    VName = "x";
    Gebdat.Jahr = 0;
    Gebdat.Monat = 0;
    Gebdat.Tag = 0;
    Urlaubstage = 0;
    Overwrite = true;
}

std::string MITARBEITER::str()
{   
    std::string s;
    s = "\t\t Name: " + NName + ", " + VName + "\n";
    s += "\t\t  Geb: " +  Gebdat.str() + "\n";
    s += "genommene Urlaubstage: " + std::to_string(Urlaubstage) + "\n\n";       
    return s;
}

int MITARBEITER::restUrlaub()
{
    time_t HDATUM;
    struct tm tmHDatum;
    tmHDatum = *gmtime(&HDATUM);

    int restUrlaub;

    if (tmHDatum.tm_year - Gebdat.Jahr > 50)
        restUrlaub = 32 - Urlaubstage;
    else
        restUrlaub = 30 - Urlaubstage;
    
    return restUrlaub;
}

