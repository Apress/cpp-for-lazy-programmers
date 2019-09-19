//Circle class, for use with the SSDL library
//   -- from _C++ for Lazy Programmers_

#ifndef CIRCLE_H
#define CIRCLE_H

#include "shape.h"

class Circle: public Shape
{
 public:
    Circle () : radius_ (0)  {}
    Circle (const Circle& c) : Shape(c), radius_ (c.radius()) {}
    Circle (Circle&&      c) : Shape (std::move (c))
    { 
        radius_ = c.radius(); 
    }
    Circle (int x, int y, int theRadius, const char* txt="") : 
        Shape (x, y, txt), radius_ (theRadius) 
    {
    } 

    const Circle& operator= (const Circle& c) 
    {
        Shape::operator=(c);            radius_ = c.radius(); 
        return *this;
    }
    const Circle& operator= (Circle&&       c)
    {
        Shape::operator=(std::move(c)); radius_ = c.radius(); 
        return *this;
    }

    int radius () const { return radius_; }

    void drawAux() const override
    { 
        SSDL_RenderDrawCircle (location().x_, location().y_, radius()); 
    }

 private:
    int radius_; 
};

#endif
