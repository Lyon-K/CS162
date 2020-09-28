/******************************************************
** Program: catalog.cpp
** Author: Lyon Kee
** Date: 04/13/2020
** Description: function definitions
** Input: none
** Output: none
******************************************************/
#include <iostream>
#include <string.h>
#include <cstdlib>
#include <fstream>
#include "catalog.h"
using namespace std;


/*********************************************************************
** Function:		create_spellbooks
** Description:		dynamically creates spellbook
** Parameters:		int n
** Pre-Conditions:	n is the number of spellbook
** Post-Conditions:	returns the address of spellbook in the heap of size n
*********************************************************************/ 
spellbook * create_spellbooks(int n){
	spellbook* temp = new spellbook[n];
	return temp;
}


/*********************************************************************
** Function:		populate_spellbook_data
** Description:		populate spellbook into the program struct
** Parameters:		spellbook *book, int n, ifstream &fin
** Pre-Conditions:	the .txt file is correct and has the right format
** Post-Conditions:	the struct is filled with data
*********************************************************************/ 
void populate_spellbook_data(spellbook *book, int n, ifstream &fin){
	int spell_count;
	for(int i = 0; i < n; i++){
		/*
		 * float to store the rate which is used to take the average
		 * and then store into the avg_success_rate of the book
		 */
		float rate = 0;
		fin >> book[i].title;
		fin >> book[i].author;
		fin >> book[i].num_pages;
		fin >> book[i].edition;
		fin >> book[i].num_spells;
		/*
		 * spells are within each book so it is called here to populate within
		 * this function.
		 */
		book[i].s = create_spells(book[i].num_spells);
		populate_spell_data(book[i].s, book[i].num_spells, fin);
		for(int j = 0; j < book[i].num_spells; ++j){
			rate += book[i].s[j].success_rate;
		}
		/*
		 * This is to get the average of the spell success rates
		 */
		rate /= (float)book[i].num_spells;
		/* 
		 * Assigned atlsat because this depends on the values of spells
		 * which are only knwon after the spells are populated.
		 */
		book[i].avg_success_rate = rate;
	}
}


/*********************************************************************
** Function:		create_spells
** Description:		dynamically creates spell on the heap
** Parameters:		int n
** Pre-Conditions:	spell struct is correct
** Post-Conditions:	returns a heal location of spell type with size n
*********************************************************************/ 
spell * create_spells(int n){
	spell *temp = new spell[n];
	return temp;
}


/*********************************************************************
** Function:		populate_spell_data
** Description:		fills in the spell data struct
** Parameters:		spell *s, int n, ifstream &fin
** Pre-Conditions:	spell data format is correct
** Post-Conditions:	populates the struct with the spell data given
*********************************************************************/
void populate_spell_data(spell *s, int n, ifstream &fin){
	for(int i = 0; i < n; i++){
		fin >> s[i].name;
		fin >> s[i].success_rate;
		fin >> s[i].effect;
	}
}


/*********************************************************************
** Function:		delete_info
** Description:		deletes all declared heap data
** Parameters:		wizard **wiz, spellbook **book, int n
** Pre-Conditions:	there are memory allocated
** Post-Conditions:	all allocated data freed
*********************************************************************/
void delete_info(wizard **wiz, spellbook **book, int n){
	delete[] *wiz;
	wiz = NULL;
	/*
	 * They are all double poitners where the heap is located at the single pointer 
	 * so we have to dereference before going into the indexes of it to delete 
	 * the spells allocated
	 */
	for(int i = 0; i < n; ++i)
		delete[] (*book)[i].s;
	delete[] *book;
	book = NULL;
}


/*********************************************************************
** Function:		populate_wizard_data
** Description:		fills wizard struct with data
** Parameters:		int n, ifstream &fin
** Pre-Conditions:	wizard.txt must be valid and as formatted
** Post-Conditions:	struct is populated
*********************************************************************/
wizard * populate_wizard_data(int n, ifstream &fin){
	wizard* temp = new wizard[n];
	for(int i = 0; i < n; ++i){
		fin >> temp[i].name;
		fin >> temp[i].id;
		fin >> temp[i].password;
		fin >> temp[i].position_title;
		fin >> temp[i].beard_length;
	}
	return temp;
}


/*********************************************************************
** Function:		terminal_arg_is_valid
** Description:		Checks if the terminal arguments are valid and as intended
** Parameters:		int c, string arg0, string arg1, string arg2
** Pre-Conditions:	none
** Post-Conditions:	if invalid then exit the function with a prompt
*********************************************************************/
void terminal_arg_is_valid(int c, string arg0, string arg1, string arg2){
	if(c != 3 || arg1 != "wizards.txt" || arg2 != "spellbooks.txt"){
		cout << "Error. You must run with " << arg0 
			<< " <wizards.txt> <spellbooks.txt> \n";
		exit(1);
	}
}


/*********************************************************************
** Function:		get_count
** Description:		returns the count which is the first line of the txt file
** Parameters:		ifstream &fin, string name
** Pre-Conditions:	fin is valid
** Post-Conditions:	returns the first line in int
*********************************************************************/
int get_count(ifstream &fin, string name){
	int c;
	if(!fin.is_open()){
		cout << "Could not open " << name << " file.\n";
		exit(1);
	}
	fin >> c;
	return c;
}


/*********************************************************************
** Function:		check_id
** Description:		check if id is valid if not then prompt again
** Parameters:		none
** Pre-Conditions:	none
** Post-Conditions:	returns a valid ID
*********************************************************************/
string check_id(){
	string temp;
	while(true){
		bool valid = true;
		cout << "Enter your ID: ";
		getline(cin, temp);
		for(int i = 0; temp[i] != '\0'; ++i){
			if(temp[i] < '0' || temp[i] > '9'){
				valid = false;
				cout << "Invalid ID! Try again.\n\n";
				break;
			}
		}
		if(valid){
			cout << "Enter your password: ";
			return temp;
		}
	}
}


/*********************************************************************
** Function:		show_char
** Description:		revels who the one logged in is
** Parameters:		wizard* w, int index
** Pre-Conditions:	there is someone logged in
** Post-Conditions:	information of the wizard is displayed
*********************************************************************/
void show_char(wizard* w, int index){
	cout << "Welcome " << w[index].name << endl;
	cout << "ID: " << w[index].id << endl;
	cout << "Status: " << w[index].position_title << endl;
	cout << "Beard Length: " << w[index].beard_length << endl << endl;

}


/*********************************************************************
** Function:		loggedin
** Description:		if if and password is correct returns true to allow access
** Parameters:		wizard* wiz, int n, int &usr
** Pre-Conditions:	there is wizard populated to check against
** Post-Conditions:	true or false depending on the id and pass entered
*********************************************************************/
bool loggedin(wizard* wiz, int n, int &usr){
	int attempts = 3;
	while(attempts > 0){
		bool valid = false;
		string id = check_id(), pass;
		getline(cin, pass);
		for(int i = 0; i < n; ++i){
			/*
			 * id is in int so we have to chang it back to int to compare
			 * or we could compare both strings but nonetherless we have to cast
			 * it a way or another, I used stoi which changes string to int
			 */
			if(stoi(id) == wiz[i].id){
				if(pass == wiz[i].password){	//access granted
					valid  = true;
					/*
					 * keeps tract of the index of the person gaining access*/
					usr = i;
				}
			}
		}
		if(!valid){
			cout <<"Incorrect id or password\n" << --attempts <<" attemps left.\n";
		}else{	//access granted because valid is true
			show_char(wiz,usr);
			return true;
		}
	}
	/*
	* Access not granted because number of trials have ran out
	*/
	cout << "ERROR LOGING IN\n";
	return false;
}


/*********************************************************************
** Function:		init
** Description:		used to initialize wizard and spellbook
** Parameters:		int &n, int c, string ar0, string ar1, string ar2
						, wizard** w, spellbook** b, int &n_b
** Pre-Conditions:	terminal argument is valid
** Post-Conditions:	proceedes to populate wizard then spells
*********************************************************************/
void init(int &n, int c, string ar0, string ar1, string ar2
		, wizard** w, spellbook** b, int &n_b){
	terminal_arg_is_valid(c, ar0, ar1, ar2);
	ifstream fin(ar1);
	n = get_count(fin, ar1); //sub into next line
	*w = populate_wizard_data(n, fin);
	fin.close();
	fin.open(ar2);
	n_b = get_count(fin, ar2);
	*b = create_spellbooks(n_b);
	populate_spellbook_data(*b, n_b, fin);
	fin.close();
}


/*********************************************************************
** Function:		append_to
** Description:		a fucntion to append strings to a file
** Parameters:		string &file, string str
** Pre-Conditions:	if file not spefied, ask for a file
** Post-Conditions:	the string is written into the file
*********************************************************************/
void append_to(string &file, string str){
	if(file == ""){
		cout << "Please provide desired filename: ";
		cin >> file;
	}
	ofstream fout(file, ios::app);
	if(!fout.is_open()){
		cout << "Unable to open file";
		return;
	}
	fout << str;
	fout.close();
}


/*********************************************************************
** Function:		display_output_option
** Description:		shows the menu for output method and ask user to choose
** Parameters:		none
** Pre-Conditions:	none
** Post-Conditions:	returns the user choice of output method
*********************************************************************/
char display_output_option(){
	char c;
	cout << "\nHow would you like the information displayed?\n" 
		<< "1. Print to screen (Press 1)\n" 
		<< "2. Print to file (Press 2)\n" 
		<< "Your Choice: ";
	cin >> c;
	return c;
}


/*********************************************************************
** Function:		display_sorted
** Description:		either output on terminal or file dependsing on user's choice
** Parameters:		spellbook* b, string status, int n_b, int order[], int sel
** Pre-Conditions:	each function called has to be specified for prompts
** Post-Conditions:	the correct information is displayed at the correct location
*********************************************************************/
void display_sorted(spellbook* b, string status, int n_b, int order[], int sel){
	char choice = display_output_option();
	string f;
	for(int i = 0; i < n_b; ++i){
		if(order[i] != -1){
			/*
			 * This one deals with function that is sorting by pages
			 */
			if(sel == 1 && choice == '1'){
				cout << b[order[i]].title << " " << b[order[i]].num_pages << endl;
			}
			else if(sel == 1 && choice == '2'){
				append_to(f, b[order[i]].title + " " + to_string(b[order[i]].num_pages) + "\n");
			}
			/*
			 * This deals with sosrt by avg succes rate and to have th correct error message,
			 *  we have to differentiate both.
			 */
			else if(sel == 3 && choice == '1'){
				cout << b[order[i]].title << " " << b[order[i]].avg_success_rate << endl;
			}
			else if(sel == 3 && choice == '2'){
				append_to(f, b[order[i]].title + " " + to_string(b[order[i]].avg_success_rate) + "\n");
			}
			else{
				cout << "Ivalid information display choice\n";
				break;
			}
		}
	}
	if(choice == '2')
		cout << "Appended requested information to file.\n";
}


/*********************************************************************
** Function:		make_order
** Description:		creates an ordered array of ints for use in other functions
** Parameters:		int n
** Pre-Conditions:	n denotes the size and the range
** Post-Conditions:	range from 0 until n -1
*********************************************************************/
int* make_order(int n){
	int *temp = new int[n];
	for(int i = 0; i < n; ++i){
		temp[i] = i;
	}
	return temp;
}


/*********************************************************************
** Function:		choice1
** Description:		fort by pages
** Parameters:		spellbook* book, string status, int n_b
** Pre-Conditions:	there are 8 spells, if not make a leep for order
** Post-Conditions:	finish sorting by pages
*********************************************************************/
void choice1(spellbook* book, string status, int n_b){
	int pos;
	int *order = make_order(n_b);
	for(int i = n_b - 1; i >=0; --i){
		for(int j = 0; j < i; ++j){
			if(book[order[j]].num_pages > book[order[j + 1]].num_pages){
				int temp = order[j];
				order[j] = order[j + 1];
				order[j + 1] = temp;
			}
		}
	}
	if(status == "Student"){
		for(int i = 0; i < n_b; ++i){
			for(int j = 0; j < book[order[i]].num_spells; j++){
				if(book[order[i]].s[j].effect == "poison" 
					|| book[order[i]].s[j].effect == "death"){
					order[i] = -1;
					break;
				}
			}
		}
	}
	display_sorted(book, status, n_b, order, 1);
	delete[] order;
}


/*********************************************************************
** Function:		choice2
** Description:		sort by effect
** Parameters:		spellbook* book, string status, int n_b
** Pre-Conditions:	status is either Student or is not
** Post-Conditions:	finish sorting by effect
*********************************************************************/
void choice2(spellbook* book, string status, int n_b){
	int pos;
	char choice = display_output_option();
	string f;
	status == "Student" ? pos = 0 : pos = 1;
	string spells[2][6] = {{"4", "bubble", "memory_loss", "fire"},
		{"6", "bubble", "memory_loss", "fire", "poison", "death"}};
	for(int i = 1; i < stoi(spells[pos][0]); i++){
		for(int j = 0; j < n_b; j++){
			for(int k = 0; k < book[j].num_spells; k++){
				if(spells[pos][i] == book[j].s[k].effect){
					if(choice == '1')
						cout << spells[pos][i] << " " << book[j].s[k].name << endl;
					else if(choice == '2'){
						append_to(f, spells[pos][i] + " " + book[j].s[k].name + "\n");
					}
					else{
						cout << "Ivalid information display choice\n";
						return;
					}

				}
			}
		}
	}
	if(choice == '2')
		cout << "Appended requested information to file.\n";
}


/*********************************************************************
** Function:		choice3
** Description:		sorts by averate success rate of the spells within the book
** Parameters:		spellbook* book, string status, int n_b
** Pre-Conditions:	it has 8 books, if not then for loop to enter order for the range
** Post-Conditions:	finish sorting it in order[]
*********************************************************************/
void choice3(spellbook* book, string status, int n_b){
	int pos;
	int *order= make_order(n_b);
	for(int i = n_b - 1; i >=0; --i){
		for(int j = 0; j < i; ++j){
			if(book[order[j]].avg_success_rate > book[order[j + 1]].avg_success_rate){
				int temp = order[j];
				order[j] = order[j + 1];
				order[j + 1] = temp;
			}
		}
	}
	if(status == "Student"){
		for(int i = 0; i < n_b; ++i){
			for(int j = 0; j < book[order[i]].num_spells; j++){
				if(book[order[i]].s[j].effect == "poison" 
					|| book[order[i]].s[j].effect == "death"){
					order[i] = -1;
					break;
				}
			}
		}
	}
	display_sorted(book, status, n_b, order, 3);
	delete[] order;
}


/*********************************************************************
** Function:		exit_prog
** Description:		exits the program
** Parameters:		wizard * wiz, spellbook *book, int n_b
** Pre-Conditions:	detele before exiting
** Post-Conditions:	quit from the program
*********************************************************************/
void exit_prog(wizard * wiz, spellbook *book, int n_b){
	delete_info(&wiz, &book, n_b);
	cout << "Good bye! CY@ POGWARTS\n";
	exit(0);
}


/*********************************************************************
** Function:		main_menu
** Description:		Displays main manu and ask user to choose
** Parameters:		none
** Pre-Conditions:	user is logged in
** Post-Conditions:	returns the option user wants
*********************************************************************/
char main_menu(){
	char usr;
	while(true){
		cout << "\nWhich option would you like to choose?" << endl 
			<< "1. Sort spellbooks by number of pages" << endl 
			<< "2. Group spells by their effect " << endl 
			<< "3. Sort spellbooks by average success rate " << endl 
			<< "4. Quit " << endl << "Your Choice: ";
		cin >> usr;
		return usr;
	}
}