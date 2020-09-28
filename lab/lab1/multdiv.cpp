#include<iostream>
#include<stdlib.h>
#include<string.h>
#include<iomanip>
#include "multdiv.h"
using namespace std;


bool is_valid_dimensions(char* m, char* n){
	for(int i = 0; i < strlen(m); i++){
		if(m[i] >= 'a' && m[i] <= 'z' 
				|| m[i] >= 'A' && m[i] <= 'Z'){
			cout << "You did not enter valid integers...\n";
			return 0;
		}
	}
	for(int i = 0; i < strlen(n); i++){
		if(n[i] >= 'a' && n[i] <= 'z' 
				|| n[i] >= 'A' && n[i] <= 'Z'){
			cout << "You did not enter valid integers...\n";
			return 0;
		}
	}
	if(atoi(m) < 1 || atoi(n) < 1)
		return 0;
	return 1;
}

multdiv_entry** create_table(int row, int col){
	multdiv_entry** t = new multdiv_entry*[row];
	for(int i = 0; i < row; i++)
		t[i] = new multdiv_entry[col];
	for(int i = 0; i < row; i++){
		for(int j = 0; j < col; j++){
			t[i][j].mult = (i+1)*(j+1);
			t[i][j].div = (float)(i+1)/(j+1); //cast j to float aswell???????
		}
	}
	return t;
}

void print_table(multdiv_entry** tables, int row, int col){
	cout << "Multiplication Table:\n";
	for(int i = 0; i < row; i++){
		for(int j = 0; j < col; j++){
			cout << tables[i][j].mult << "\t";
		}
		cout << endl;
	}

	cout << "Division Table:\n";
	for(int i = 0; i < row; i++){
		for(int j = 0; j < col; j++){
			cout << tables[i][j].div << "\t";
		}
		cout << endl;
	}
}

void delete_table(multdiv_entry** tables, int row){
	for(int i = 0; i < row; i++)
		delete[] tables[i];
	delete[] tables;
}
