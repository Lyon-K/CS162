#include <iostream>
#include <fstream>
#include <string.h>
#include "restaurant.h"
using namespace std;

int main(int argc, char *argv[])
{
	//your main function lives here
	ifstream fin("menu.txt");
	Pizza a, b, c, d;
	a.set_name("TEST");
	a.set_from_file(fin);
	a.display_pizza();
	b.set_name("TEST2");
	b.set_from_file(fin);
	b.display_pizza();
	c.set_name("TEST3");
	c.set_from_file(fin);
	c.display_pizza();
	d.set_name("TEST4");
	d.set_from_file(fin);
	d.display_pizza();
	return 0;
}