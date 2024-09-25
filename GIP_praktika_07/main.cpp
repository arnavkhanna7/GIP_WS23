// In main.cpp
#include <iostream>
#include <string>
#include <fstream>
#include "person.h"
#include "texte.h"


std::string br(std::string s) {
    return s + "<br/>";
}

std::string b(std::string s) {
    return "<b>" + s + "</b>";
}

int main() {
    std::string eingabezeile = "",kurztext = "", langtext = "";
    std::ifstream datendatei("personendaten.txt");

    if (!datendatei.is_open()) {
        std::cerr << "Fehler beim Öffnen der Datei 'personendaten.txt'" << std::endl;
        return 1;
    }

    while (std::getline(datendatei, eingabezeile)) {
        Person person = extrahiere_person(eingabezeile);
        std::cout << "Vorname: " << person.vorname << ", Nachname: " << person.nachname
                  << ", Geburtsdatum: " << person.geburtsdatum << std::endl;


        kurztext += br(b(person.nachname) + ", " + person.vorname) + "\n";
        langtext += br(b(person.vorname + " " + person.nachname) + ", " + person.geburtsdatum) + "\n";
    }

    datendatei.close();

    //opening template file
    std::ifstream templateFile("webseite.html.tmpl");

    if(!templateFile.is_open()){
        std::cerr << "Error opening template file." << std::endl;
        return 1;
    }

    // Open output file
    std::ofstream outputFile("webseite2.html");

    if (!outputFile.is_open()) {
        std::cerr << "Error opening output file." << std::endl;
        return 1;
    }

    //reading template file and using ersetze function

    while(std::getline(templateFile,eingabezeile)){
        eingabezeile = ersetze(eingabezeile, '%',kurztext);
        eingabezeile = ersetze(eingabezeile,'$',langtext);

        outputFile << eingabezeile + "\n";
    }

    templateFile.close();
    outputFile.close();


    system("pause");
    return 0;
}
