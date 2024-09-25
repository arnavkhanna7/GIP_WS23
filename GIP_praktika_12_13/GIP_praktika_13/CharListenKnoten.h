#pragma once
class CharListenKnoten
{
private:
    char data;
    CharListenKnoten *next;
    int my_id;

public:
    //setter und getter methods for class atrributes
    char get_data() { return data; };
    CharListenKnoten *get_next() { return next; };
    
    void set_data(char value) { data = value; };
    void set_next(CharListenKnoten *value) { next = value; };

    //getter for knoten id
    int get_my_id() { return my_id; }

    //constructor
    CharListenKnoten(char d, CharListenKnoten *n = nullptr) : data{d}, next{n}
    {
        my_id = next_available_id;
        next_available_id++;
        object_count++;
    };

    //desctructor
    ~CharListenKnoten()
    {
        object_count--;
    }

    //static attributes 
    static int next_available_id;
    static int object_count;
};
void hinten_anfuegen(CharListenKnoten *&anker, const char wert);

void loesche_alle(CharListenKnoten *&anker);

CharListenKnoten *deep_copy(CharListenKnoten *orig);