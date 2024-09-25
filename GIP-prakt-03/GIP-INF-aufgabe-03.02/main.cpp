#include <iostream>
using namespace std;

int main()
{

    char eing_1;
    cout << "bitte geben Sie die erste Ziffer ein ?" << endl;
    cin>> eing_1;
    char eing_2;
    cout << "bitte geben Sie die zweite Ziffer ein ?" << endl;
    cin >> eing_2;

    int eing_1_dec = (int) eing_1;
    int eing_2_dec = (int) eing_2;

    if(eing_1_dec == (int)'q' || eing_2_dec == (int)'q'){
        cout << "Das Programm wurde durch Eingabe von q beendet." << endl;
        exit(1);
    }
    else if(eing_1_dec >= (int)'0' && eing_1_dec <= (int)'9' && eing_2_dec >= (int)'0' && eing_2_dec <= (int)'9'){
        cout << (eing_1_dec - (int)'0') << " + " << (eing_2_dec - (int)'0') << " = " << (eing_1_dec - (int)'0') + (eing_2_dec - (int)'0') << endl;
    }
    else{
        cout << "Bitte geben sie ein zahl zwischen 0 - 9 ein." << endl;
    }


    
    system("pause");
    return 0;
}