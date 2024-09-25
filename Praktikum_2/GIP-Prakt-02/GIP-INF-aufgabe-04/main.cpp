#include <iostream>
using namespace std;

// aufgabe INF-02.04
int main()
{

    double nummer = 0;
    cout << "Ihre Eingabe: ? ";
    cin >> nummer;

    cout << "Ihre Auswahl der Umwandlung:\n"
         << "1 - Celsius in Fahrenheit\n"
         << "2 - Meter in Fuss\n"
         << "3 - Euro in US Dollar\n";
    double 
    b;
    cin >> b;
    double summe;

    summe = ((b - 2) * (b - 3) * (nummer * 1.8 + 32) / 2) - ((b - 1) * (b - 3) * (nummer * 3.2808)) + ((b - 1) * (b - 2) * (nummer * 1.2957) / 2);
    cout << "Das Ergebnis lautet: " << summe << endl;

    system("pause");
    return 0;
}