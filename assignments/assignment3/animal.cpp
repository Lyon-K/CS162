#include "animal.h"

using namespace std;

Animal::Animal(){
    this->age = 0;
    this->price = 0;
    this->births = 0;
    this->food_cost_percentage = 0;
    this->revenue = 0;
    this->cure_cost = 0;
    this->selling_price = 0;
}


Animal::Animal(const Animal& old_obj){
    // cout << "ANIMAL COPY CONSTRUCTOR CALLED" << endl;
    this->age = old_obj.age;
    this->price = old_obj.price;
    this->births = old_obj.births;
    this->food_cost_percentage = old_obj.food_cost_percentage;
    this->revenue = old_obj.revenue;
    this->cure_cost = old_obj.cure_cost;
    this->selling_price = old_obj.selling_price;
}


Animal& Animal::operator=(const Animal& old_obj){
    // cout << "ANIMAL AOO CALLED\n";
    this->age = old_obj.age;
    this->price = old_obj.price;
    this->births = old_obj.births;
    this->food_cost_percentage = old_obj.food_cost_percentage;
    this->revenue = old_obj.revenue;
    this->cure_cost = old_obj.cure_cost;
    this->selling_price = old_obj.selling_price;
}


Animal::~Animal(){
}


/*********************************************************************
** Function:         get_age()
** Description:      gets the called animal's age
** Parameters:       -
** Pre-Conditions:   called on an existing animal
** Post-Conditions:  returns the age of the called animal
*********************************************************************/
int Animal::get_age(){
    return this->age;
}


/*********************************************************************
** Function:         get_revenue()
** Description:      gets the called animal's revenue
** Parameters:       -
** Pre-Conditions:   called on an existing animal
** Post-Conditions:  returns the revenue of the called animal
*********************************************************************/
float Animal::get_revenue(){
    return this->revenue;
}


/*********************************************************************
** Function:         get_selling_price()
** Description:      gets the called animal's selling_price
** Parameters:       -
** Pre-Conditions:   called on an existing animal
** Post-Conditions:  returns the selling_price of the called animal
*********************************************************************/
float Animal::get_selling_price(){
    return this->selling_price;
}


/*********************************************************************
   ** Function:         increment_age()
   ** Description:      increment the called animal's age
   ** Parameters:       -
   ** Pre-Conditions:   called on an existing animal
   ** Post-Conditions:  increments the called animal's age by one
   *********************************************************************/
void Animal::increment_age(){
    ++this->age;
}

