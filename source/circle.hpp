#ifndef CIRCLE_HPP
#define CIRCLE_HPP

#include "Vec2.hpp"
#include "color.hpp"
#include "window.hpp"
#include <cmath>
#include <cstdlib>


class Circle{

public:
    Circle();
    Circle(Vec2 const& c, float r);
    Circle(Vec2 const& a, float r, Color const& c);

    Vec2 getCenter() const;
    float getRadius() const;
    Color getColor() const;
    float circumference() const;
   
    void draw(Window const& w);
    void draw(Window const& w, Color const& col);
   
    bool isInsideCirc(Vec2 const& p)const;

private:
    Vec2 center_;
    float radius_;
    Color color_;
};

#endif

