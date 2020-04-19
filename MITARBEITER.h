#include <string>
#include <ctime>

#include "DATUM.h"

//Konstruktor: Nachname, Vorname, Geburtsdatum, Urlaubtstage.
class MITARBEITER
{
    public:
        std::string NName, VName;
        DATUM Gebdat;
        int Urlaubstage;
        bool Overwrite{false};

    // public:
        MITARBEITER();
        MITARBEITER(std::string nn, std::string vn, DATUM gd, int ut);

        void reset();
        std::string str();
        int restUrlaub();
        void Urlaub_add(int ut);
};
