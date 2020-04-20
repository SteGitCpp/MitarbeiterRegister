#include "MITARBEITERREGISTER.h"

// void MB_hinzufügen(MITARBEITER MB);
int MITARBEITERREGISTER::MB_suchen(std::string vn, std::string nn)
{
     for (int RegPos = 0; RegPos < 500; RegPos++)
     {
         if (Register[RegPos].VName==vn && Register[RegPos].NName==nn)
         {
             return RegPos;
         }
     }   
}

void MITARBEITERREGISTER::MB_loeschen(int RegPos)
{   
    Register[RegPos].reset();
}

void MITARBEITERREGISTER::MB_Urlaubanlegen(int RegPos, int ut)
{
    Register[RegPos].Urlaubstage+=ut;
}

std::string MITARBEITERREGISTER::MBs_stringliste()
{
    std::string strliste;

    for (int i = 0; i < 500 ; i++)
    {
        strliste += Register[i].str();
    }
    return strliste;
}

int MITARBEITERREGISTER::MBs_anzahl()
{
    int i=0;
    int x=0; 

    while (i < 500)
    {
        if (Register[i].Overwrite == false)
        {
            x++;
        }
        i++;
    }

    return x;
}