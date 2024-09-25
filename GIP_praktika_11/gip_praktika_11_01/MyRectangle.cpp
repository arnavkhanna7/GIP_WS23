#include "MyRectangle.h"

// Constructor
MyRectangle::MyRectangle(MyCanvas& canvas, unsigned int x1, unsigned int y1, unsigned int x2, unsigned int y2)
    : x1(x1), y1(y1), x2(x2), y2(y2), canvas_ptr(&canvas) {}

//Operator * method 
MyRectangle MyRectangle::operator*(unsigned int i) const{
    unsigned int new_x2 = x1 + (x2-x1)*i;
    unsigned int new_y2 = y1 + (y2-y1)*i;

    return MyRectangle(*canvas_ptr,x1,y1,new_x2,new_y2);
}

// Getter methods
unsigned int MyRectangle::get_x1() const {
    return x1;
}

unsigned int MyRectangle::get_y1() const {
    return y1;
}

unsigned int MyRectangle::get_x2() const {
    return x2;
}

unsigned int MyRectangle::get_y2() const {
    return y2;
}

// Setter methods
void MyRectangle::set_x1(unsigned int x) {
    x1 = x;
}

void MyRectangle::set_y1(unsigned int y) {
    y1 = y;
}

void MyRectangle::set_x2(unsigned int x) {
    x2 = x;
}

void MyRectangle::set_y2(unsigned int y) {
    y2 = y;
}

// Draw method
void MyRectangle::draw() {
    canvas_ptr->draw_rectangle(x1, y1, x2, y2);
}

