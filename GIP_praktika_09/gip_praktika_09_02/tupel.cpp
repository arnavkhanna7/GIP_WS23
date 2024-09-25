#include "tupel.h"
#include <string>

template <typename T1, typename T2>

int vergleiche( Tupel<T1, T2>& p1,  Tupel<T1, T2>& p2) {
    if (p1.komponente1 < p2.komponente1 && p1.komponente2 < p2.komponente2) {
        return -1;
    } else if (p1.komponente1 > p2.komponente1 && p1.komponente2 > p2.komponente2) {
        return 1;
    } else {
        return 0;
    }
}

// Explizite Instanziierung für benötigte Typen
template int vergleiche<std::string, int>( Tupel<std::string, int>& p1, Tupel<std::string, int>& p2);
template int vergleiche<int, int>( Tupel<int, int>& p1, Tupel<int, int>& p2);
template int vergleiche<std::string, std::string> (Tupel<std::string,std::string> &s1, Tupel<std::string,std::string> &s2);

