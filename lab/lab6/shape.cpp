#include <iostream>
#include <string.h>
#include "shape.h"

Shape::Shape(){
	name = "";
	color = "";
}

Shape::~Shape(){};


string Shape::get_name(){
	return this->name;
}


string Shape::get_color(){
	return this->color;
}



void Shape::set_name(string name){
	this->name = name;
}


void Shape::set_color(string color){
	this->color = color;
}


float Shape::area(){
	return 0;
}

void Shape::display(){
	cout << "Name: " << this->name << endl;
	cout << "Color: " << this->color << endl;
}

