#include "MitarbeiterRegister.h"
#include <iostream>


void MITARBEITERREGISTER::MB_hinzufuegen(MITARBEITER MB)
{
    // std::cout << "DEBUG: MB_hinzufuegen() called" << std::endl;
    for (int i = 0; i < REG_LEN; i++)
    {
        // std::cout << "DEBUG: MB_hinzufuegen() into for loop" << std::endl;
        if (Register[i].Overwrite)
        {
            Register[i] = MB;
            // std::cout << "DEBUG: MB_hinzufuegen() MB hinzugefuegt" << std::endl;
            return;
        }            
    }
}

int MITARBEITERREGISTER::MB_suchen(std::string vn, std::string nn)
{
     for (int RegPos = 0; RegPos < REG_LEN; RegPos++)
     {
         if (Register[RegPos].VName == vn && Register[RegPos].NName == nn)
             return RegPos;
     }
     return -1;   
}

void MITARBEITERREGISTER::MB_loeschen(int RegPos)
{   
    Register[RegPos].reset();
}

void MITARBEITERREGISTER::MB_Urlaubanlegen(int RegPos, int ut)
{
    Register[RegPos].Urlaubstage += ut;
}

std::string MITARBEITERREGISTER::MBs_stringliste()
{
    std::string strliste;

    for (int i = 0; i < REG_LEN; i++)
    {
        if (!Register[i].Overwrite)
        {
             // strliste += "Mitarbeiternummer: " + std::to_string(i) + "\n";
            strliste += Register[i].str();
        }
    }
    return strliste;
}

int MITARBEITERREGISTER::MBs_anzahl()
{
    int cntr = 0; 

    for (int i = 0; i < REG_LEN; i++)
    {
        if (!Register[i].Overwrite)
            cntr++;
    }
    return cntr;
}
