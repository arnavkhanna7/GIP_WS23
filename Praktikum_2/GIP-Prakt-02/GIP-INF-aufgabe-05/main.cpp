#include <iostream>
using namespace std;

// aufgabe INF-02.05
int main()
{

    char alphabet;
    cout << "Bitte geben Sie den Buchstaben ein: ? ";
    cin >> alphabet;

    cout << "Der Buchstabe " << alphabet << " hat die Position " << int(alphabet) - ((int)'a' -1 ) << " im Alphabet.\n";

    // buchstabe a beginnt mit dezimal wert 97
    system("pause");
    return 0;

}