#include "sloth.h"

using namespace std;

Sloth::Sloth(){
    this->age = 0;
    this->price = 2000;
    this->births = 5;
    this->food_cost_percentage = 1;
    this->revenue = 0.05 * this->price;
    this->cure_cost = 0.5 * this->price;
    this->selling_price = 0.5 * this->price;
}


Sloth::Sloth(string){
    this->age = 24;
    this->price = 2000;
    this->births = 5;
    this->food_cost_percentage = 1;
    this->revenue = 0.05 * this->price;
    this->cure_cost = 0.5 * this->price;
    this->selling_price = 0.5 * this->price;

}


Sloth::~Sloth(){

}