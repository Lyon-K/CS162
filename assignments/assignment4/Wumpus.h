#ifndef WUMPUS_H
#define WUMPUS_H

#include <string>
#include "Event.h"
using std::string;


class Wumpus: public Event{
	public:
		string percept();
		void encounter(int, bool&, bool&, int &, int&);
};


#endif