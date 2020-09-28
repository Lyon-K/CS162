#include <iostream>
#include<fstream>
#include <string.h>
#include "student_db.h"
using namespace std;

int main(int argc, char* argv[]){
	int size;
	if(argc != 2){
		cout << "ERROR! Run the file with input.txt file following it "
			<< "like such: " << argv[0] << " [input.txt]\n";
		return 1;
	}
	ifstream fin(argv[1]);
	if(!fin.is_open()){
		cout << "Invalid text file\n";
		return 1;
	}
	fin >> size;
	int sort[size];
	student *group = create_student_db(size);

	//student *group = new student[size]

	populate_student_db_info(group, size, fin);
	fin.close();
	for(int i = 0; i < size; i++){
		sort[i] = i;
	}
	for(int i = size - 1; i >= 0; i--){
		for(int j = 0; j < i; j++){
			if(group[sort[j]].id > group[sort[j + 1]].id)
				swap(sort[j], sort[j + 1]);
		}
	}
	ofstream fout("sort_id.txt");
	if(!fout.is_open()){
		cout << "Error opening sort id file.\n";
		return 1;
	}else{
		fout << size << endl;
		for(int i = 0; i < size; i++){
			fout << group[sort[i]].id << " "
				<< group[sort[i]].firstname << " "
				<< group[sort[i]].lastname << " "
				<< group[sort[i]].major << endl;
		}
		fout.close();
	}


	for(int i = 0; i < size; i++){
		sort[i] = i;
	}
	for(int i = size - 1; i >= 0; i--){
		for(int j = 0; j < i; j++){
			if(group[sort[j]].lastname > group[sort[j + 1]].lastname)
				swap(sort[j], sort[j + 1]);
		}
	}
	fout.open("sort_lastname.txt");
	if(!fout.is_open()){
		cout << "Error opening sort lastname file.\n";
		return 1;
	}else{
		fout << size << endl;
		for(int i = 0; i < size; i++){
			fout << group[sort[i]].id << " "
				<< group[sort[i]].firstname << " "
				<< group[sort[i]].lastname << " "
				<< group[sort[i]].major << endl;
		}
		fout.close();
	}

	int index = 0;
	string arr[size];
	for(int i = 0; i < size; i++)
		sort[i] = 0;
	bool repeat = false;
	for(int i = 0; i < size; i++){
		repeat = false;
		for(int j = 0; j < size; j++){
			if(group[i].major == arr[j]){
				repeat = true;
				sort[j]++;
				break;
			}
		}
		if(!repeat){
			arr[index] = group[i].major;
			sort[index]++;
			index++;
		}
	}
	fout.open("count_major.txt");
	if(!fout.is_open()){
		cout << "Error opening sort major file.\n";
		return 1;
	}else{
		for(int i = 0; i < size; i++){
			if(!arr[i].empty()){
				fout << arr[i] << " " << sort[i] << endl;
			}
		}
		fout.close();
	}
	delete_student_db_info(&group, size);
	return 0;
}
