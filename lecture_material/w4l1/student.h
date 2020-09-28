#ifndef STUDENT_H
#define STUDENT_H

#include <iostream>
#include <fstream>

using namespace std;


class Student
{
public:
	Student();
	Student(int, string, string, int, float*);

	//getters and setters
	int get_id() const;
	int get_terms() const;

	//big three
	Student(const Student&);
	Student& operator=(const Student&);
	~Student();

	//print one student object
	void display_student();

	//populate one student object
	void pop_student(ifstream&);



private:
	int id;
	string fname;
	string lname;
	
	int terms; //indicate number of elements in grades
	float* grades; //gpa of each term

};

#endif