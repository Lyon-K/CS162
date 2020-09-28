#include <iostream>
#include <fstream>
#include <string.h>
#include <cstdlib>
#include "student_db.h"
using namespace std;

student * create_student_db(int num){
	student *temp = new student[num];
	return temp;
}

void populate_student_db_info(student *s, int num, ifstream &fin){
	string temp;
	long n;
	for(int i = 0; i < num; i++){
		fin >> n;
		s[i].id = n;
		fin >> temp;
		s[i].firstname = temp;
		fin >> temp;
		s[i].lastname = temp;
		fin >> temp;
		s[i].major = temp;
		
		// fin >> s[i].id;
		// fin >> s[i].firstname;
		// fin >> s[i].lastname;
		// fin >> s[i].major;
	}
}

void delete_student_db_info(student **arr, int num){
	// for(int i = 0; i < num; i++)
	delete[] *arr;
	arr = NULL;
}

void swap(int &a, int &b){
	int temp = a;
	a = b;
	b = temp;
}