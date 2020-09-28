/*********************************************************************************************
** Program Filename:	prog.cpp
** Author:				Lyon Kee
** Date:					5/25/2020
** Description:		includes the lfow of the program
** Input:				<int size of cave> <true/false for debug mode> as comand line argument
** Output:				-
*********************************************************************************************/


#include "Game.h"
#include "Empty.h"
#include <iostream>

using namespace std;

int main(int argc, char* argv[]){
	if(!CL_is_valid(argc, argv)){
		cout << "ERROR: Execute the program with 2 tags like so: " << argv[0] 
			<< " <int size of cave> <true/false for debug mode>\n";
		return 0;
	}
	Game game(atoi(argv[1]), stob(argv[2]));
	game.make_map();
	game.initialize();
	while(game.check_gameover()){
		// cout << endl;
		game.display_cave();
		game.display_perceptions();
		game.move();
		game.wumpus_move();
		game.evaluate_position();
		// cout << "\n\n\n";
	}
	game.display_cave();
	cout << "\nThe Wuuuuuuwuuwwumpus has ended!" << endl;//intended UwU
	return 0;
}