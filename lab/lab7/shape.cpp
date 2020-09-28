#include <iostream>
#include <string.h>
#include "shape.h"

Shape::Shape(){
	name = "";
	color = "";
}

Shape::~Shape(){};


string Shape::get_name() const{
	return this->name;
}


string Shape::get_color() const{
	return this->color;
}



void Shape::set_name(string name){
	this->name = name;
}


void Shape::set_color(string color){
	this->color = color;
}


// float Shape::area() const{
	// return 0;
// }


void Shape::display() const{
	
	cout << "Name: " << this->name << endl;
	cout << "Color: " << this->color << endl;
	cout << "Area: " << this->area() << endl;
}


void print_shape_info(Shape &s){
	cout << "Name: " << s.get_name() << endl;
	cout << "Color: " << s.get_color() << endl;
	cout << "Area: " << s.area() << endl;
}


bool operator>(const Shape &s1, const Shape &s2){
	if(s1.area() > s2.area())
		return true;
	return false;
}


bool operator<(const Shape &s1, const Shape &s2){
	if(s1.area() < s2.area())
		return true;
	return false;
}


