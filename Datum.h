#include <string>

#ifndef DATUM_H
#define DATUM_H

// Konstruktor: Tag, Monat, Jahr.
struct DATUM
{
    int Tag, Monat, Jahr;
    DATUM(): Tag(0), Monat(0), Jahr(0){}
    DATUM(int t,int m, int j): Tag(t), Monat(m), Jahr(j){}
    std::string str();
};

#endif
