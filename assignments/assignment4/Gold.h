#ifndef GOLD_H
#define GOLD_H

#include <string.h>
#include "Event.h"
using std::string;


class Gold: public Event{
	public:
		string percept();
		void encounter(int, bool&, bool&, int &, int&);
};


#endif