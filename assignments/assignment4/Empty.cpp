/*********************************************************************************************
** Program Filename:	Empty.cpp
** Author:				Lyon Kee
** Date:					5/25/2020
** Description:		Empty class of which is a child of an abstract class named event
** Input:				-
** Output:				-
*********************************************************************************************/


#include "Empty.h"
#include <iostream>
using namespace std;


/********************************************************************************************
** Function:			percept()
** Description:		returns the message for the room's event
** Parameters:			-
** Pre-Conditions:	-
** Post-Conditions:	returns perception
********************************************************************************************/ 
string Empty::percept(){
	string str = "";
	return str;
}


/********************************************************************************************
** Function:			encounter()
** Description:		performs the action if the event is enocuntered
** Parameters:			int size, bool& dead, bool& gold, int &player_x, int& player_y
** Pre-Conditions:	-
** Post-Conditions:	-
********************************************************************************************/ 
void Empty::encounter(int size, bool& dead, bool& gold, int &player_x, int& player_y){

}