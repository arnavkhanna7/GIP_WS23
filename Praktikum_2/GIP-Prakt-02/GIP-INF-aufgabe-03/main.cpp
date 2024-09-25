#include <iostream>
using namespace std;

// aufgabe INF-02.03

int main()
{

    double euro = 0;
    cout << "Bitte geben Sie die Geldmenge in Euro ein: ? ";
    cin >> euro;
    double dollar = euro * 1.2957;

    cout << "Die Geldmenge in US Dollar lautet: " << dollar << "\n";

    system("pause");
    return 0;
}