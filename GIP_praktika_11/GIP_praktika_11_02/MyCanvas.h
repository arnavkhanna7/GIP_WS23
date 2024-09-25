// Datei: MyCanvas.h

#pragma once

#include "gip_mini_catch_heap_delete.h"

// In dieser Headerdatei:
// Deklaration der Klasse MyCanvas
// Zu UEbungszwecken dieses Mal ausnahmsweise alle (!) Methodenruempfe
// in der .cpp Datei definieren.
// Auch fuer die Methoden mit kurzen Rümpfen 
// (kurze Konstruktoren, Setter, Getter, ...),
// die man normalerweise komplett in der Headerdatei 
// definieren wuerde ...

class MyCanvas {
public:
    // Default constructor declaration
    MyCanvas(unsigned int x = 0, unsigned int y = 0);

    // Destructor
    ~MyCanvas();

    // Copy constructor
    MyCanvas(const MyCanvas& other);

    // Copy assignment operator
    MyCanvas& operator=(const MyCanvas& other);

    // Getter methods
    unsigned int get_size_x() const;
    unsigned int get_size_y() const;
    char* get_canvas_array_ptr() const;

    // Setter method
    void set_canvas_array_ptr(char* ptr);

    // Other methods
    void init();
    void set(unsigned int x, unsigned int y, char c) const;
    char get(unsigned int x, unsigned int y) const;
    std::string to_string() const;
    void print() const;
    void draw_rectangle(unsigned int x1, unsigned int y1, unsigned int x2, unsigned int y2);

private:
    unsigned int size_x;
    unsigned int size_y;
    char* canvas_array_ptr;
};

