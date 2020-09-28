#ifndef ROOM_H
#define ROOM_H
#include <iostream>
#include <vector>
#include <cstdlib>
#include <string.h>
#include "Event.h"
#include "Wumpus.h"
#include "Bats.h"
#include "Pit.h"
#include "Gold.h"
#include "Empty.h"


using namespace std;

class Room{
	protected:
		char icon;
		Event *event;
	public:

		Room();
		~Room();

		char get_icon();
		Event* get_event();
		void run_encounter(int, bool&, bool&, int &, int&);
		void set_event(string);
		void set_coords(int, int);
		// void move();
		bool is_empty_room();
		void clear_event();
		string get_message();

};

bool CL_is_valid(int, char**);
char get_key();
bool stob(string cond);


#endif

// Room
// Event
// Wumpus
// Bats
// Pit
// Gold
// Empty