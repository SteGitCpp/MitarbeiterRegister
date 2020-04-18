#include <string>
 
#include "../DATUM.h"

/* Konvertiert string 'date_str' in gegebenes Datumobjekt 'Date'.
Gibt 'false' zurück, wenn das Datum nicht der Form 'xx.xx.xxxx' entspricht,
ansonsten 'true' [x ist Zahl 0-9] */
bool string_to_date(std::string date_str, DATUM &Date);

/* Benutzt ctime um zu checken ob gegebenes Datum exisitiert.
Gibt 'false' zurück, wenn das Datum nicht existiert, sonst 'true' */
bool is_valid_date(DATUM D);
