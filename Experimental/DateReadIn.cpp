#include <string>
#include <regex>

#include "DateReadIn.h"

/* Konvertiert string 'date_str' in gegebenes Datumobjekt 'Date'.
Gibt 'false' zurück, wenn das Datum nicht der Form 'xx.xx.xxxx' entspricht,
ansonsten 'true' [x ist Zahl 0-9] */
bool string_to_date(std::string date_str, DATUM &Date)
{
    const std::regex date_regex("([0-9]{2})\\.([0-9]{2})\\.([0-9]{4})");
    std::smatch sub_matches;

    if (std::regex_match(date_str, sub_matches, date_regex)) {
        // Note: sub_matches.size() == 4
        Date.Tag = std::stoi(sub_matches[1].str());
        Date.Monat = std::stoi(sub_matches[2].str());
        Date.Jahr = std::stoi(sub_matches[3].str());
        return true;
    }
    else{
        return false;
    }
}

/* Benutzt ctime um zu checken ob gegebenes Datum exisitiert.
Gibt 'false' zurück, wenn das Datum nicht existiert, sonst 'true' */
bool is_valid_date(DATUM D)
{
    time_t rawtime;
    struct tm * timeinfo;

    /* fill timeinfo with current time */
    time(&rawtime);
    timeinfo = localtime(&rawtime);

    /* change timeinfo with given time data */
    timeinfo->tm_year = D.Jahr - 1900;
    timeinfo->tm_mon = D.Monat - 1;
    timeinfo->tm_mday = D.Tag;

    /* use mktime to check if date is valid (returns -1 if invalid) */
    if (mktime(timeinfo) > -1)
        return false;
    return true;
}



