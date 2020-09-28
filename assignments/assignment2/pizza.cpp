#include <string>
#include <iostream>
#include <fstream>
#include "pizza.h"

using namespace std;


/*********************************************************************
** Function:default constructor
** Description: initializes initial values
** Parameters: -
** Pre-Conditions:  -
** Post-Conditions: -
*********************************************************************/ 
Pizza::Pizza(){
    // cout << "PIZZA DEFAULT CONSTRUCTOR CALLED\n";
    this->ingredient_count = 0;
    this->small_cost = 0;
    this->large_cost = 0;
    this->num_ingredients = 0;
    this->ingredients = NULL;
}

/*********************************************************************
** Function:deconstructor
** Description: deletes remaining memory
** Parameters: -
** Pre-Conditions:  -
** Post-Conditions: -
*********************************************************************/ 
Pizza::~Pizza(){
    // cout << "PIZZA DECONSTRUCTOR CALLED\n";
    if(this->ingredients != NULL){
        // cout << "ADDRESS DECONSTRUCTED " << ingredients << endl;
        delete[] this->ingredients;
    }
    this->ingredients = NULL;
}

/*********************************************************************
** Function:    copy constructor 
** Description: copies classes
** Parameters:  -
** Pre-Conditions:  -
** Post-Conditions: -
*********************************************************************/ 
Pizza::Pizza(const Pizza& old_obj){
    // cout << "PIZZA COPY CONSTRUCTOR CALLED\n";
    this->name = old_obj.name;
    this->small_cost = old_obj.small_cost;
    this->medium_cost = old_obj.medium_cost;
    this->large_cost = old_obj.large_cost;
    this->num_ingredients = old_obj.num_ingredients;
    this->ingredient_count = old_obj.ingredient_count;
    this->ingredients = new string[old_obj.num_ingredients];
    for(int i = 0; i < old_obj.num_ingredients; ++i){
        this->ingredients[i] = old_obj.ingredients[i];
    }
}

/*********************************************************************
** Function:    Assignment Operator Overload
** Description: assign a class to be another class
** Parameters:  -
** Pre-Conditions:  -
** Post-Conditions: -
*********************************************************************/ 
Pizza& Pizza::operator=(const Pizza old_obj){
    // cout << "PIZZA AOO CALLED\n";
    if(this != &old_obj){
        // cout << "PIZZA AOO RAN\n";
        this->name = old_obj.name;
        this->small_cost = old_obj.small_cost;
        this->medium_cost = old_obj.medium_cost;
        this->large_cost = old_obj.large_cost;
        this->num_ingredients = old_obj.num_ingredients;
        this->ingredient_count = old_obj.ingredient_count;
        if(this->ingredients != NULL)
            delete[] this->ingredients;
        this->ingredients = new string[old_obj.num_ingredients];
        for(int i = 0; i < old_obj.num_ingredients; ++i){
            this->ingredients[i] = old_obj.ingredients[i];
        }
    }
}


string Pizza::get_name() const{
    return this->name;
}


int Pizza::get_small_cost() const{
    return this->small_cost;
}


int Pizza::get_medium_cost() const{
    return this->medium_cost;
}


int Pizza::get_large_cost() const{
    return this->large_cost;
}


int Pizza::get_num_ingredients() const{
    return this->num_ingredients;
}


string* Pizza::get_ingredients() const{
    // for(int i = 0; i < this->num_ingredients; ++i){
    //     cout << i+1 << ": " << this->ingredients[i] << endl;
    // }
    return ingredients;
}

void Pizza::set_name(string str){
    this->name = str;
}


void Pizza::set_small_cost(int n){
    this->small_cost = n;
}

void Pizza::set_medium_cost(int n){
    this->medium_cost = n;
}


void Pizza::set_large_cost(int n){
    this->large_cost = n;
}


void Pizza::set_num_ingred(int n){
    this->num_ingredients = n;
}


void Pizza::set_num_ingredients(int n){
    if(n < 1 && this->name != ""){
        cout << "You cannot have less than 1 ingredients\n";
        return;
    }
    this->num_ingredients = n;
    this->ingredients = new string[n];
}


void Pizza::allocate_ingredients(int size){
    delete[] this->ingredients;
    this->ingredients = new string[size];
}


void Pizza::set_ingredients(string ingred, int i){
    this->ingredients[i] = ingred;
}


void Pizza::set_ingredients(string ingredient){
    if(this->ingredient_count < this->num_ingredients){
        this->ingredients[this->ingredient_count] = ingredient;
        this->ingredient_count++;
        return;
    }
    cout << "Max ingredients reached\n";
}


void Pizza::set_from_file(ifstream& fin){
    int temp = 0;
    fin >> this->name;
    fin >> this->small_cost;
    fin >> this->medium_cost;
    fin >> this->large_cost;
    fin >> temp;
    set_num_ingredients(temp);
    for(int i = 0; i < num_ingredients; ++i){
        string ingred;
        fin >> ingred;
        this->set_ingredients(ingred);
    }
}


void Pizza::print_cost(){
    if(this->small_cost == -1)
        cout << "N/A ";
    else
        cout << this->small_cost << " ";

    if(this->medium_cost == -1)
        cout << "N/A ";
    else
        cout << this->medium_cost << " ";
    
    if(this->large_cost == -1)
        cout << "N/A ";
    else
        cout << this->large_cost << " ";
}

void Pizza::display_pizza(){
    // cout << "Name: " << this->name << endl;
    // cout << "small_cost: " << this->small_cost << endl;
    // cout << "medium_cost: " << this->medium_cost << endl;
    // cout << "large_cost: " << this->large_cost << endl;
    // cout << "num_ingredients: " << this->num_ingredients << endl;
    // for(int i = 0; i < this->num_ingredients; ++i){
    //     cout << i+1 << ": " << this->ingredients[i] << endl;
    cout << this->name << " ";
    this->print_cost();
    cout << this->num_ingredients << " ";
    for(int i = 0; i < this->num_ingredients; ++i){
        cout << this->ingredients[i] << " ";
    }
    cout << endl;
}

