/*********************************************************************
** Program Filename:pizza.h
** Author:  Lyon
** Date:    4/27/2020
** Description: headers for pizza
** Input:   n/a
** Output:  n/a
*********************************************************************/
#ifndef PIZZA_H
#define PIZZA_H

#include <string>
#include <fstream>

using namespace std;

class Pizza {
  private:
    string name;
    int small_cost;
    int medium_cost;
    int large_cost;
    int num_ingredients;
    int ingredient_count;
    string* ingredients;
  public:
    //need to include accessor functions and mutator functions for each private member
    //need to include constructors, copy constructors, assignment operator overload,
    //and destructors where appropriate
    Pizza();
    ~Pizza();
    Pizza(const Pizza&);
    Pizza& operator=(const Pizza);

    string get_name() const;
    int get_small_cost() const;
    int get_medium_cost() const;
    int get_large_cost() const;
    int get_num_ingredients() const;
    string* get_ingredients() const;

    void set_name(string);
    void set_small_cost(int);
    void set_medium_cost(int);
    void set_large_cost(int);
    void set_num_ingred(int n);
    void set_num_ingredients(int);
    void allocate_ingredients(int);
    void set_ingredients(string, int);
    void set_ingredients(string);
    void set_from_file(ifstream&);

/*ONLY FOR TESTING, DELETE BEFORE SUBMISSION*/
    void print_cost();
    void display_pizza();
};

#endif