#include "square.h"

Square::Square(): Rectangle(){
	set_width(0);
	set_height(0);
}


Square::Square(float length){
	set_width(length);
	set_height(length);
}


Square::~Square(){}


float Square::area(){
	return this->get_width() * this->get_height();
}


void Square::display(){
	Shape::display();
	cout << "Area: " << this->area() << endl;
}
