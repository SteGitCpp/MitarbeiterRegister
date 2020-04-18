#include "DATUM.h"

std::string DATUM::str()
{
    return std::to_string(Tag) + "." + std::to_string(Monat) + "." + std::to_string(Jahr);
}