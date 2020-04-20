#include "MITARBEITER.h"

class MITARBEITERREGISTER
{
    MITARBEITER Register[500];

    public:
        void MB_hinzufügen(MITARBEITER MB);
        int MB_suchen(std::string vn, std::string nn);
        void MB_loeschen(int RegPos);
        void MB_Urlaubanlegen(int RegPos, int ut);
        std::string MBs_stringliste();
        int MBs_anzahl();
};