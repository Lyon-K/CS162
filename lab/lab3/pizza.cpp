#include <string>
#include <iostream>
#include <fstream>
#include "pizza.h"

using namespace std;



Pizza::Pizza(){
    cout << "Default constructor\n";
    this->count = 0;
    this->small_cost = 0;
    this->large_cost = 0;
    this->num_ingredients = 0;
    this->ingredients = NULL;
}


Pizza::~Pizza(){
    cout << "Destructor called\n";
    delete[] this->ingredients;
    this->ingredients = NULL;
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
    for(int i = 0; i < this->num_ingredients; ++i){
        cout << i+1 << ": " << this->ingredients[i] << endl;
    }
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


void Pizza::set_num_ingredients(int n){
    if(n < 1){
        cout << "You cannot have less than 1 ingredients\n";
        return;
    }
    this->num_ingredients = n;
    this->ingredients = new string[n];
}


void Pizza::set_ingredients(string ingredient){
    if(this->count < this->num_ingredients){
        this->ingredients[this->count] = ingredient;
        this->count++;
        return;
    }
    cout << "Max ingredients reached\n";
}


void Pizza::set_from_file(ifstream& fin){
    int temp;
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


void Pizza::display_pizza(){
    cout << "Name: " << this->name << endl;
    cout << "small_cost: " << this->small_cost << endl;
    cout << "medium_cost: " << this->medium_cost << endl;
    cout << "large_cost: " << this->large_cost << endl;
    cout << "num_ingredients: " << this->num_ingredients << endl;
    for(int i = 0; i < this->num_ingredients; ++i){
        cout << i+1 << ": " << this->ingredients[i] << endl;
    }
}
