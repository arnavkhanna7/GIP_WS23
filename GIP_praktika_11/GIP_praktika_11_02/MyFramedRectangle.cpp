#include "MyFramedRectangle.h"

// Constructor
MyFramedRectangle::MyFramedRectangle(MyCanvas& canvas, unsigned int x1, unsigned int y1, unsigned int x2, unsigned int y2)
    : MyRectangle(canvas, x1, y1, x2, y2) {}

// Draw method
void MyFramedRectangle::draw() {
    // Draw the inner rectangle using the base class method
    MyRectangle::draw();

    // Draw the outer frame using '+'
    for (unsigned int x = get_x1(); x <= get_x2(); ++x) {
        canvas_ptr->set(x, get_y1(), '+');
        canvas_ptr->set(x, get_y2(), '+');
    }

    for (unsigned int y = get_y1(); y <= get_y2(); ++y) {
        canvas_ptr->set(get_x1(), y, '+');
        canvas_ptr->set(get_x2(), y, '+');
    }
}
