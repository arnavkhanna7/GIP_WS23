// Datei: suchen_rekursiv.cpp

#include <string>
#include "aufruf_visualisieren.h"
#include "suchen_rekursiv.h"

int zeichenkette_suchen_rekursiv(
	std::string text, 
	std::string zkette, 
	size_t text_pos, 
	size_t text_such_pos, 
	size_t zkette_such_pos){
	// Die folgende Zeile "aktivieren", wenn Sie zusaetzliche Programmausgaben
	// haben moechten, die das Verstaendnis der rekursiven Aufrufe ggfs.
	// unterstuetzen ...
	//aufruf_visualisieren(text, zkette, text_pos, text_such_pos, zkette_such_pos);

	// Ihr Code ab hier ...

	//if text and zkette are empty
	if (text == "" || zkette == "")
		
	{
		return -1;
	}


	//if current position matches
	if (text.at(text_such_pos) == zkette.at(zkette_such_pos)) 
	{
		text_such_pos++;	
		zkette_such_pos++;
	}

	else
	{
		text_pos++;
		text_such_pos = text_pos; 
		zkette_such_pos = 0;
	}
	

	//if end of text is reached 
	if (text_such_pos == text.length()) 
		 
	{
		if (zkette_such_pos != zkette.length())	
		{										
			return -1;						
		}
		return text_pos; 
	}
	else if (zkette_such_pos == zkette.length())
	{
		return text_pos;
	}
	
	else 
	{
		return zeichenkette_suchen_rekursiv(text, zkette, text_pos, text_such_pos, zkette_such_pos);
	}

}
