#pragma once

#include "BaumKnoten.h"

class BinaererSuchbaum {
private:
    BaumKnoten* root;

public:
    BinaererSuchbaum();

    // Getter for root
    BaumKnoten* get_root() const;

    // Methods to insert and print
    void einfuegen(int value);
    void ausgeben() const;
};

