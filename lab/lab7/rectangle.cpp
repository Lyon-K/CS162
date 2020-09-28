#include "rectangle.h"


Rectangle::Rectangle() : Shape(){
	this->width = 0;
	this->height = 0;
}


Rectangle::Rectangle(float width, float height){
	this->width = width;
	this->height = height;
}


Rectangle::~Rectangle(){}

float Rectangle::get_width(){
	return this->width;
}


float Rectangle::get_height(){
	return this->height;
}


void Rectangle::set_width(float width){
	this->width = width;
}


void Rectangle::set_height(float height){
	this->height = height;
}


float Rectangle::area() const{
	cout << "calculating RECTANGLE AR`EA\n";
	return this->width*this->height;
}


void Rectangle::display(){
	cout << "RECTANGLE DISPLAY FUNCTION\n";
	Shape::display();
	cout << "Area: " << this->area() << endl;
}
