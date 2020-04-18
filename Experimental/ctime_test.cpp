#include <iostream>      /* printf */
#include <ctime>         /* time_t, struct tm, difftime, time, mktime */

int main ()
{
/*
time_t
    Datentyp den die Funktion time() benutzt. Entspricht normalerweise 32-bit 'signed int'.
    Kann aber auch unsigned, 64-bit etc. sein. Das übernimmt der Compiler.

time()
    Gibt die Anzahl an Sekunden, die seit  00:00 Uhr, Jan 1, 1970 UTC vergangen sind.
    Benutzung:
    1.
        |---------------------------|
        | time_t t1 = time(NULL);   |
        |---------------------------|
    2.
        time_t t1;
        t1 = time(NULL);
    3.
        time_t t1;
        time(&t1)
    
struct tm
    Structure, die das Kalenderdatum in (unterteilt Komponenten tag,monat,jahr, ...) enthält:

        Member	Type	Meaning	                    Range
        tm_sec	 int	seconds after the minute	0-60*
        tm_min	 int	minutes after the hour	    0-59
        tm_hour	 int	hours since midnight	    0-23
        tm_mday	 int	day of the month	        1-31
        tm_mon	 int	months since January	    0-11
        tm_year	 int	years since 1900	
        tm_wday	 int	days since Sunday	        0-6
        tm_yday	 int	days since January 1	    0-365
        tm_isdst int	Daylight Saving Time flag	

gmtime()
    Funktion, die aus der Anzahl an vergangen Sekunden (00:00 Uhr, Jan 1, 1970 UTC) in der Variable
    vom Typ 'time_t' gespeichert sind, ein Kalenderdatum vom Typ 'struct tm' macht.

    "Uses the value ... to fill a tm structure with the values that represent the corresponding time"

    Benutzung:

        time_t aktuelles_datum_in_sekunden = time(NULL);
        struct tm *aktuelles_datum;

        aktuelles_datum = gmtime(&aktuelles_datum_in_sekunden);

        std::cout << asctime(aktuelles_datum) << std::endl;
        std::cout << "Wir haben den Monat: " << (*aktuelles_datum).tm_mon;

localtime()
    Genau wie gmtime, berücksichtigt aber die lokale Zeitverschiebung.
*/
time_t aktuelles_datum_in_sekunden = time(NULL);
struct tm *aktuelles_datum;

aktuelles_datum = gmtime(&aktuelles_datum_in_sekunden);

std::cout << asctime(aktuelles_datum) << std::endl;
std::cout << "Wir haben den Monat: '(*aktuelles_datum).tm_mon': " << (*aktuelles_datum).tm_mon << std::endl;
std::cout << "Wir haben das Jahr: 'aktuelles_datum->tm_mon': s" << aktuelles_datum->tm_year << std::endl;
}