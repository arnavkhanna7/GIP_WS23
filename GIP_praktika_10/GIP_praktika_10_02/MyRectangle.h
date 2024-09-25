#ifndef MYRECTANGLE_H
#define MYRECTANGLE_H

#include "MyCanvas.h"

class MyRectangle {
public:
    // Constructor
    MyRectangle(MyCanvas& canvas, unsigned int x1, unsigned int y1, unsigned int x2, unsigned int y2);

    // Getter methods
    unsigned int getX1() const;
    unsigned int getY1() const;
    unsigned int getX2() const;
    unsigned int getY2() const;

    // Setter methods
    void setX1(unsigned int x);
    void setY1(unsigned int y);
    void setX2(unsigned int x);
    void setY2(unsigned int y);

    // Draw method
    void draw();

protected:
    unsigned int x1;
    unsigned int y1;
    unsigned int x2;
    unsigned int y2;
    MyCanvas* canvas_ptr;
};

#endif // MYRECTANGLE_H
