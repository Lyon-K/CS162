#ifndef RECTANGLE_H
#define RECTANGLE_H

#include "shape.h"
using namespace std;

class Rectangle: public Shape{
	float width;
	float height;
public:
	Rectangle();
	Rectangle(float, float);
	~Rectangle();

	float get_width();
	float get_height();
	void set_width(float);
	void set_height(float);
	float area();
	void display();
};


#endif