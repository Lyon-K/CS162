/******************************************************
** Program: 	run_wizard.cpp
** Author: 		Lyon Kee
** Date: 		04/13/2020
** Description: Assignment 1, sort spells and books
** Input: 		2 files by command line(wizards.txt & spellbooks.txt)
** Output: 		sorted by effect, pages, or avg success rate
					by terminal or file
******************************************************/
#include <iostream>
#include <string.h>
#include <cstdlib>
#include <fstream>
#include "catalog.h"
using namespace std;

int main(int argc, char* argv[]){
	int usr, n, n_books;
	wizard* wiz;
	spellbook *book;
	/*
	 * Innitializes all sstructs
	 */
	init(n, argc, argv[0], argv[1], argv[2], &wiz, &book, n_books);
	/*
	 * If logged in, by providing the correct ID and Password, we allow the
	 * user to enter into the main menu to allow them to sort in 3 methods
	 * until the user chooses to quit from the program by entering 4
	 */
	if(loggedin(wiz, n, usr)){
		while(true){
			char choice = main_menu();
			/*
			 * Runs choice1() if the user chooses to run option 1
			 * which is to sort by pages, where we pass in its position
			 * title to control their scope.
			 */
			if(choice == '1')
				choice1(book, wiz[usr].position_title, n_books);
			/*
			 * Runs choice2() if the user chooses to run option 2
			 * which is to sort by effect, where we pass in its position
			 * title to control their scope.
			 */
			else if(choice == '2')
				choice2(book, wiz[usr].position_title, n_books);
			/*
			 * Runs choice3() if the user chooses to run option 3
			 * which is to sort by avg success rate, where we pass in its 
			 * position title to control its scope.
			 */
			else if(choice == '3')
				choice3(book, wiz[usr].position_title, n_books);
			/*
			 * Runs exit_prog() file to exit from the program as per requested.
			 * After the call, we will go into deleting allocated heaps.
			 */
			else if(choice == '4')
				exit_prog(wiz, book, n_books);
			/*
			 * Provide error message for when input is invalid
			 */
			else
				cout <<"invalid input! Try again.\n\n";
		}
	}
	return 0;
}