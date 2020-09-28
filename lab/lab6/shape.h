#ifndef SHAPE_H
#define SHAPE_H

#include <iostream>
#include <string.h>
using namespace std;

class Shape{
protected:
	string name;
	string color;
public:
	Shape();
	~Shape();

	string get_name();
	string get_color();

	void set_name(string);
	void set_color(string);
	float area();
	void display();
};


#endif