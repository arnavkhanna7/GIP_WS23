#include <iostream>
using namespace std;

// aufgabe INF-02.02

int main()
{
    double length_meter = 0;

    cout << "Bitte geben Sie die Laenge in Metern ein: ? ";
    cin >> length_meter;
    double length_feet = length_meter * 3.2808;
    cout << "Die Laenge in Fuss lautet: " << length_feet << "\n";

    system("pause");
    return 0;
}