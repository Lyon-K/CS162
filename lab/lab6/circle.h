#ifndef CIRCLE_H
#define CIRCLE_H

#include <math.h>
#include "shape.h"
using namespace std;

class Circle: public Shape{
	float radius;
public:
	Circle();
	Circle(float);
	~Circle();
	float area();
	void display();
};

#endif