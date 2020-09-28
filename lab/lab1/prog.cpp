#include<iostream>
#include<stdlib.h>
#include<string.h>
#include<iomanip>
#include "multdiv.h"
using namespace std;

int main(int argc, char* argv[]){
	bool rerun;
	int row, col;
	cout << fixed;
	cout << setprecision(2);
	if(argc != 3){
		cout << "Enter 2 integers following the file call\n";
		return 0;
	}
	do{
		if(!is_valid_dimensions(argv[1], argv[2]))
			return 0;
		row = atoi(argv[1]);
		col = atoi(argv[2]);
		multdiv_entry** table = create_table(row, col);
		print_table(table, row, col);
		delete_table(table, row);
		cout << "Would you like to see a different size matrix (0-no, 1-yes)? ";
		cin >> rerun;
			cin.ignore();
		if(rerun){
			cout << "Enter an integer greater than 0 for row: ";
			cin.getline(argv[1], 15);
			cout << "Enter an integer greater than 0 for col: ";
			cin.getline(argv[2], 15);
		}
	}while(rerun);
	return 0;
}
