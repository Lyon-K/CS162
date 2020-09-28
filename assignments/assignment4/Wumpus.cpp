/*********************************************************************************************
** Program Filename:	Wumpus.cpp
** Author:				Lyon Kee
** Date:					5/25/2020
** Description:		Wumpus class of which is a child of an abstract class named event
** Input:				-
** Output:				-
*********************************************************************************************/


#include "Wumpus.h"
#include <iostream>
using namespace std;


/*********************************************************************************************
** Function:			percept()
** Description:		returns the perception message of the event
** Parameters:			-
** Pre-Conditions:	-
** Post-Conditions:	returns perception
*********************************************************************************************/ 
string Wumpus::percept(){
	string str = "You smell a terrible stench.";
	return str;
}


/*********************************************************************************************
** Function:			encounter()
** Description:		performs the action if the event is enocuntered
** Parameters:			int size, bool& dead, bool& gold, int &player_x, int& player_y
** Pre-Conditions:	-
** Post-Conditions:	kills player
*********************************************************************************************/ 
void Wumpus::encounter(int size, bool& dead, bool& gold, int &player_x, int& player_y){
	dead = true;
	cout << "KILLED BY WUMPUS" << endl;
}