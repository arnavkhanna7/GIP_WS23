#include "CharListenKnoten.h"
int CharListenKnoten::next_available_id = 1;
int CharListenKnoten::object_count = 0;

void hinten_anfuegen(CharListenKnoten *&anker, const char wert)
{
    CharListenKnoten *new_entry = new CharListenKnoten{wert};
    if (anker == nullptr)
        anker = new_entry;
    else
    {
        //go through the list till last node
        CharListenKnoten *aktuellerKnoten = anker;
        while (aktuellerKnoten->get_next() != nullptr)
        {
            aktuellerKnoten = aktuellerKnoten->get_next();
        }
        aktuellerKnoten->set_next(new_entry);
    }
}

void loesche_alle(CharListenKnoten *&anker)
{
    if (anker == nullptr)
        return;

    while (anker != nullptr) {
        CharListenKnoten* temp = anker;     
        anker = anker->get_next();          // set anker to next node 
        delete temp;                        // delete the temp node
    }

    // anker auf nullptr setzen, da die Liste jetzt leer ist
    anker = nullptr;
}

CharListenKnoten *deep_copy(CharListenKnoten *orig)
{
    if (orig == nullptr)
    {
        CharListenKnoten *result = nullptr;
        return result;
    }
    else
    {
        CharListenKnoten *result = nullptr;
        while (orig != nullptr)
        {
            hinten_anfuegen(result, orig->get_data());
            orig = orig->get_next();
        }
        return result;
    }
}