// Datei: parser_main.cpp

#include <iostream>
#include <string>

bool expect(char c, std::string &input, std::size_t pos)
{
    std::cout << "Teste auf das Zeichen " << c << std::endl;
    if ( pos >= input.length() )
    {
        std::cout << "Aber schon am Ende der "
                  << "Eingabe-Zeichenkette angelangt.\n";
        return false;
    }
    if ( input.at(pos) == c )
    {
        std::cout << "Zeichen " << c << " gefunden.\n";
        return true;
    }
    else
    {
        std::cout << "Test auf " << c << " nicht erfolgreich. "
                  << "Stattdessen " << input.at(pos) 
                  << " gesehen." << std::endl;
        return false;
    }
}

void match(char c, std::string &input, std::size_t &pos)
{
    std::cout << "Betrete match() fuer das Zeichen " << c << std::endl;
    if ( pos >= input.length() )
    {
        std::cout << "Error! Input-Zeichenkette zu kurz. "
                  << "Erwarte noch das Zeichen " << c << std::endl
                  << "Verlasse match()" << std::endl;
        return;
    }
    if ( input.at(pos) != c )
    {
        std::cout << "Error! An Position "
                  << pos << " erwarte "
                  << c << " und sehe " << input.at(pos) << std::endl;
        std::cout << "Verlasse match()" << std::endl;
        return;
    }
    pos++;
    std::cout << "Zeichen " << c << " konsumiert.\n"
              << "Verlasse match() fuer das Zeichen " 
              << c << std::endl;
}

// Die Funktions-Prototypen ...
void parse_gesamtausdruck(std::string &input, std::size_t &pos);
void parse_ausdruck(std::string &input, std::size_t &pos);
void parse_term(std::string &input, std::size_t &pos);
void parse_operand(std::string &input, std::size_t &pos);
void parse_number(std::string &input, std::size_t &pos);

void parse_gesamtausdruck(std::string &input, std::size_t &pos)
{
    std::cout << "Betrete parse_gesamtausdruck()" << std::endl;
    
    // ... (TODO)
    
    parse_ausdruck(input, pos);
    if (expect('.', input, pos))
    {
        match('.', input, pos);
        //std::cout << "Gesamtausdruck syntaktisch korrekt." << std::endl;
    }
    else
    {
        std::cout << "Error! Erwarte '.' am Ende." << std::endl;
    }
    
    // ... (TODO)
    
    std::cout << "Verlasse parse_gesamtausdruck()" << std::endl;
}

void parse_ausdruck(std::string &input, std::size_t &pos)
{
    std::cout << "Betrete parse_ausdruck()" << std::endl;
    
    // ... (TODO)
    parse_term(input,pos);

    while ( expect('U', input, pos) ||
            expect('O', input, pos) )
    {
        if (expect('U', input, pos))
        {
            std::cout << "Betrete parse_ausdruck(): U Fall" << std::endl;
            
            // ... (TODO)
            match('U',input,pos);
            parse_term(input,pos);

            std::cout << "Verlasse parse_ausdruck(): U Fall" 
                 << std::endl;
        }
        else if ( expect('O', input, pos) )
        {
            std::cout << "Betrete parse_ausdruck(): O Fall" << std::endl;
            
            match('O',input,pos);
            parse_term(input,pos);
            // ... (TODO)
            
            std::cout << "Verlasse parse_ausdruck(): O Fall" 
                      << std::endl;
        }
    }
    std::cout << "Verlasse parse_ausdruck()" << std::endl;
}

void parse_term(std::string &input, std::size_t &pos)
{
    std::cout << "Betrete parse_term()" << std::endl;
    parse_operand(input,pos);
    
    while(expect('>',input,pos) || expect('<',input,pos)){
        if(expect('>',input,pos)){
            std::cout << "Betrete parse_term() : > Fall" << std::endl;
            match('>',input,pos);
            parse_operand(input,pos);
            //...(TODO) Handle > case
            std::cout << "Verlasse parse_term() : > Fall" << std::endl;
        }
        else if(expect('<',input,pos)){
            std::cout << "Betrete parse_term(): < Fall" << std::endl;
            match('<', input, pos);
            parse_operand(input, pos);
            // ... (TODO) Handle < case
            std::cout << "Verlasse parse_term(): < Fall" << std::endl;
        }
    }
    // ... (TODO)
    
    std::cout << "Verlasse parse_term()" << std::endl;
}

void parse_operand(std::string &input, std::size_t &pos)
{
    std::cout << "Betrete parse_operand()" << std::endl;
    
    if ( expect('(', input, pos) )
    {
        std::cout << "Betrete parse_operand(): '(' Fall" << std::endl;
        
        match('(', input, pos);
        parse_ausdruck(input, pos);

        // ... (TODO)
        if (expect(')', input, pos))
        {
            match(')', input, pos);
        }
        else
        {
            std::cout << "Error! Erwarte ')' nach Ausdruck in Operand." << std::endl;
        }
        std::cout << "Verlasse parse_operand(): '(' Fall" << std::endl;        
    }
    else {
        // ... (TODO)
        parse_number(input,pos);
    }
    
    std::cout << "Verlasse parse_operand()" << std::endl;
}

void parse_number(std::string &input, std::size_t &pos)
{
    std::cout << "Betrete parse_number()" << std::endl;
    
    // ... (TODO)
    if (expect('0', input, pos) || expect('1', input, pos) || expect('2', input, pos) ||
        expect('3', input, pos) || expect('4', input, pos) || expect('5', input, pos) ||
        expect('6', input, pos) || expect('7', input, pos) || expect('8', input, pos) ||
        expect('9', input, pos))
    {
        match(input.at(pos), input, pos);
    }
    else
    {
        std::cout << "Error! Erwarte Ziffer in Number." << std::endl;
    }

    std::cout << "Verlasse parse_number()" << std::endl;
}

int main()
{    
    std::size_t pos = 0;

    std::cout << "Bitte geben Sie die Zeichenkette ein: " ;
    //std::string input; std::getline(std::cin, input);


    // Nur eine der folgenden Zeilen auskommentieren ...
    // Letzte Zeile: mit Benutzereingabe (für eigene Testläufe)
    // Zeilen davor: spezifische Testläufe (Eintippen nicht nötig)
    //
    // std::string input = "(3U4U7)>(5U2)."; // syntaktisch korrekt
    std::string input = "(4>3)U2<7."; // syntaktisch korrekt
    // std::string input = "(4>3)U2<7"; // syntaktisch inkorrekt: finaler Punkt fehlt
    //std::string input = "(4>)U2<"; // syntaktisch inkorrekt

    parse_gesamtausdruck(input, pos);

    if ( pos != input.length() ) {
        std::cout << "Error! Noch Input-Zeichen uebrig.\n";
    }

    std::system("PAUSE");
    return 0;
}
