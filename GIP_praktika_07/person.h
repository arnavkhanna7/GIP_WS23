#ifndef PERSON_H
#define PERSON_H
#include <iostream>
#include <string>

struct Person{
    std::string vorname;
    std::string nachname;
    std::string geburtsdatum;
};

struct Person extrahiere_person(std::string eingabezeile);

#endif
