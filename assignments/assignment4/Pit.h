#ifndef PIT_H
#define PIT_H

#include <string.h>
#include "Event.h"
using std::string;


class Pit: public Event{
	public:
		string percept();
		void encounter(int, bool&, bool&, int &, int&);
};


#endif