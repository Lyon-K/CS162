#include <iostream>
#include <fstream>

#include "course.h"

using namespace std;

int main(int argc, char const *argv[])
{
	//Which constructor is called?
	Course c1;

	ifstream f("info.txt");
	if (!f.is_open()){
		cout << "unable to open the file" << endl;
		return 1;
	}

	c1.pop_course(f);
	c1.display_course();

	//Does one of the big 3 get called here? which one?
	Course c2 = c1;

	float *grade_arr = new float[3];
	grade_arr[0] = 3.69;
	grade_arr[1] = 3.75;
	grade_arr[2] = 3.80;

	//Which constructor is called?
	Student s(10004, "Peter", "Parker", 3, grade_arr);	

	//Does one of the big 3 get called here? which one?
	c2.add_student(s);
	c2.remove_student(10002);
	c2.display_course();

	//Does one of the big 3 get called here? which one?
	Course c3 = c1.search_std_by_terms(4);
	cout << "TEST1\n";
	c3.display_course();

	return 0;
	
}

//After going out of scope, 
//How many times is Course destructor called?
//How many times is Student destructor called?
