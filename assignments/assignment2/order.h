/*********************************************************************
** Program Filename:order.h
** Author:	Lyon
** Date:	4/27/2020
** Description:	headers for order
** Input:	n/a
** Output:	n/a
*********************************************************************/
#ifndef ORDER_H
#define ORDER_H

#include<string>
#include <fstream>

using namespace std;

struct ordered_pizzas{
	string pizza_name = "";
	string size = "";
	int quantity = 0;
};


class Order{
	static int num_orders;
	int order_num;
	string customer_name;
	string customer_CC;
	string Customer_phone;
	ordered_pizzas* pizzas; 
	int num_pizzas;
public:
	Order();
	~Order();
	Order(const Order&);
	Order& operator=(const Order);
	int get_num_orders();
	int get_order_num();
	string get_customer_name();
	string get_customer_CC();
	string get_customer_phone();
	ordered_pizzas* get_pizzas();
	int get_num_pizzas();
	string get_pizza_name(int i);
	string get_size(int i);
	int get_quantity(int i);


	void set_pizza_name(string, int i);
	void set_size(string, int i);
	void set_quantity(int, int i);
	void set_num_orders(int);
	void set_order_num(int);
	void set_customer_name(string);
	void set_customer_CC(string);
	void set_customer_phone(string);
	void set_pizzas(ordered_pizzas*, int);
	void set_num_pizzas(int);
	void load_additional_pizzas(ifstream&, string&);
	void set_from_file(ifstream&, string&);
	void upsize_pizzas();
	void display_orders();
	void upsize_Orders(int);
};


bool is_digits(string);
#endif