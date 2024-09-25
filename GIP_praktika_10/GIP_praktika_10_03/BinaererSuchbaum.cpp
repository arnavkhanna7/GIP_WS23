#include "BinaererSuchbaum.h"
#include <iostream>

BinaererSuchbaum::BinaererSuchbaum() : root(nullptr) {}

BaumKnoten* BinaererSuchbaum::get_root() const {
    return root;
}

void BinaererSuchbaum::einfuegen(int wert) {
    // Implementation for insertion into the binary search tree
    if (!root) {
            root = new BaumKnoten(wert, nullptr, nullptr);
            return;
        }

        BaumKnoten* aktuellerKnoten = root;
        while (true) {
            if (wert < aktuellerKnoten->get_data()) {
                if (aktuellerKnoten->get_links() == nullptr) {
                    aktuellerKnoten->set_links(new BaumKnoten(wert, nullptr, nullptr));
                    return;
                }
                aktuellerKnoten = aktuellerKnoten->get_links();
            } else if (wert > aktuellerKnoten->get_data()) {
                if (aktuellerKnoten->get_rechts() == nullptr) {
                    aktuellerKnoten->set_rechts(new BaumKnoten(wert, nullptr, nullptr));
                    return;
                }
                aktuellerKnoten = aktuellerKnoten->get_rechts();
            } else {
                // Wert already exists in the tree, do nothing
                return;
            }
    }
}


void BinaererSuchbaum::ausgeben() const {
    if (root) {
        root->ausgeben(0);
    } else {
        std::cout << "Leerer Baum." << std::endl;
    }
}
