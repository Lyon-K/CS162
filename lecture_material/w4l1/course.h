#ifndef COURSE_H
#define COURSE_H 

#include <iostream>
#include <fstream>

#include "student.h"

using namespace std;

class Course
{
public:
	Course();
	
	Course(const Course&);
    Course& operator=(const Course&);
	~Course();

	void pop_course(ifstream&);
	void display_course();

	void add_student(Student);
	void remove_student(int);

	Course search_std_by_terms(int);

private:
	int num_std;
	Student* std;
};
#endif