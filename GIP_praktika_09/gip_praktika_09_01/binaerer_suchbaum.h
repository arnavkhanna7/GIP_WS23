#pragma once

namespace suchbaum {

    struct BaumKnoten {
        int data;
        BaumKnoten* links;
        BaumKnoten* rechts;
        BaumKnoten(int wert) : data(wert), links(nullptr), rechts(nullptr) {}             //constructor fuer neue baumknote
    };

    void einfuegen(BaumKnoten*& anker, int wert);
    void ausgeben(BaumKnoten* anker);
    void knoten_ausgeben(BaumKnoten* knoten, unsigned int tiefe);

} // namespace suchbaum

