#include <iostream>
#include "../DATUM.h"

int main()
{
    DATUM day1;
    DATUM day2(20,4,1889);

    std::cout << day1.str() << std::endl;
    std::cout << day2.Jahr << std::endl;

    return 0;
}