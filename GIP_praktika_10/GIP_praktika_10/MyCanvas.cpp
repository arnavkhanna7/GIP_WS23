#include "MyCanvas.h"
#include <iostream>



MyCanvas::MyCanvas(unsigned int x, unsigned int y) : size_x(x), size_y(y), canvas_array_ptr(nullptr) {
    init();
}

MyCanvas::~MyCanvas() {
    delete[] canvas_array_ptr;
}

MyCanvas::MyCanvas(const MyCanvas& other) : size_x(other.size_x), size_y(other.size_y), canvas_array_ptr(nullptr) {
    init();
    for (unsigned int i = 0; i < size_x * size_y; ++i) {
        canvas_array_ptr[i] = other.canvas_array_ptr[i];
    }
}

MyCanvas& MyCanvas::operator=(const MyCanvas& other) {
    if (this != &other) {
        delete[] canvas_array_ptr;
        size_x = other.size_x;
        size_y = other.size_y;
        init();
        for (unsigned int i = 0; i < size_x * size_y; ++i) {
            canvas_array_ptr[i] = other.canvas_array_ptr[i];
        }
    }
    return *this;
}

unsigned int MyCanvas::get_size_x() const {
    return size_x;
}

unsigned int MyCanvas::get_size_y() const {
    return size_y;
}

char* MyCanvas::get_canvas_array_ptr() const {
    return canvas_array_ptr;
}

void MyCanvas::set_canvas_array_ptr(char* ptr) {
    canvas_array_ptr = ptr;
}

void MyCanvas::init() {
    canvas_array_ptr = new char[size_x * size_y];
    for (unsigned int i = 0; i < size_x * size_y; ++i) {
        canvas_array_ptr[i] = '.';
    }
}

void MyCanvas::set(unsigned int x, unsigned int y, char c)  {
    if (x < size_x && y < size_y) {
        canvas_array_ptr[y * size_x + x] = c;
    }
}

char MyCanvas::get(unsigned int x, unsigned int y) const {
    if (x < size_x && y < size_y) {
        return canvas_array_ptr[y * size_x + x];
    }
    return '\0'; // Out of bounds, return null character
}

std::string MyCanvas::to_string() const {
    std::string result;
    for (unsigned int y = 0; y < size_y; ++y) {
        for (unsigned int x = 0; x < size_x; ++x) {
            result += get(x, y);
        }
        result += '\n';
    }
    return result;
}

void MyCanvas::print() const {
    std::cout << to_string() << std::endl;
}
