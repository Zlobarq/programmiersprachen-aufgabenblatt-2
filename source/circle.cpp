#include <cmath>
#include "circle.hpp"
#include "Vec2.hpp"
#include "color.hpp"
#include "mat2.hpp"

Circle::Circle():
    center_(0.0f, 0.0f),
    radius_(1.0f),
    color_(0.0f, 0.0f, 0.0f){}


Circle::Circle(Vec2 const& c, float r):
    center_(c),
    radius_(r),
    color_(0.0f, 0.0f, 0.0f){}

Circle::Circle(Vec2 const& a, float r, Color const& c):
    center_(a),
    radius_(r),
    color_(c){}

Vec2 Circle::getCenter() const {
	return center_;
}

float Circle::getRadius() const {
	return radius_;
}

Color Circle::getColor() const {
	return color_;
}

float Circle::circumference() const {
	return M_PI*radius_*2;
}

void Circle::draw(Window const& w){
	Vec2 rad1{radius_, 0.0f};
	Vec2 rad2{rad1}; 
	Mat2 m = make_rotation_mat2(M_PI/180);
    for (float i = 1; i<=360; i++){
        rad1 += center_;
        rad2 = m*rad2;
        rad2 += center_;
        w.draw_line(rad1.x_,rad1.y_,rad2.x_,rad2.y_,color_.r_,color_.g_,color_.b_);
        rad2 -= center_;
        rad1 = rad2;
    }	
}


void Circle::draw(Window const& w, Color const& color){
	Vec2 rad1{radius_, 0.0f};
	Vec2 rad2{rad1}; 
	Mat2 m = make_rotation_mat2(M_PI/180);
    for (float i = 1; i<=360; i++){
        rad1 += center_;
        rad2 = m*rad2;
        rad2 += center_;
        w.draw_line(rad1.x_,rad1.y_,rad2.x_,rad2.y_,color.r_,color.g_,color.b_);
        rad2 -= center_;
        rad1 = rad2;
    }	
}

bool Circle::isInsideCirc (Vec2 const& p)const{
	float xcenter=getCenter().x_;
	float ycenter=getCenter().y_;
	float rad=getRadius();
	float a = p.x_-xcenter;
	float b = p.y_-ycenter;
	if(sqrt(pow(a, 2)+pow(b, 2))<rad){
		return true;
	}else return false;
} 