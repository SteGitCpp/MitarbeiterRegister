#include <iostream>

#include "DateReadIn.h"

int main()
{
    const std::string teststrings[] = {"28.01.1999", "9.1.2020", "3.19.0101", "23 jan 2010"};
    DATUM temp_date;

    for (const auto &date_str : teststrings) {
        std::cout << '\'' << date_str << '\'' << std::endl;

        if (string_to_date(date_str, temp_date)) {
            std::cout << "    - string konvertierbar: Ja [date.str() = " << temp_date.str() << ']' << std::endl;

            if (is_valid_date(temp_date))
                std::cout << "    - datum existiert: Ja" << std::endl;
            else
                std::cout << "    - datum existiert: Nein" << std::endl;
        }
        else{
            std::cout << "    - string konvertierbar: Nein" << std::endl;
        }
    }
    return 0;
}
