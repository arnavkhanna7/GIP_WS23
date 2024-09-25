// Datei: suchen_rekursiv_main.cpp

#define CATCH_CONFIG_RUNNER
#include "gip_mini_catch.h"

#include <iostream>
using namespace std;

#include "suchen_rekursiv.h"

int main()
{
    Catch::Session().run();	//Testlauf

	string text = "";	//wird eingegeben
	string zkette = ""; //beides

	cout << "Bitte geben Sie den Text ein: ";
	getline(cin, text);

	cout << "Bitte geben Sie die zu suchende Zeichenkette ein: ";
	getline(cin, zkette);



	int result = zeichenkette_suchen_rekursiv(text, zkette); 

	if (result == -1)
		cout << "Die Zeichenkette " << zkette << " ist NICHT im Text " << text << " enthalten." << endl;
	else
	{
		cout << "Die Zeichenkette " << zkette << " ist im Text " << text << " enthalten." << endl;
		cout << "Sie startet ab Zeichen " << result << " (bei Zaehlung ab 0)." << endl;
	}

	system("PAUSE");
	return 0;
}