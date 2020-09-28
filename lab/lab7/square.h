#ifndef SQUARE_H
#define SQUARE_H

#include "rectangle.h"
using namespace std;

class Square: public Rectangle{
public:
	Square();
	Square(float);
	~Square();
	float area();
	void display();
};

#endif