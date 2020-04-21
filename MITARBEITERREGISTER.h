#include "MITARBEITER.h"

#define REG_LEN 20

#ifndef MITARBEITERREGISTER_H
#define MITARBEITERREGISTER_H

struct MITARBEITERREGISTER
{
    MITARBEITER Register[REG_LEN];

    void MB_hinzufuegen(MITARBEITER MB);
    int MB_suchen(std::string vn, std::string nn);
    void MB_loeschen(int RegPos);
    void MB_Urlaubanlegen(int RegPos, int ut);
    std::string MBs_stringliste();
    int MBs_anzahl();
};

#endif