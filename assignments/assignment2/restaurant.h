/*********************************************************************
** Program Filename:restaurant.h
** Author:  Lyon
** Date:    4/27/2020
** Description: headers for restaurant
** Input:   n/a
** Output:  n/a
*********************************************************************/
#ifndef RESTAURANT_H
#define RESTAURANT_H

#include <string>
#include <fstream>
#include "menu.h"
#include "emp_hours.h"
#include "order.h"

using namespace std;

class Restaurant {
  private:
    Order *orders;
    Menu menu;
    int num_employee;
    int employee_logedin;
    employee* employees;
    hours* week;
    string name;
    string phone;
    string address;
  public:
    //need to include accessor functions and mutator functions for each private member
    //need to include constructors, copy constructors, assignment operator overload,
    Restaurant();
    ~Restaurant();
    Restaurant(const Restaurant&);
    Restaurant& operator=(const Restaurant);
    //and destructors where appropriate
    void main_menu();
    void customer_menu();
    void Employee_menu();
    bool employee_selection();
    string get_name();
    void set_name(string);
    void set_phone(string);
    void set_address(string);
    void load_pizza(ifstream &fin);
    void load_employee(ifstream&);
    void load_data(); //reads from files to correctly populate menu, employees, hours, etc.
    bool login(string id, string password);
    void view_menu();
    void view_hours();
    void view_address();
    void view_phone();
    void display_results(int&, Menu);
    void search_menu_by_price();
    void display_include(string* including, int &num_including);
    void display_exclude(string* excluding, int &num_excluding);
    bool include_ingredients_from_usr(string*, int&);
    bool exclude_ingredients_from_usr(string*, int&);
    void evaluate_include_exclude_ingredients(string*, int&, string*, int&);
    void search_by_ingredients();
    
    // Only one of the following two prototypes should be used:
    // selection is a dynamically allocated array of Pizza objects that are being ordered
    // selection_size indicates the number of Pizza objects in the array
    // num_ordered is a dynamically allocated array that indicates how many pizzas of each type were ordered
    void place_order(string* selection, int selection_size, int* num_ordered, string* piz_size);
    // you may also choose to use this prototype:
    //void place_order(Pizza* selection);
    void add_to_menu_ingredients(int);
    void change_hours();
    void add_to_menu_ingredients();
    void add_to_menu();
    void remove_from_menu();
    void upsize_Orders();
    void add_to_orders(Order* order_to_add, int num_orders = 1);
    void view_orders();
    void remove_orders();
    void populate_week(ifstream&);
    void load_restaurant(ifstream&);
    // void load_employee(ifstream&);
    void display_employee();
    void resize_employee(int&);
    void load_orders(ifstream&);
    void customer_order(Menu);
    void store_pizza(Menu men, string , string* , int& , int* , string*);
};

void upsize_string(string*, int&);
#endif