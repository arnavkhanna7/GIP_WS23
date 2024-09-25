#include "binaerer_suchbaum.h"
#include <iostream>

namespace suchbaum {

    void einfuegen(BaumKnoten*& anker, int wert) {
        if (!anker) {
            anker = new BaumKnoten(wert);
        } else if (wert < anker->data) {
            einfuegen(anker->links, wert);
        } else if (wert > anker->data) {
            einfuegen(anker->rechts, wert);
        }
    }

    void knoten_ausgeben(BaumKnoten* knoten, unsigned int tiefe) {
         if (knoten) {
            knoten_ausgeben(knoten->rechts, tiefe + 1);
            for (unsigned int i = 0; i < tiefe * 2; ++i) {
                std::cout << "+";
            }
            std::cout << knoten->data << std::endl;
            knoten_ausgeben(knoten->links, tiefe + 1);
        }
    }

    void ausgeben(BaumKnoten* anker) {
        if(!anker){
            std::cout << "Leerer Baum." << std::endl; 
        }
        knoten_ausgeben(anker, 0);
    }

} // namespace suchbaum
