// Datei: sudoku_pruefen_main.cpp

#include <iostream>
#include <string>
using namespace std;

const size_t sudoku_groesse = 9;
const size_t eingabe_groesse = 11;

bool pruefe_spalten(int sudoku[][sudoku_groesse]){
    // Ihr Code hier ...

    bool spalte = true;

    for (int j = 0; j < sudoku_groesse; j++) {
        int digitCount[10] = {0};

        for (int i = 0; i < sudoku_groesse; i++) {
            int currentDigit = sudoku[i][j];

            if (digitCount[currentDigit] == 1) {
                spalte = false;
                cout << "Spalte " << j << ": Zahl " << currentDigit << " kommt mehrfach vor." << endl;
            }

            digitCount[currentDigit]++;
        }

        for (int digit = 1; digit <= 9; digit++) {
            if (digitCount[digit] == 0) {
                spalte = false;
                cout << "Spalte " << j << ": Zahl " << digit << " kommt nicht vor." << endl;
            }
        }
    }

    return spalte;
}

bool pruefe_zeilen(int sudoku[][sudoku_groesse]){
    // Ihr Code hier ...
    bool zeile = true;
    for(int i=0; i< sudoku_groesse;i++){
        int digitCount[10] = {0};
        for(int j=0;j<sudoku_groesse;j++){
           int currentDigit = sudoku[i][j];

            if (digitCount[currentDigit] == 1) {
                zeile = false;
                cout << "Zeile " << i << ": Zahl " << currentDigit << " kommt mehrfach vor." << endl;
            }

            digitCount[currentDigit]++;
        }

        for (int digit = 1; digit <= 9; digit++) {
            if (digitCount[digit] == 0) {
                zeile = false;
                cout << "Zeile " << i << ": Zahl " << digit << " kommt nicht vor." << endl;
            }
        }
    }

    return zeile;
}

bool pruefe_bloecke(int sudoku[][sudoku_groesse])
{
    bool bloecke = true;
    for (int blockRow = 0; blockRow < sudoku_groesse; blockRow += 3) {
        for (int blockCol = 0; blockCol < sudoku_groesse; blockCol += 3) {
            int digitCount[10] = {0};                        // Array to count number of digits (0-9)

            for (int i = 0; i < 3; ++i) {
                for (int j = 0; j < 3; ++j) {
                    int currentNum = sudoku[blockRow + i][blockCol + j];

                    digitCount[currentNum]++;
                }
            }

            for (int digit = 1; digit <= 9; ++digit) {
                if (digitCount[digit] > 1) {
                    cout << "Block " << blockRow / 3 * 3 + blockCol / 3 
                    << ": Zahl " << digit << " kommt mehrfach vor." << endl;
                    bloecke = false;
                } else if (digitCount[digit] == 0) {
                    cout << "Block " << blockRow / 3 * 3 + blockCol / 3 << ": Zahl " 
                    << digit << " kommt nicht vor." << endl;
                    bloecke = false;
                }
            }
        }
    }

    return bloecke;
}


void konvertiere(string eingabe[], int sudoku[][sudoku_groesse])
{
    // Ihr Code aus dem letzten Praktikum zum Umwandeln der Eingabe-Texte
    // fuer die Zeilen in das Array sudoku[][] hier hin ...
    
    // removing . and | from the string
    string eingabe_new[11];
    for(int i=0;i<11;i++){
            for(int j=0;j<eingabe[i].length();j++){
                if(eingabe[i].at(j) >= '0' && eingabe[i].at(j) <= '9'){
                    eingabe_new[i]+=eingabe[i].at(j);
                    }
                        
            }
        }

    // removing empty lines from the array
    string eingabe_final[9];
        int z = 0;
        for(int j=0; j<11;j++){
            if(j==3 or j==7)
                continue;
            else{
                eingabe_final[z] = eingabe_new[j];
                z+=1;
                
            }

        }


    
    // convering string array to int 
    int a = 0;
    for(int i=0; i<9;i++,a++){
        int c = 0;
        for(int j =0; j<9;j++){
            sudoku[a][c] = (int)eingabe_final[i][j] - (int)'0';
                c++;
        }

    }

}

int main() 
{
    int sudoku[sudoku_groesse][sudoku_groesse] = { 0 };
    string eingabe[eingabe_groesse];

    cout << "Bitte geben Sie das Sudoku ein:" << endl;
    for (size_t i = 0; i < eingabe_groesse; i++)
        getline(cin, eingabe[i]);

    konvertiere(eingabe, sudoku);

    for(int i=0;i<9;i++){
        for(int j=0;j<9;j++){
            cout << sudoku[i][j];
        }
        cout<<endl;
    }

    bool ps = pruefe_spalten(sudoku);
    bool pz = pruefe_zeilen(sudoku);
    bool pb = pruefe_bloecke(sudoku); 

    if (ps && pz && pb)
        cout << "Das Sudoku ist gueltig." << endl;

    system("PAUSE");
    return 0;
}


/*
.5.1.4.|.8.6.9.|.7.2.3
.8.7.2.|.3.4.5.|.6.1.9
.9.6.3.|.2.1.7.|.5.4.8
-------|-------|-------
.6.2.8.|.1.3.4.|.9.5.7
.1.9.7.|.6.5.2.|.8.3.4
.4.3.5.|.7.9.8.|.1.6.2
-------|-------|-------
.2.4.6.|.9.7.1.|.3.8.5
.7.5.1.|.4.8.3.|.2.9.6
.3.8.9.|.5.2.6.|.4.7.1 


.1.1.4.|.8.6.9.|.7.2.3 
.8.7.2.|.3.4.5.|.6.1.9 
.9.6.3.|.2.1.7.|.5.4.8 
-------|-------|------- 
.6.2.8.|.1.3.4.|.9.5.7 
.1.9.7.|.6.5.2.|.8.3.4 
.4.3.5.|.7.9.8.|.1.6.2 
-------|-------|------- 
.2.4.6.|.9.7.1.|.3.8.5 
.7.5.1.|.4.8.3.|.2.9.6 
.3.8.9.|.5.2.6.|.4.7.9 

*/