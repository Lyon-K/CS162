#include "sea_otter.h"

using namespace std;

Sea_otter::Sea_otter(){
    this->age = 0;
    this->price = 5000;
    this->births = 2;
    this->food_cost_percentage = 2;
    this->revenue = 0.05 * this->price;
    this->cure_cost = 0.5 * this->price;
    this->selling_price = 0.5 * this->price;
}


Sea_otter::Sea_otter(string lul){
    this->age = 24;
    this->price = 5000;
    this->births = 2;
    this->food_cost_percentage = 2;
    this->revenue = 0.05 * this->price;
    this->cure_cost = 0.5 * this->price;
    this->selling_price = 0.5 * this->price;
}


Sea_otter::~Sea_otter(){
}