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

	virtual string get_name() const;
	virtual string get_color() const;

	void set_name(string);
	void set_color(string);
	virtual float area() const = 0;
	virtual void display() const;

	friend bool operator>(const Shape &, const Shape &);
	friend bool operator<(const Shape &, const Shape &);

};
void print_shape_info(Shape &);


#endif