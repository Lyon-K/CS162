#include <iostream>
#include <fstream>
#include <string.h>
#include "restaurant.h"
using namespace std;
/*********************************************************************
** Function:	main
** Description:	runs the code for the program
** Parameters:	none
** Pre-Conditions:	-
** Post-Conditions:	-
*********************************************************************/ 
int main(int argc, char *argv[])
{
	//your main function lives here
	// declarations end
	// ifstream fin("menu.txt");
	// Pizza a, b, c, d;
	// a.set_from_file(fin);
	// a.display_pizza();
	// b.set_from_file(fin);
	// b.display_pizza();
	// c.set_from_file(fin);
	// c.display_pizza();
	// d.set_from_file(fin);
	// d.display_pizza();
	// d = a;
	// Pizza test = b;
	// d.display_pizza();
	// test.display_pizza();


	// Menu menu;
	// menu.populate_pizzas(fin);
	// menu.display_pizzas();

	// cout << "TESTING STARTS\n\n";
	// Pizza a;
	// a.set_name("TEST1");
	// a.set_small_cost(5);
	// a.set_medium_cost(55);
	// a.set_large_cost(555);
	// a.set_num_ingredients(2);
	// a.set_ingredients("TESTING");
	// a.set_ingredients("DEBUGING");
	// a.display_pizza();

	// cout << "ADDED PIZZA\n\n";
	// menu.add_to_menu(a);
	// menu.display_pizzas();
	// menu.remove_from_menu(6);
	// menu.display_pizzas();

	Restaurant proj;
	cout << "Welcome to Bytes Pizza!\n";
	proj.main_menu();
	// proj.get_menu().display_pizzas();
	// proj.view_menu();
	// proj.view_hours();
	// proj.display_employee();
	// proj.search_menu_by_price();
	// cout << "SHOULD BE VIEWING ORDERS\n";
	// proj.view_orders();


	// Order *test = new Order[1];
	// test->set_order_num(4);
	// test->set_customer_name("LYON");
	// test->set_customer_CC("LEL NO WAY");
	// test->set_customer_phone("NOT TELLIN HP NO");
	// ordered_pizzas * p = new ordered_pizzas[1];
	// p->pizza_name = "PIIIIZ!";
	// p->size = "SO BIG";
	// p->quantity = 20;
	// test->set_pizzas(p, 1);
	// cout << "ADDED ORDER TO MENU\n\n\n";
	// proj.add_to_orders(test);
	// cout << "PRINTING ORDERS TO MENU" << endl;
	// delete[] p;

	// proj.remove_orders(1);
	// proj.view_orders();

	// cout << "END PROG\n";
	return 0;
}