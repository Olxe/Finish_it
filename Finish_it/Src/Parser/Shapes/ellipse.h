#ifndef __ELLIPSE__
#define __ELLIPSE__

#include "shape.h"

class Ellipse: public Shape
{
public:
    Ellipse(float x, float y, float width, float height);
    ~Ellipse();

};

#endif