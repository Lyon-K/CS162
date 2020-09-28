#ifndef EMPTY_H
#define EMPTY_H

#include <string.h>
#include "Event.h"
using std::string;


class Empty: public Event{
	public:
		string percept();
		void encounter(int, bool&, bool&, int &, int&);
};


#endif