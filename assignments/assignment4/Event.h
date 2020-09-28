/*********************************************************************************************
** Program Filename:	Event.h
** Author:				Lyon Kee
** Date:					5/25/2020
** Description:		An abstract class named Event which is a parent to Wumpus, Bats, Gold,
								Pit, and Empty which are the types of events in this game
** Input:				-
** Output:				-
*********************************************************************************************/


#ifndef EVENT_H
#define EVENT_H
#include <string>
using std::string;

class Event{
	public:
		virtual string percept() = 0;
		virtual void encounter(int, bool&, bool&, int&, int&) = 0;
};


#endif