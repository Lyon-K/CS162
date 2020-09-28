#include "course.h"

using namespace std;

Course::Course(){
	cout << "Course Constructor called" << endl;
	this->num_std = 0;
	this->std = NULL;
}

Course::Course(const Course& old_obj){
	cout << "Copy Constructor of Course called" << endl;
	this->num_std = old_obj.num_std;

	this->std = new Student [this->num_std];
	for (int i = 0; i < this->num_std; ++i)
		this->std[i] = old_obj.std[i];
	
}

Course& Course::operator=(const Course& old_obj){
	cout << "Assignment operator overload of Course called" << endl;
	if (this != &old_obj){
		this->num_std = old_obj.num_std;

		if (this->std != NULL)
			delete [] this->std;
		this->std = new Student [this->num_std];
		for (int i = 0; i < this->num_std; ++i)
			this->std[i] = old_obj.std[i];
	}
	return *this;
}

Course::~Course(){
	cout << "Course Destructor called" << endl;
	if (this->std != NULL){
		delete [] this->std;
		this->std = NULL;
	}
}

void Course::pop_course(ifstream& in_file){
	//given the ifstream object, populate the course object
}


void Course::display_course(){
	//display each student's info in this course object
}

void Course::add_student(Student std_to_add){
	cout << "ADD_STUDENT\n";
	//add a student to this course object
}

void Course::remove_student(int id){
	cout << "REMVOE_STUDENT\n";
	//remove a student from this course object
	//by the id of the student to remove
}

Course Course::search_std_by_terms(int lower_limit){
	//provided a lower_limit of terms, return a Course object
	//in which each student's term is greater than the lower_limit

	//you need to fix this
	cout << "SEARCH_STD_BY_TERMS\n";
	return *this;
}