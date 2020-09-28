/******************************************************
** Program: catalog.h
** Author: Lyon Kee
** Date: 04/13/2020
** Description: struct declaration  & function prototyping
** Input: none
** Output: none
******************************************************/
using namespace std;



struct wizard {
	string name;
	int id;
	string password;
	string position_title;
	float beard_length;
};


struct spellbook {
	string title;
	string author;
	int num_pages;
	int edition;
	int num_spells;
	float avg_success_rate;
	struct spell *s;
};


struct spell {
	string name;
	float success_rate;
	string effect;
};


spellbook * create_spellbooks(int);
void populate_spellbook_data(spellbook *, int, ifstream &); 
spell * create_spells(int);
void populate_spell_data(spell *, int, ifstream &); 
void delete_info(wizard **, spellbook **, int);

void init(int&, int, string, string, string, wizard**, spellbook**, int&);
wizard * populate_wizard_data(int n, ifstream &fin);
void terminal_arg_is_valid(int c, string arg0, string arg1, string arg2);
int get_count(ifstream &, string);
string check_id(string prompt, string err_Message);
void show_char(wizard* w, int index);
bool loggedin(wizard*, int, int&);
void append_to(string &file, string str);
char display_output_option();
void display_sorted(spellbook*, string, int, int[], int);
int* make_order(int n);
void choice1(spellbook* book, string status, int n_b);
void choice2(spellbook*, string, int);
void choice3(spellbook*, string, int);
void exit_prog(wizard * wiz, spellbook *book, int n_b);
char main_menu();