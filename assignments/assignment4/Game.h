#ifndef GAME_H
#define GAME_H

#include <vector>
#include <cstdlib>
#include <time.h>
#include <string>
#include "Room.h"
#include "Wumpus.h"
#include "Bats.h"
#include "Pit.h"
#include "Gold.h"
#include "Empty.h"

using namespace std;

class Game{
	protected:
		vector<vector<Room> > map;
		int arrows;
		int player_x;
		int player_y;
		int size;
		bool gold;
		int escape_x;
		int escape_y;
		int gold_x;
		int gold_y;
		int wumpus_x;
		int wumpus_y;
		bool debug;
		bool dead;
		bool wumpus_dead;

	public:
		Game();
		Game(int, bool);
		void initialize();
		void load_player(int, int);
		void make_map();
		void display_cave();
		void get_empty_coords(int&, int&);
		void move();
		void auto_play();
		void evaluate_position();
		void shoot();
		void mark_wumpus();
		void shoot_at(char);
		void wumpus_move();
		bool check_gameover();
		bool again(string);
		void clear_map();
		void reset_values(string);
		void display_perceptions();
};


#endif