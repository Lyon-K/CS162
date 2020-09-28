#include "moss_piglets.h"

using namespace std;

Moss_piglets::Moss_piglets(){
    this->age = 0;
    this->price = 1000000;
    this->births = 100;
    this->food_cost_percentage = 10;
    this->revenue = 0.05 * this->price;
    this->cure_cost = 0.5 * this->price;
    this->selling_price = 0.5 * this->price;
}


Moss_piglets::Moss_piglets(string){
    this->age = 24;
    this->price = 1000000;
    this->births = 100;
    this->food_cost_percentage = 10;
    this->revenue = 0.05 * this->price;
    this->cure_cost = 0.5 * this->price;
    this->selling_price = 0.5 * this->price;
}


Moss_piglets::~Moss_piglets(){

}