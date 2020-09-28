/*********************************************************************************************
** Program Filename:	Room.cpp
** Author:				Lyon Kee
** Date:					5/25/2020
** Description:		Have all functions that operate ona room
** Input:				-
** Output:				-
*********************************************************************************************/


#include "Room.h"

/*********************************************************************
** Function:			Room
** Description:		default constructor for room
** Parameters:			-
** Pre-Conditions:	a room is declared
** Post-Conditions:	a room is constructed
*********************************************************************/ 
Room::Room(){
	this->icon = ' ';
	this->event = NULL;
}


/*********************************************************************
** Function:			Room
** Description:		Room destructor
** Parameters:			-
** Pre-Conditions:	room scope ends
** Post-Conditions:	deletes allocated event memory
*********************************************************************/ 
Room::~Room(){
	delete this->event;
}


/*********************************************************************
** Function:			get_icon
** Description:		gets the icon of the room
** Parameters:			-
** Pre-Conditions:	-
** Post-Conditions:	returns icon
*********************************************************************/ 
char Room::get_icon(){
	return this->icon;
}


/*********************************************************************
** Function:			get_event
** Description:		gets the event of the room
** Parameters:			-
** Pre-Conditions:	-
** Post-Conditions:	returns the event of the room
*********************************************************************/ 
Event* Room::get_event(){
	return this->event;
}


/*********************************************************************
** Function:			run_encounter
** Description:		runs the enconter set for the room
** Parameters:			int size, bool& dead, bool& gold, int &player_x, int& player_y
** Pre-Conditions:	-
** Post-Conditions:	encountered for the room's event executed
*********************************************************************/ 
void Room::run_encounter(int size, bool& dead, bool& gold, int &player_x, int& player_y){
	bool prev_gold = gold;
	this->event->encounter(size, dead, gold, player_x, player_y);
	if(gold != prev_gold){
		this->clear_event();
	}
}


/*********************************************************************
** Function:			set_event
** Description:		sets the event for a room
** Parameters:			string type
** Pre-Conditions:	-
** Post-Conditions:	sets a room accoring to parameter
** Justification:		the addition of delete is here because it makes more sense to 
								put it before allocating memory than outside of this function
*********************************************************************/ 
void Room::set_event(string type){
	delete this->event;
	if(type == "Wumpus"){
		this->icon = 'W';
		this->event = new Wumpus;
	}
	else if(type == "Bats"){
		this->icon = 'B';
		this->event = new Bats;
	}
	else if(type == "Pit"){
		this->icon = 'P';
		this->event = new Pit;
	}
	else if(type == "Gold"){
		this->icon = 'G';
		this->event = new Gold;
	}
	else if(type == "Empty"){
		this->icon = ' ';
		this->event = new Empty;
	}
}
// 
// 
// /*********************************************************************
// ** Function:			move
// ** Description:		
// ** Parameters:			
// ** Pre-Conditions:	
// ** Post-Conditions:	
// *********************************************************************/ 
// void Room::move(){
// 	char key = get_key();
// }


/*********************************************************************
** Function:			is_empty_room
** Description:		checks if a room is empty
** Parameters:			-
** Pre-Conditions:	-
** Post-Conditions:	returns true or false according to this rooom
*********************************************************************/ 
bool Room::is_empty_room(){
	if(this->icon == ' ')
		return true;
	return false;
}


/*********************************************************************
** Function:			clear_event
** Description:		
** Parameters:			
** Pre-Conditions:	
** Post-Conditions:	
*********************************************************************/ 
void Room::clear_event(){
	delete this->event;
	this->event = NULL;
	this->icon = ' ';
}


/*********************************************************************
** Function:			get_message
** Description:		
** Parameters:			
** Pre-Conditions:	
** Post-Conditions:	
*********************************************************************/ 
string Room::get_message(){
	return this->event->percept();
}


/*********************************************************************
** Function:			CL_is_valid
** Description:		checks for command line argument validity
** Parameters:			int argc, char** argv
** Pre-Conditions:	command line provided
** Post-Conditions:	ends game if arguments are incorrect
*********************************************************************/ 
bool CL_is_valid(int argc, char** argv){
	if(argc == 3){
		if(strcmp(argv[2],"true") == 0 || strcmp(argv[2],"false") == 0){
			for(int i = 0; argv[1][i] != '\0'; ++i){
				if(argv[1][i] < '0' || argv[1][i] > '9'){
					return false;
				}
			}
			if(atoi(argv[1]) < 4){
				cout << "Map size cannot be lesser than 4\n";
				return false;
			}
			return true;
		}
	}
	return false;
}


/*********************************************************************
** Function:			get_key
** Description:		gets a keypress
** Parameters:			-
** Pre-Conditions:	-
** Post-Conditions:	returns a keypress
*********************************************************************/ 
char get_key(){
	char key;
	do{
		system("stty raw");
		cin >> noskipws >> key;
		system("stty cooked");
	}while(key!='w' && key!= 'a' && key!= 's' && key!= 'd' && key != ' ');
	return key;
}


/*********************************************************************
** Function:			stob
** Description:		changes a string to a boolean
** Parameters:			string cond
** Pre-Conditions:	a string is passed in
** Post-Conditions:	true or false or error thrown according to string passed in
*********************************************************************/ 
bool stob(string cond){
	if(cond == "true")
		return true;
	if(cond == "false")
		return false;
	throw "Custom error converting string to bool";
}