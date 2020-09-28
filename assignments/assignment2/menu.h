/*********************************************************************
** Program Filename:menu.h
** Author:  Lyon
** Date:    4/27/2020
** Description: deahers for menu
** Input:   n/a
** Output:  n/a
*********************************************************************/
#ifndef MENU_H
#define MENU_H 

#include <string>
#include <fstream>
#include "pizza.h"
#include "order.h"

using namespace std;

class Menu {
  private:
    int num_pizzas;
    Pizza* pizzas;
    int pizzas_cap;
  public:
    //need to include accessor functions and mutator functions for each private member
    //need to include constructors, copy constructors, assignment operator overload,
    //and destructors where appropriate
    Menu();
    ~Menu();
    Menu(const Menu&);
    Menu& operator=(const Menu&);


    int get_num_pizzas();
    Pizza* get_pizzas();
    // int get_pizzas_cap();

    void set_num_pizzas(int);
    void set_pizzas_cap(int);
    // Only one of the following two prototypes should be used:
    Menu search_pizza_by_cost(int upper_bound);
    //Menu search_pizza_by_cost(int upper_bound, string size);

    Menu search_pizza_by_ingredients_to_include(string* ingredients, int num_ingredients);
    Menu search_pizza_by_ingredients_to_exclude(string* ingredients, int num_ingredients);
    void add_to_menu(Pizza pizza_to_add);
    void remove_from_menu(int index_of_pizza_on_menu);

    void populate_pizzas(ifstream&);
    void display_pizzas(int);
    void display_pizzas();
    void print_results(int &index, int &count, int &i, int* arr);
    Order* display_results(int& n_orders);
    Order* evaluate_purchase(int* selection, int* quantity, int& n_orders);
    Order* get_results(int &n_orders, int* arr, int* selection, int* quantity, int& capacity);
};

#endif