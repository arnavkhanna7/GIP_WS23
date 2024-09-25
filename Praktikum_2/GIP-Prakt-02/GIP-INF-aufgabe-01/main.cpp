#include <iostream>

using namespace std;

// aufgabe INF-02.01
int main()
{

    double temp_celsius = 0;
    cout << "Bitte geben Sie die TEmperatur in Grad Celsius ein: ? ";
    cin >> temp_celsius;

    double temp_fahrenheit = temp_celsius * 1.8 + 32;

    cout << "Die Temperatur in Fahrenheit lautet: " << temp_fahrenheit << "\n";

    system("pause");
    return 0;

}