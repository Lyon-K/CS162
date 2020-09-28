/*********************************************************************************************
** Program Filename:	Bats.cpp
** Author:				Lyon Kee
** Date:					5/25/2020
** Description:		Bats class of which is a child of an abstract class named event
** Input:				-
** Output:				-
*********************************************************************************************/


#include "Bats.h"
#include <iostream>
#include <cstdlib>


using namespace std;

/*********************************************************************************************
** Function:			percept()
** Description:		returns the perception message of the event
** Parameters:			-
** Pre-Conditions:	-
** Post-Conditions:	returns perception
*********************************************************************************************/ 
string Bats::percept(){
	string str = "You hear wings flapping.";
	return str;
}


/*********************************************************************************************
** Function:			encounter()
** Description:		performs the action if the event is enocuntered
** Parameters:			int size, bool& dead, bool& gold, int &player_x, int& player_y
** Pre-Conditions:	-
** Post-Conditions:	telepots the player to another location
*********************************************************************************************/
void Bats::encounter(int size, bool& dead, bool& gold, int &player_x, int& player_y){
	// cout << "WITHIN BATS ENCOUNTER METHOD" << endl;
	int x, y;
	do{
		// cout << "INFINITE LOOP?!?!?!" << endl;
		x = rand()%size, y = rand()%size;
	}while(x == player_x && y == player_y);
	// cout << "loop exited" << endl;
	player_x = x;
	player_y = y;
	// cout << "teleported to <"<<x << "," << y << ">" << endl;
}