// In texte.h
#ifndef TEXTE_H
#define TEXTE_H

#include <string>

void spalte_ab_erstem(const std::string &eingabe, char trennzeichen, std::string &teil1, std::string &rest);
std::string trimme(const std::string &s);
std::string ersetze(const std::string &s, char placeholder, const std::string &replacement);
#endif // TEXTE_H
