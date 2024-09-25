#pragma once

#include "MyCanvas.h"

class MyRectangle {
public:
    // Constructor
    MyRectangle(MyCanvas& canvas, unsigned int x1, unsigned int y1, unsigned int x2, unsigned int y2);

    // Operator* method 
    MyRectangle operator*(unsigned int factor) const;

    // Getter methods
    unsigned int get_x1() const;
    unsigned int get_y1() const;
    unsigned int get_x2() const;
    unsigned int get_y2() const;

    // Setter methods
    void set_x1(unsigned int x);
    void set_y1(unsigned int y);
    void set_x2(unsigned int x);
    void set_y2(unsigned int y);

    // Draw method
    virtual void draw();

protected:
    unsigned int x1;
    unsigned int y1;
    unsigned int x2;
    unsigned int y2;
    MyCanvas* canvas_ptr;
};

