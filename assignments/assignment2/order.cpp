/*********************************************************************
** Program Filename:order.cpp
** Author:	Lyon
** Date:	4/27/2020
** Description:	definitions for order
** Input:	n/a
** Output:	n/a
*********************************************************************/
#include <iostream>
#include <fstream>
#include <string.h>
#include <cstdlib>
#include "order.h"

using namespace std;


int Order::num_orders = 0;

/*********************************************************************
** Function:default constructor
** Description: initializes initial values
** Parameters: -
** Pre-Conditions:	-
** Post-Conditions:	-
*********************************************************************/ 
Order::Order(){
	cout << "ORDER DEFAULT CONSTRUCTOR CALLED" << endl;
	// this->num_orders = 0;
	this->order_num = 0;
	this->customer_name = "";
	this->customer_CC = "";
	this->Customer_phone = "";
	this->pizzas = NULL;
	this->num_pizzas = 0;
}

/*********************************************************************
** Function:deconstructor
** Description: deletes remaining memory
** Parameters: -
** Pre-Conditions:	-
** Post-Conditions:	-
*********************************************************************/ 
Order::~Order(){
	cout << "ORDER DECONSTRUCTOR CALLED" << endl;
	delete[] this->pizzas;
}

/*********************************************************************
** Function:	copy constructor 
** Description:	copies classes
** Parameters:	-
** Pre-Conditions:	-
** Post-Conditions:	-
*********************************************************************/ 
Order::Order(const Order& old_obj){
	cout << "ORDER COPY CONSTRUCTOR CALLED" << endl;
	this->order_num = old_obj.order_num;
	this->customer_name = old_obj.customer_name ;
	this->customer_CC = old_obj.customer_CC ;
	this->Customer_phone = old_obj.Customer_phone;
	this->num_pizzas = old_obj.num_pizzas;
	this->pizzas = new ordered_pizzas[old_obj.num_pizzas];
	for(int i = 0; i < old_obj.num_pizzas; ++i){
		this->pizzas[i].pizza_name = old_obj.pizzas[i].pizza_name;
		this->pizzas[i].size = old_obj.pizzas[i].size;
		this->pizzas[i].quantity = old_obj.pizzas[i].quantity;
	}
	cout << "COPY CONSTRUCTOR CALL ENDED" << endl;
}

/*********************************************************************
** Function:	Assignment Operator Overload
** Description:	assign a class to be another class
** Parameters:	-
** Pre-Conditions:	-
** Post-Conditions:	-
*********************************************************************/ 
Order& Order::operator=(const Order old_obj){
	cout << "ORDER AOO CALLED" << endl;
	this->order_num = old_obj.order_num;
	this->customer_name = old_obj.customer_name ;
	this->customer_CC = old_obj.customer_CC ;
	this->Customer_phone = old_obj.Customer_phone;
	this->num_pizzas = old_obj.num_pizzas;
	delete[] pizzas;
	this->pizzas = new ordered_pizzas[old_obj.num_pizzas];
	for(int i = 0; i < old_obj.num_pizzas; ++i){
		this->pizzas[i].pizza_name = old_obj.pizzas[i].pizza_name;
		this->pizzas[i].size = old_obj.pizzas[i].size;
		this->pizzas[i].quantity = old_obj.pizzas[i].quantity;
	}
}

/*********************************************************************
** Function:	get_num_orders
** Description:	return num_orders
** Parameters:	-
** Pre-Conditions:	-
** Post-Conditions:	get num_orders
*********************************************************************/ 
int Order::get_num_orders(){
	return this->num_orders;
}

/*********************************************************************
** Function:	get_order_num
** Description:	return order_num
** Parameters:	-
** Pre-Conditions:	-
** Post-Conditions:	get order_num
*********************************************************************/ 
int Order::get_order_num(){
	return this->order_num;
}

/*********************************************************************
** Function:	get_customer_name
** Description:	return customer_name
** Parameters:	-
** Pre-Conditions:	-
** Post-Conditions:	get customer_name
*********************************************************************/ 
string Order::get_customer_name(){
	return this->customer_name;
}

/*********************************************************************
** Function:	get_customer_CC
** Description:	return customer_CC
** Parameters:	-
** Pre-Conditions:	-
** Post-Conditions:	get customer_CC
*********************************************************************/ 
string Order::get_customer_CC(){
	return this->customer_CC;
}

/*********************************************************************
** Function:	get_customer_phone
** Description:	return customer_phone
** Parameters:	-
** Pre-Conditions:	-
** Post-Conditions:	get customer_phone
*********************************************************************/ 
string Order::get_customer_phone(){
	return this->Customer_phone;
}

/*********************************************************************
** Function:	get_get_pizzas
** Description:	return get_pizzas
** Parameters:	-
** Pre-Conditions:	-
** Post-Conditions:	get get_pizzas
*********************************************************************/ 
ordered_pizzas* Order::get_pizzas(){
	return this->pizzas;
}


int Order::get_num_pizzas(){
	return this->num_pizzas;
}


string Order::get_pizza_name(int i){
	return this->pizzas[i].pizza_name;
}


string Order::get_size(int i){
	return this->pizzas[i].size;
}


int Order::get_quantity(int i){
	return this->pizzas[i].quantity;
}


void Order::set_pizza_name(string pizza_name, int i){
	this->pizzas[i].pizza_name = pizza_name;
}


void Order::set_size(string size, int i){
	this->pizzas[i].size = size;
}


void Order::set_quantity(int quantity, int i){
	this->pizzas[i].quantity = quantity;
}



void Order::set_num_orders(int num_orders){
	this->num_orders = num_orders;
}


void Order::set_order_num(int order_num){
	this->order_num = order_num;
}


void Order::set_customer_name(string customer_name){
	this->customer_name = customer_name;
}


void Order::set_customer_CC(string customer_CC){
	this->customer_CC = customer_CC;
}


void Order::set_customer_phone(string Custcmer_phone){
	this->Customer_phone = Custcmer_phone;
}


void Order::set_pizzas(ordered_pizzas* pizzas, int count){
	cout << "SETTING PIZZA TO ORDER" << endl;
	this->num_pizzas = count;
	this->pizzas = pizzas;
}


void Order::set_num_pizzas(int num_pizzas){
	this->num_pizzas = num_pizzas;
}


void Order::load_additional_pizzas(ifstream& fin, string &temp){
	while(true){
		fin >> temp;
		if(!is_digits(temp)){
			this->upsize_pizzas();
			this->pizzas[this->num_pizzas-1].pizza_name = temp;
			fin >> this->pizzas[this->num_pizzas-1].size;
			fin >> temp;
			this->pizzas[this->num_pizzas-1].quantity = stoi(temp);
		}
		else{
			return;
		}
	}
}


void Order::set_from_file(ifstream& fin, string& temp){
	this->order_num = stoi(temp);
	fin >> this->customer_name >> this->customer_CC;
	fin >> this->Customer_phone;
	this->load_additional_pizzas(fin, temp);
	// ++this->num_orders;
}


void Order::upsize_pizzas(){
	if(this->num_pizzas == 0){
		this->num_pizzas++;
		this->pizzas = new ordered_pizzas[num_pizzas];
		return;
	}
	ordered_pizzas *temp = new ordered_pizzas[++this->num_pizzas];
	for(int i = 0; i < this->num_pizzas-1; ++i){
		temp[i].pizza_name = this->pizzas[i].pizza_name;
		temp[i].size = this->pizzas[i].size;
		temp[i].quantity = this->pizzas[i].quantity;
	}
	delete[] this->pizzas;
	this->pizzas = temp;
	temp = NULL;
}


bool is_digits(string str){
	if(str == ""){
		return false;
	}
	for(int i = 0; i < str.length(); ++i){
		if(str[i] < '0' || str[i] > '9'){
			return false;
		}
	}
	return true;
}


void Order::display_orders(){
		cout << "customer_name = " << this->customer_name << endl;
		cout << "customer_CC = " << this->customer_CC << endl;
		cout << "Customer_phone = " << this->Customer_phone << endl;
		for(int j = 0; j < this->num_pizzas; j++){
			cout << "Pizza " << j+1 << ": ";
			cout << this->pizzas[j].pizza_name << " ";
			cout << this->pizzas[j].size << " ";
			cout << this->pizzas[j].quantity << endl;;
		}
}


void Order::upsize_Orders(int cap){
    Order* temp = new Order[cap];
    for(int i = 0; i < this->num_orders; ++i){
        temp[i] = this[i];
    }
    // delete[] this->pizzas;
    // delete[] this;
    // this = temp;
    temp = NULL;
}