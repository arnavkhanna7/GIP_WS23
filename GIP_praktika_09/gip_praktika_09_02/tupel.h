#pragma once

template <typename T1, typename T2>
struct Tupel {
    T1 komponente1;
    T2 komponente2;

    //Tupel(const T1& k1, const T2& k2) : komponente1(k1), komponente2(k2) {}
};

template <typename T1, typename T2>
int vergleiche( Tupel<T1, T2>& p1, Tupel<T1, T2>& p2);

