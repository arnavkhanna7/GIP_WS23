// Datei: liste.cpp

#include <string>
#include "liste.h"

std::string liste_als_string(TListenKnoten* anker)
{
    std::string resultat = "";

    if (anker == nullptr) {
        return "Leere Liste.";
    }
    else
    {
        resultat += "[ ";
        TListenKnoten* ptr = anker;
        do
        {
            resultat += std::to_string(ptr->data);

            if (ptr->next != nullptr) { resultat += " , "; }
            else { resultat += " "; }

            ptr = ptr->next;
        } while (ptr != nullptr);
        resultat += "]";
    }
    return resultat;
}

// Wird modifiziert in Aufgabe INF-08.01 ...
void hinten_anfuegen(TListenKnoten *&anker, const int wert)
{
    TListenKnoten *neuer_eintrag = new TListenKnoten;
    neuer_eintrag->data = wert;
    neuer_eintrag->next = nullptr;
    neuer_eintrag->prev = nullptr;

    if (anker == nullptr) {
        anker = neuer_eintrag;
    }
    else
    {
        TListenKnoten *ptr = anker;
        while (ptr->next != nullptr) {
            ptr = ptr->next;
        }
        neuer_eintrag->prev = ptr;
        ptr->next = neuer_eintrag;
    }
}

std::string liste_als_string_rueckwaerts(TListenKnoten* anker){
  std::string result;

    if (anker == nullptr) {
        return "Leere Liste.";
    }else{
        result += "[ ";

    // Gehe bis zum Ende der Liste
    TListenKnoten* ptr = anker;
    while (ptr != nullptr && ptr->next != nullptr) {
        ptr = ptr->next;
    }

    // go backwards through the list and append
    while (ptr != nullptr) {
        //use to string to add to list
        result += std::to_string(ptr->data);

        if(ptr->prev != nullptr){
            result += " , ";
        }

        ptr = ptr->prev;
    }
    result+= " ]";

    }
    return result;

}

void in_liste_einfuegen(TListenKnoten* &anker, int wert_neu,int vor_wert){
    TListenKnoten* neuer_eintrag = new TListenKnoten;
    neuer_eintrag->data = wert_neu;
    neuer_eintrag->next = nullptr;
    neuer_eintrag->prev = nullptr;

    if(anker == nullptr){
        anker = neuer_eintrag;
        return;
    }

    TListenKnoten *ptr = anker;

    // Suche die Stelle vor_wert in der Liste
    while (ptr != nullptr && ptr->data != vor_wert) {
        ptr = ptr->next;
    }

    // Füge den neuen Eintrag vor der Stelle vor_wert ein
    if (ptr != nullptr) {
        neuer_eintrag->next = ptr;

        if (ptr->prev != nullptr) {
            // Update the previous node's next pointer
            ptr->prev->next = neuer_eintrag;
            neuer_eintrag->prev = ptr->prev;
        } else {
            // The new entry is now the new head of the list
            anker = neuer_eintrag;
        }

        ptr->prev = neuer_eintrag;
    } else {
        // vor_wert nicht gefunden, füge am Ende der Liste ein
        hinten_anfuegen(anker, wert_neu);
    }
}

void aus_liste_loeschen(TListenKnoten* &anker, int wert){
    if(anker == nullptr){
        return;
    }

    TListenKnoten* ptr = anker;

    //suche den ersten knoten mit dem wert
    while(ptr != nullptr && ptr-> data != wert){
        ptr = ptr->next;
    }

    if(ptr == nullptr){
        //wert nicht gefunden , nichts loeschen
        return;
    }

    if(ptr->prev != nullptr){
        //der knoten ist nicht der kopf der liste
        ptr->prev->next = ptr->next;
    }else{
        //knoten ist kopf der liste
        anker = ptr->next;
    }

    if(ptr->next != nullptr){
        //der Knoten ist nicht das ende der liste 
        ptr->next->prev = ptr->prev; 
    }
    
    //loesche den gefundenen pointer
    delete ptr;
    

}


void practice_einfuegen(TListenKnoten* &anker, int wert_neu, int vor_wert){
    TListenKnoten* neuer_eintrag = new TListenKnoten;
    neuer_eintrag -> data = wert_neu;
    neuer_eintrag -> next = nullptr;
    neuer_eintrag -> prev = nullptr;

    if(anker == nullptr){
        anker->next = nullptr;
        anker->data = wert_neu;
    }else{

        TListenKnoten* ptr = anker;
        while(ptr-> next != nullptr && ptr -> data != vor_wert)
            ptr = ptr->next;
        if(ptr->data == vor_wert){
            if(ptr == anker){
                anker = neuer_eintrag;
            }else{
                ptr->prev->next = neuer_eintrag;
                neuer_eintrag->prev = ptr->prev;
            }

            ptr->prev = neuer_eintrag;
            neuer_eintrag->next = ptr;
        }
        else{
            ptr->next = neuer_eintrag;
            neuer_eintrag->prev = ptr;
        }
    }
}