#include "MyRectangle.h"

// Constructor
MyRectangle::MyRectangle(MyCanvas& canvas, unsigned int x1, unsigned int y1, unsigned int x2, unsigned int y2)
    : x1(x1), y1(y1), x2(x2), y2(y2), canvas_ptr(&canvas) {}

// Getter methods
unsigned int MyRectangle::getX1() const {
    return x1;
}

unsigned int MyRectangle::getY1() const {
    return y1;
}

unsigned int MyRectangle::getX2() const {
    return x2;
}

unsigned int MyRectangle::getY2() const {
    return y2;
}

// Setter methods
void MyRectangle::setX1(unsigned int x) {
    x1 = x;
}

void MyRectangle::setY1(unsigned int y) {
    y1 = y;
}

void MyRectangle::setX2(unsigned int x) {
    x2 = x;
}

void MyRectangle::setY2(unsigned int y) {
    y2 = y;
}

// Draw method
void MyRectangle::draw() {
    canvas_ptr->draw_rectangle(x1, y1, x2, y2);
}

