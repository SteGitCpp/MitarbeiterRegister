void MITARBEITER::Reset()
{
    NName,VName="x";
    Gebdat.Jahr, Gebdat.Monat, Gebdat.Tag = 00;
    Urlaubstage = 0;
    Overwrite={true};
}

std::string MITARBEITER::str()
{   
    return NName + ", " + VName + "\n" + Gebdat.str() + "\n" + std::to_string(Urlaubstage); 
}

int MITARBEITER::restUrlaub()
{
    //ctime
    time_t HDATUM;
    struct tm * tmHDatum;
    tmHDatum = gmtime(&HDATUM);

    if (tmHDatum.tm_year-Gebdat.Jahr > 50)
    // if (tmHDatum-> tm_year-Gebdat.Jahr>50)
    {
        int restUrlaub=32-Urlaubstage;
    }else
    {
        int restUrlaub=30-Urlaubstage;
    }
}