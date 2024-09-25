#pragma once
#include "CharListenKnoten.h"
#include <string>
class MyString2
{
private:
    CharListenKnoten *anker;

public:
    //Aufgabe 13.01
    CharListenKnoten *get_anker() { return anker; };
    void set_anker(CharListenKnoten *a) { anker = a; };

    MyString2() : anker{nullptr} {};  //standard konstruktor

    //Aufgabe 13.03 (zusätzliche konstruktor)
    MyString2(std::string s) : anker{nullptr}
    {
        for (size_t i = 0; i < s.length(); i++)
        {
            hinten_anfuegen(anker, s.at(i));
        }
    }

    //Aufgabe 13.04 - copy konstruktor
    MyString2(const MyString2 &orig)
    {
        anker = deep_copy(orig.anker);
    }

    //Aufgabe 13.04 - assignment operator
    MyString2 operator=(const MyString2 &orig)
    {
        loesche_alle(anker);
        anker = deep_copy(orig.anker);
        return *this;
    }

    //Aufgabe 13.02 - desctructor
    ~MyString2() { loesche_alle(anker); }  

    //Aufgabe 13.05 length() methode
    unsigned int length() const
    {
        if (anker == nullptr)
        {
            return 0;
        }
        else
        {
            size_t counter = 0;
            CharListenKnoten *temp = anker;
            while (temp != nullptr)
            {
                counter++;
                temp = temp->get_next();
            }
            return counter;
        }
    }

    //Aufgabe 13.06 - At() method
    // char at(unsigned int pos) const
    // {
    //     if (anker == nullptr)
    //     {
    //         return '\0';
    //     }
    //     else
    //     {
    //         char c;
    //         CharListenKnoten *temp = anker;
    //         for (size_t i = 0; i <= pos; i++)
    //         {
    //             if (temp == nullptr)
    //             {
    //                 c = '\0';
    //                 break;
    //             }
    //             c = temp->get_data();
    //             temp = temp->get_next();
    //         }
    //         return c;
    //     }
    // }

    //Aufgabe 13.06 - at() method
    char at(unsigned int pos) const
    {

        if(anker == nullptr){
            return '\0';
        }

        CharListenKnoten *temp = anker;
        char c = '\0';

        for (size_t i = 0; i <= pos; i++)
        {
            if (temp == nullptr)
            {
                c = '\0';
                break;
            }

            if (i == pos)
            {
                c = temp->get_data();

            }

            temp = temp->get_next();
        }

        return c;
    }

    //Aufgabe 13.07 - to_string() method 
    std::string to_string() const
    {
        std::string s = "";
        if (anker == nullptr)
            return s;
        else
        {
            CharListenKnoten *temp = anker;
            while (temp != nullptr)
            {
                s += temp->get_data();
                temp = temp->get_next();
            }
            return s;
        }
    }

    //Aufgabe 13.08 - operator+() method 
    MyString2 operator+(char c) const
    {
        MyString2 new_string = *this;
        hinten_anfuegen(new_string.anker, c);
        return new_string;
    }
};