#pragma once
#include "MyRectangle.h"

class MyFramedRectangle : public MyRectangle {
    public:
        MyFramedRectangle(MyCanvas& canvas, unsigned int x1, unsigned int y1,unsigned int x2, unsigned int y2);

        void draw() override;
       

};