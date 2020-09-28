#include "student.h"

using namespace std;

Student::Student(){
	cout << "Default Constructor of student called" << endl;
	this->id = 0;
	this->fname = "";
	this->lname = "";
	this->terms = 0;
	this->grades = NULL;
}

Student::Student(int id, string fname, string lname, int terms, float* grades){
	cout << "Non-Default Constructor of student called" << endl;
	this->id = id;
	this->fname = fname;
	this->lname = lname;
	this->terms = terms;
	this->grades = grades;
}

int Student::get_id() const {return this->id;}
int Student::get_terms() const {return this->terms;}

Student::Student(const Student& old_obj){
	cout << "Copy Constructor of Student called" << endl;
	this->id = old_obj.id;
	this->fname = old_obj.fname;
	this->lname = old_obj.lname;
	this->terms = old_obj.terms;
	
	this->grades = new float [this->terms];
	for (int i = 0; i < this->terms; ++i)
		this->grades[i] = old_obj.grades[i];
	
}

Student& Student::operator=(const Student& old_obj){
	cout << "Assignment operator overload of Student called" << endl;
	if (this != &old_obj){
		this->id = old_obj.id;
		this->fname = old_obj.fname;
		this->lname = old_obj.lname;
		this->terms = old_obj.terms;
		
		if (this->grades != NULL)
			delete [] this->grades;
		this->grades = new float [this->terms];
		for (int i = 0; i < this->terms; ++i)
			this->grades[i] = old_obj.grades[i];
	}
	return *this;
}

Student::~Student(){
	cout << "Student Destructor called " << endl;
	if (this->grades != NULL){
		delete [] this->grades;
		this->grades = NULL;
	}
}

void Student::display_student(){
	//display info of this student object
}

void Student::pop_student(ifstream& in_file){
	//populate info to this student object
}


