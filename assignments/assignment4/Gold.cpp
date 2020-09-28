/*********************************************************************************************
** Program Filename:	Gold.cpp
** Author:				Lyon Kee
** Date:					5/25/2020
** Description:		Gold class of which is a child of an abstract class named event
** Input:				-
** Output:				-
*********************************************************************************************/


#include "Gold.h"
#include <iostream>
using namespace std;


/*********************************************************************************************
** Function:			percept()
** Description:		returns the perception message of the event
** Parameters:			-
** Pre-Conditions:	-
** Post-Conditions:	returns perception
*********************************************************************************************/ 
string Gold::percept(){
	string str = "You see a glimmer nearby.";
	return str;
}


/*********************************************************************************************
** Function:			encounter()
** Description:		performs the action if the event is enocuntered
** Parameters:			int size, bool& dead, bool& gold, int &player_x, int& player_y
** Pre-Conditions:	-
** Post-Conditions:	player obtains gold
*********************************************************************************************/ 
void Gold::encounter(int size, bool& dead, bool& gold, int &player_x, int& player_y){
	gold = true;
	cout << "You've taken the gold!" << endl;
}