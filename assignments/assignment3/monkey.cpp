#include "monkey.h"

using namespace std;

Monkey::Monkey(){
    this->age = 0;
    this->price = 15000;
    this->births = 1;
    this->food_cost_percentage = 4;
    this->revenue = 0.1 * this->price;
    this->cure_cost = 0.5 * this->price;
    this->selling_price = 0.5 * this->price;
}


Monkey::Monkey(string){
    this->age = 24;
    this->price = 15000;
    this->births = 1;
    this->food_cost_percentage = 4;
    this->revenue = 0.1 * this->price;
    this->cure_cost = 0.5 * this->price;
    this->selling_price = 0.5 * this->price;
}


Monkey::~Monkey(){

}