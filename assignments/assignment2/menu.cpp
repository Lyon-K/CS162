/*********************************************************************
** Program Filename:menu.cpp
** Author:	Lyon
** Date:	4/27/2020
** Description:	definitions for menu
** Input:	n/a
** Output:	n/a
*********************************************************************/
#include <iostream>
#include <fstream>
#include <string.h>
#include "menu.h"

using namespace std;

Menu::Menu(){
	cout << "MENU DEFAULT CONSTRUCTOR CALLED\n";
	this->num_pizzas = 0;
	this->pizzas_cap = 0;
	this->pizzas = NULL;
}


Menu::~Menu(){
	cout << "MENU DECONSTRUCTOR CALLED\n";
	delete[] this->pizzas;
}


Menu::Menu(const Menu& old_obj){
	cout << "MENU COPY CONSTRUCTOR CALLED\n";
    this->num_pizzas = old_obj.num_pizzas;
    this->pizzas = new Pizza[old_obj.pizzas_cap];
    for(int i = 0; i < this->num_pizzas; ++i){
    	this->pizzas[i] = old_obj.pizzas[i];
    }
    this->pizzas_cap = old_obj.pizzas_cap;
}


Menu& Menu::operator=(const Menu& old_obj){
	cout << "MENU AOO CALLED\n";
    this->num_pizzas = old_obj.num_pizzas;
    delete[] this->pizzas;
    this->pizzas = new Pizza[old_obj.pizzas_cap];
    for(int i = 0; i < this->num_pizzas; ++i){
    	this->pizzas[i] = old_obj.pizzas[i];
    }
    this->pizzas_cap = old_obj.pizzas_cap;
}


int Menu::get_num_pizzas(){
	return this->num_pizzas;
}


Pizza* Menu::get_pizzas(){
	if(this->pizzas != NULL)
		return this->pizzas;
	cout << "INVALID GET PIZZAS\n";
}


// int Menu::get_pizzas_cap(){
//  return this->pizzas_cap;
// }


void Menu::set_num_pizzas(int num){
	if(num < 0){
		cout << "NUMBER OF PIZZA IS INVALID\n";
		return;
	}
	while(this->pizzas_cap < num){
		// cout << "RESIZED PIZZAS CAPACITY\n";
		set_pizzas_cap(this->pizzas_cap * 2);
	}
	// cout << "ADDRESS OF PIZZA AFTER FUNC IS " << this->pizzas << endl;
	this->num_pizzas = num;
}

//TEST DELETE[] THIS->PIZZAS IF IT IS NEEDED OR IF IT IS NOT SINCE IT WILL BE DECONSTRUCTEDDDDDDDDDDDDDDDDDDDDD
void Menu::set_pizzas_cap(int cap){
	cout << "METHOD IF SET_PIZZAS_CAPPPP " << endl;
	if(this->pizzas_cap == 0){
		this->pizzas = new Pizza[1];
		pizzas_cap = 1;
		return;
	}
	Pizza* temp = new Pizza[cap];
	for(int i = 0; i < this->num_pizzas; ++i){
		temp[i] = this->pizzas[i];
	}
	delete[] this->pizzas;
	this->pizzas = temp; //temp address gets deleted after this function???
	// temp = NULL;
	this->pizzas_cap = cap;
}


Menu Menu::search_pizza_by_cost(int upper_bound){
	Menu searched = *this;
	for(int i = this->num_pizzas-1; i >= 0; --i){
		if(this->pizzas[i].get_small_cost() > upper_bound){
			searched.remove_from_menu(i); 
		}
		else if(this->pizzas[i].get_medium_cost() > upper_bound){
			searched.pizzas[i].set_medium_cost(-1);
			searched.pizzas[i].set_large_cost(-1);
		}
		else if(this->pizzas[i].get_large_cost() > upper_bound){
			searched.pizzas[i].set_large_cost(-1);
		}
	}
	return searched;
}


//Menu search_pizza_by_cost(int upper_bound, string size);

Menu Menu::search_pizza_by_ingredients_to_include(string* ingredients, int num_ingredients){
	Menu searched = *this;

}


Menu Menu::search_pizza_by_ingredients_to_exclude(string* ingredients, int num_ingredients){

}


void Menu::add_to_menu(Pizza pizza_to_add){
	if(this->num_pizzas == 0 || this->pizzas_cap == 0){
		cout << "Please allocate number of pizzas first\n";
		return;
	}
	this->set_num_pizzas(this->get_num_pizzas() + 1);
	this->pizzas[get_num_pizzas() - 1] = pizza_to_add;
}


void Menu::remove_from_menu(int index_of_pizza_on_menu){
	if(index_of_pizza_on_menu >= num_pizzas || index_of_pizza_on_menu < 0){
		cout << "Unable to remove non-existant pizza\n";
		return;
	}
	--this->num_pizzas;
	cout << "Removed " << this->pizzas[index_of_pizza_on_menu].get_name() << endl;
	for(int i = index_of_pizza_on_menu; i < this->num_pizzas; ++i){
		this->pizzas[i] = this->pizzas[i+1];
	}
}


void Menu::populate_pizzas(ifstream& fin){
	while(!fin.eof()){
		this->set_num_pizzas(this->get_num_pizzas() + 1);
		this->pizzas[get_num_pizzas() - 1].set_from_file(fin);
		if(this->pizzas[get_num_pizzas() - 1].get_name() == ""){
			this->set_num_pizzas(this->get_num_pizzas() - 1);
		}
		fin.get();
	}
	fin.close();
	cout << "Menu.txt CLOSED\n";
}


void Menu::display_pizzas(int n){
	// cout << "DISPLAYING PIZZASSSSS" << endl;
	this->pizzas[n].display_pizza();
}


void Menu::display_pizzas(){
	// cout << "DISPLAYING all pizzas" << endl;
	for(int i = 0; i < this->num_pizzas; ++i){
		this->pizzas[i].display_pizza();
		cout << endl;
	}
}


void Menu::print_results(int &index, int &count, int &i, int* arr){
		if(this->pizzas[i].get_small_cost() != -1){
			cout << "(" << count << ")\tSmall " << this->pizzas[i].get_name()
				<< " - $" << this->pizzas[i].get_small_cost() << endl;
				arr[count++-1] = index;
		}
		index++;
		if(this->pizzas[i].get_medium_cost() != -1){
			cout << "(" << count << ")\tMedium " << this->pizzas[i].get_name()
				<< " - $" << this->pizzas[i].get_medium_cost() << endl;
				arr[count++-1] = index;
		}
		index++;
		if(this->pizzas[i].get_large_cost() != -1){
			cout << "(" << count << ")\tLarge " << this->pizzas[i].get_name()
				<< " - $" << this->pizzas[i].get_large_cost() << endl;
				arr[count++-1] = index;
		}
		index++;
}


Order* Menu::display_results(int &n_orders){
	int count = 1, index = 0, *arr = new int [this->num_pizzas*3], *selection = new int [this->num_pizzas*3];
	int *quantity = new int[this->num_pizzas*3];
	int capacity = 1;
	for(int i = 0; i < this->num_pizzas*3; i++){
		arr[i] = -1;
		selection[i] = -1;
		quantity[i] = -1;
	}
	for(int i = 0; i < this->num_pizzas*3; i++){
		this->print_results(index, count, i, arr);
	}
	cout << "VISUAL REPRESENTATION OF THE ARRAY" << endl;
	for(int i = 0; i < this->num_pizzas; i++)
		cout << arr[i] << " ";
	cout << endl;
	return this->get_results(n_orders, arr, selection, quantity, capacity);
}


Order* Menu::evaluate_purchase(int* selection, int* quantity, int& n_orders){
	string sizes[] = {"Small", "Medium", "Large"};
	Order* customer_order = new Order[1];
	if(n_orders == 0){
		return customer_order;
	}
	customer_order->set_pizza_name(this->pizzas[(selection[0]-1)/3].get_name(), 0);
	// customer_order->set_size(sizes[(selection[0] - 1)%3][0], 0);
	customer_order->set_quantity(quantity[0], 0);
	for(int i = 1; i < n_orders; i++){
		customer_order->upsize_pizzas();
		customer_order->set_pizza_name(this->pizzas[(selection[i]-1)/3].get_name(), 0);
		// customer_order->set_size(sizes[(selection[i] - 1)%3][0], 0);
		customer_order->set_quantity(quantity[i], 0);
	} delete[] selection; delete[] quantity;
	return customer_order;
}


Order* Menu::get_results(int &n_orders, int* arr, int* selection, int* quantity, int& capacity){
	int index= 0;
	string sizes[] = {"Small", "Medium", "Large"}, usr = "blank";
	while(usr != "0" || usr != ""){
		cout << "Please select an option from the list above. \nYou may also enter 0 to cancel this order"
			" or press enter (blank line) to proceed to checkout.\nYour selection: ";
		getline(cin, usr);
		if(is_digits(usr)){
			selection[index] = stoi(usr);
			n_orders++;
			cout << "How many " << sizes[arr[stoi(usr) - 1]%3] << " " 
				<< this->pizzas[arr[stoi(usr) - 1]/3].get_name()<< "? ";
				cin >> quantity[index];
			index++;
		}
	}
	usr == "0"? n_orders = 0:n_orders = n_orders;
	delete[] arr;
	return this->evaluate_purchase(selection, quantity, n_orders);
}


			// arr[stoi(usr) - 1]/3 //pizza index
			// arr[stoi(usr) - 1]%3 //pizza size