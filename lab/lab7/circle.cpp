#include "circle.h"


Circle::Circle(){
	this->radius = 0;
}


Circle::Circle(float radius){
	this->radius = radius;
}


Circle::~Circle(){}


float Circle::area(){
	return this->radius * this->radius * M_PI;
}


void Circle::display(){
	Shape::display();
	cout << "Area: " << this->area() << endl;
}


