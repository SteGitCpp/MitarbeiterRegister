#include <iostream>
#include "../DATUM.h"

int main()
{
    DATUM day1;
    DATUM day2(20,4,1889);

    // empty constructor
    std::cout << "day1.str() = " << day1.str() << std::endl;
    std::cout << "day1.Tag = " << day1.Tag << std::endl;
    std::cout << "day1.Monat = " << day1.Monat << std::endl;
    std::cout << "day1.Jahr = " << day1.Jahr << std::endl;
    std::cout << std::endl;

    // filled constructor
    std::cout << "day2.str(20,4,1889)= " << day2.str() << std::endl;
    std::cout << "day2.Tag = " << day2.Tag << std::endl;
    std::cout << "day2.Monat = " << day2.Monat << std::endl;
    std::cout << "day2.Jahr = " << day2.Jahr << std::endl;

    return 0;
}