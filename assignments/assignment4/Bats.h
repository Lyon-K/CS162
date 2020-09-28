#ifndef BATS_H
#define BATS_H

#include <string.h>
#include "Event.h"
using std::string;


class Bats: public Event{
	public:
		string percept();
		void encounter(int, bool&, bool&, int &, int&);
};


#endif