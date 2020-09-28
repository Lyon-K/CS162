/*********************************************************************************************
** Program Filename:	Game.cpp
** Author:				Lyon Kee
** Date:					5/25/2020
** Description:		Have al members required to run game as well as methods to do so
** Input:				-
** Output:				-
*********************************************************************************************/


#include "Game.h"


/*********************************************************************
** Function:			Game
** Description:		default constructor for game
** Parameters:			-
** Pre-Conditions:	-
** Post-Conditions:	creates and initializes a game 
*********************************************************************/ 
Game::Game(){
	this->arrows = 3;
	this->player_x = 0;
	this->player_y = 0;
	this->size = 0;
	this->gold = false;
	this->escape_x = 0;
	this->escape_y = 0;
	this->gold_x = -1;
	this->gold_y = -1;
	this->wumpus_x = -1;
	this->wumpus_y = -1;
	this->debug = false;
	this->dead = false;
	this->wumpus_dead = false;
}


/*********************************************************************
** Function:			Game
** Description:		default constructor for game
** Parameters:			int size, bool debug
** Pre-Conditions:	-
** Post-Conditions:	creates and initializes a game 
*********************************************************************/ 
Game::Game(int size, bool debug){
	this->arrows = 3;
	this->player_x = 0;
	this->player_y = 0;
	this->size = size;
	this->gold = false;
	this->escape_x = 0;
	this->escape_y = 0;
	this->gold_x = -1;
	this->gold_y = -1;
	this->wumpus_x = -1;
	this->wumpus_y = -1;
	this->debug = debug;
	this->dead = false;
	this->wumpus_dead = false;
}


/*********************************************************************
** Function:			initialize
** Description:		fill the board with events
** Parameters:			-
** Pre-Conditions:	game and cave is declared
** Post-Conditions:	initializes a game with values to run it
*********************************************************************/ 
void Game::initialize(){
	int x, y;
	srand(time(NULL));
	this->get_empty_coords(wumpus_x, wumpus_y);
	this->map[wumpus_y][wumpus_x].set_event("Wumpus");
	this->get_empty_coords(gold_x, gold_y);
	this->map[gold_y][gold_x].set_event("Gold");
	for(int i = 0; i < 2; i++){
		this->get_empty_coords(x, y);
		this->map[y][x].set_event("Bats");
		this->get_empty_coords(x, y);
		this->map[y][x].set_event("Pit");
	}
	this->get_empty_coords(x, y);
	this->load_player(x, y);
}
	
	
/*********************************************************************
** Function:			load_player
** Description:		sets aplayer location for the game
** Parameters:			int x, int y
** Pre-Conditions:	game and cave is declared
** Post-Conditions:	sets player location
*********************************************************************/ 
void Game::load_player(int x, int y){
	this->player_x = x;
	this->player_y = y;
	this->escape_x = x;
	this->escape_y = y;
}


/*********************************************************************
** Function:			make_map
** Description:		makes an empty cave of set size
** Parameters:			-
** Pre-Conditions:	-
** Post-Conditions:	creates a cave of all empty rooms
*********************************************************************/ 
void Game::make_map(){
	if(size > 3){
		this->map.resize(size, vector<Room> (size));
		this->clear_map();
	}
	else
		cout << "Incorrect size to make map" << endl;
}


/*********************************************************************
** Function:			display_cave
** Description:		displays the cave
** Parameters:			-
** Pre-Conditions:	-
** Post-Conditions:	-
** Justification:		the entire map is printed here so it is easily readible 
								within one function
*********************************************************************/ 
void Game::display_cave(){
	system("clear");
	cout << endl;
	for(int k = 0; k < map.size(); ++k){
		cout << " ---";
	}
	for(int i = 0; i < map.size(); i++){
		cout << "\n| ";
		for(int j = 0; j < map[i].size(); ++j){
			if(j == player_x && i == player_y){
				cout << "* | ";
			}
			else if(debug == true){
				cout << map[i][j].get_icon() << " | ";
			}
			else
				cout << "  | ";
		}
		cout << endl;
		for(int k = 0; k < map.size(); ++k){
			cout << " ---";
		}
	}
}


/*********************************************************************
** Function:			get_empty_coords
** Description:		find and returns an empty coordinate
** Parameters:			int &x, int &y
** Pre-Conditions:	-
** Post-Conditions:	returns empty coordinates of x and y
*********************************************************************/ 
void Game::get_empty_coords(int &x, int &y){
	do{
		x = rand()%this->size;
		y = rand()%this->size;
	}while(!this->map[y][x].is_empty_room());
}


/*********************************************************************
** Function:			move
** Description:		gets a key press and evaluate the more location
** Parameters:			-
** Pre-Conditions:	-
** Post-Conditions:	moves the person to specified location
*********************************************************************/ 
void Game::move(){
	char key = get_key();
	if(key == 'w'){
		if(player_y != 0)
			player_y--;
	}
	else if(key == 'a'){
		if(player_x != 0)
			player_x--;
	}
	else if(key == 's'){
		if(player_y != size - 1)
			player_y++;
	}
	else if(key == 'd'){
		if(player_x != size - 1)
			player_x++;
	}
	else if(key == ' '){
		this->shoot();
	}
	// else if(key == '~'){
	// 	this->auto_play();
	// }
}


/*********************************************************************
** Function:			auto_play
** Description:		plays the game for the player
** Parameters:			-
** Pre-Conditions:	-
** Post-Conditions:	-
*********************************************************************/ 
void Game::auto_play(){

}


/*********************************************************************
** Function:			evaluate_position
** Description:		performs the action of the player in their event
** Parameters:			-
** Pre-Conditions:	-
** Post-Conditions:	run individual encounters
*********************************************************************/ 
void Game::evaluate_position(){
	bool prev_gold = gold;
	while(!map[player_y][player_x].is_empty_room() && dead == false){
		map[player_y][player_x].run_encounter(size, dead, gold, player_x, player_y);
		if(prev_gold != gold){
			gold_x = player_x;
			gold_y = player_y;
			map[player_y][player_x].clear_event();
			map[player_y][player_x].set_event("Empty");
			
		}
	}
}


/*********************************************************************
** Function:			shoot
** Description:		shoots an arrow at a direction
** Parameters:			-
** Pre-Conditions:	-
** Post-Conditions:	determines if wumpus is killed after an arrow is shot
*********************************************************************/ 
void Game::shoot(){
	if(arrows > 0){
		char direction;
		do{
			cout << "Which direction would you like to shoot it at: ";
			system("stty raw");
			cin >> direction;
			system("stty cooked");
		}while(direction != 'w' && direction != 'a' && direction != 's' && direction != 'd');
		arrows--;
		if(wumpus_x == -1 && wumpus_y == -1){
			this->mark_wumpus();
		}
		this->shoot_at(direction);
	}
	else
		cout << "No arrows left" << endl;
}


/*********************************************************************
** Function:			mark_wumpus
** Description:		finds and store the location of wumpus
** Parameters:			-
** Pre-Conditions:	-
** Post-Conditions:	changes wumpus_x and wumpus_y to the location of wumpus
*********************************************************************/ 
void Game::mark_wumpus(){
	for(int i = 0; i < size; i++){
		for(int j = 0; j < size; j++){
			if(map[i][j].get_icon() == 'W')
				wumpus_x = j;
				wumpus_y = i;
		}
	}
}


/*********************************************************************
** Function:			shoot_at
** Description:		checks if wumpus is at the direction specified to shoot at
** Parameters:			-
** Pre-Conditions:	-
** Post-Conditions:	if wumpus is shot then kill it and empty the room
** Justification:		it is more readible to put the 4 directions of shoot 
								into the same function
*********************************************************************/ 
void Game::shoot_at(char direction){
	if(direction == 'w'){
		for(int i = this->player_y - 1; i >= 0; i--){
			if(this->map[i][player_x].get_icon() == 'W'){
				wumpus_dead = true;
				this->map[i][player_x].clear_event();
				this->map[i][player_x].set_event("Empty");
				break;
			}
		}
	}

	else if(direction == 'a'){
		for(int i = this->player_x - 1; i >= 0; i--){
			if(this->map[player_y][i].get_icon() == 'W'){
				wumpus_dead = true;
				this->map[player_y][i].clear_event();
				this->map[player_y][i].set_event("Empty");
				break;
			}
		}
	}

	else if(direction == 's'){
		for(int i = this->player_y + 1; i < this->size; i++){
			if(this->map[i][player_x].get_icon() == 'W'){
				wumpus_dead = true;
				this->map[i][player_x].clear_event();
				this->map[i][player_x].set_event("Empty");
				break;
			}
		}
	}

	else if(direction == 'd'){
		for(int i = this->player_x + 1; i < this->size; i++){
			if(this->map[player_y][i].get_icon() == 'W'){
				wumpus_dead = true;
				this->map[player_y][i].clear_event();
				this->map[player_y][i].set_event("Empty");
				break;
			}
		}
	}
}


/*********************************************************************
** Function:			wumpus_move
** Description:		75% chance of wumpus moving
** Parameters:			-
** Pre-Conditions:	-
** Post-Conditions:	moves the wumpus on a 75% chance
*********************************************************************/ 
void Game::wumpus_move(){
	int x, y;
	if(arrows < 3 && !wumpus_dead){
		if(rand()%4 != 0){
			this->get_empty_coords(x, y);
			for(int i = 0; i < this->size; i++){
				for(int j = 0; j < this->size; j++){
					if(this->map[i][j].get_icon() == 'W'){
						this->map[i][j].clear_event();
						this->map[i][j].set_event("Empty");
						break;
					}
				}
			}
			this->map[y][x].set_event("Wumpus");
		}
	}
}


/*********************************************************************
** Function:			check_gameover
** Description:		check if game ended or not
** Parameters:			-
** Pre-Conditions:	-
** Post-Conditions:	game ends
*********************************************************************/ 
bool Game::check_gameover(){
	if(dead || arrows == 0 && wumpus_dead == false){
		return this->again("lost");
	}
	else if(player_y == escape_y && player_x == escape_x && wumpus_dead == true && gold == true){
		return this->again("won");
	}
	return true;
}


/*********************************************************************
** Function:			again
** Description:		asks if user wants to end the game
** Parameters:			-
** Pre-Conditions:	an end game condition is met
** Post-Conditions:	either end the game or play again
*********************************************************************/ 
bool Game::again(string condition){
	system("clear");
	string usr;
	cout << "You've " << condition << " the Game!\nWould you like to play again(Yes/No)? ";
	cin >> skipws >> usr;
	if(usr == "Yes"){
		cout << "Would you like to create a new map(Yes/No)? ";
		cin >> usr;
		if(usr == "Yes"){
			this->clear_map();
			this->reset_values("hard");
			this->initialize();
		}
		else
			this->reset_values("soft");
		return true;
	}
	return false;
}


/*********************************************************************
** Function:			clear_map
** Description:		changes all room into empty rooms
** Parameters:			-
** Pre-Conditions:	-
** Post-Conditions:	whole cave is empty
*********************************************************************/ 
void Game::clear_map(){
	for(int i = 0; i < map.size(); ++i){
		for(int j = 0; j < map[i].size(); ++j){
			map[i][j].clear_event();
			map[i][j].set_event("Empty");
		}
	}
}


/*********************************************************************
** Function:			reset_values
** Description:		resets values to allow user to play again
** Parameters:			-
** Pre-Conditions:	-
** Post-Conditions:	hard reset or soft reset values
*********************************************************************/ 
void Game::reset_values(string reset){
	arrows = 3;
	gold = false;
	dead = false;
	wumpus_dead = false;
	player_x = escape_x;
	player_y = escape_y;
	if(reset == "hard"){
		this->gold_x = -1;
		this->gold_y = -1;
		this->wumpus_x = -1;
		this->wumpus_y = -1;
	}
	if(gold_x != -1 && gold_y != -1)
		this->map[gold_y][gold_x].set_event("Gold");
	if(wumpus_x != -1 && wumpus_y != -1)
		this->map[wumpus_y][wumpus_x].set_event("Wumpus");
}


/*********************************************************************
** Function:			display_perceptions
** Description:		shows adjacent perceptions
** Parameters:			-
** Pre-Conditions:	-
** Post-Conditions:	cout the error messages
*********************************************************************/ 
void Game::display_perceptions(){
	cout << endl;
	if(player_x + 1 < size){
		if(this->map[player_y][player_x+1].get_message() != "")
			cout << this->map[player_y][player_x+1].get_message() << endl;
	}
	if(player_y + 1 < size){
		if(this->map[player_y+1][player_x].get_message() != "")
			cout << this->map[player_y+1][player_x].get_message() << endl;
	}
	if(player_x - 1 >= 0){
		if(this->map[player_y][player_x-1].get_message() != "")
			cout << this->map[player_y][player_x-1].get_message() << endl;
	}
	if(player_y - 1 >= 0){
		if(this->map[player_y-1][player_x].get_message() != "")
			cout << this->map[player_y-1][player_x].get_message() << endl;
	}
}