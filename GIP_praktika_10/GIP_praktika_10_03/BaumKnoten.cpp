#include "BaumKnoten.h"
#include <iostream>

BaumKnoten::BaumKnoten(int wert, BaumKnoten* links, BaumKnoten* rechts)
    : data(wert), links(links), rechts(rechts) {}

BaumKnoten::~BaumKnoten() {
    delete links;
    delete rechts;
}

int BaumKnoten::get_data() {
        return data;
    }


void BaumKnoten::set_data(int value) {
    data = value;
}

BaumKnoten* BaumKnoten::get_links() {
    return links;
}

void BaumKnoten::set_links(BaumKnoten* node) {
    links = node;
}

BaumKnoten* BaumKnoten::get_rechts()  {
    return rechts;
}

void BaumKnoten::set_rechts(BaumKnoten* node) {
    rechts = node;
}

void BaumKnoten::ausgeben(unsigned int tiefe)  {
    if (rechts) {
        rechts->ausgeben(tiefe + 1);
    }

    for (unsigned int i = 0; i < tiefe * 2; ++i) {
        std::cout << "+";
    }

    std::cout << data << std::endl;

    if (links) {
        links->ausgeben(tiefe + 1);
    }
}

