/*********************************************************************
** Program Filename:    zoo.h
** Author:              Lyon Kee
** Date:                5/10/2020
** Description:         contains all values of a zoo as well as methods
** Input:               -
** Output:              -
*********************************************************************/
#ifndef ZOO_H
#define ZOO_H

#include <iostream>
#include <string.h>
#include <iomanip>

#include "monkey.h"
#include "sloth.h"
#include "sea_otter.h"
#include "moss_piglets.h"

class Zoo{
private:
    Animal **animals;
    float bank;
    int month;
    float base_food_cost;
    int num_monkeys;
    int monkeys_cap;
    int num_sloths;
    int sloths_cap;
    int num_sea_otters;
    int sea_otters_cap;
    int num_moss_piglets;
    int moss_piglets_cap;
    string food;
public:
   /*********************************************************************
   ** Function:         Zoo()
   ** Description:      default constructor of Zoo
   ** Parameters:       -
   ** Pre-Conditions:   declaration of default Zoo
   ** Post-Conditions:  creates default Zoo
   *********************************************************************/
    Zoo();
   /*********************************************************************
   ** Function:         Zoo()
   ** Description:      default destructor of Zoo
   ** Parameters:       -
   ** Pre-Conditions:   destructing of Zoo
   ** Post-Conditions:  destructs Zoo
   *********************************************************************/
    ~Zoo();

    float get_bank();
    int get_adult_monkeys();
    int get_adult_sloths();
    int get_adult_sea_otters();
    int get_adult_moss_piglets();
    
    int get_baby_monkeys();
    int get_baby_sloths();
    int get_baby_sea_otters();
    int get_baby_moss_piglets();


    void display_zoo();
    void add_monkey(string condition = "");
    void add_sloth(string condition = "");
    void add_sea_otter(string condition = "");
    void add_moss_piglets(string condition = "");
    void upsize(int,  int&, int);
    void initiate();
    void next_day();
    void buy_menu();
    void purchase(int, int);
    void food_choice();
    void display_food_info(string&);
    void daily_increments();
    float revenue();
    void sell_menu();
    void events(int);
    void sell(int);
    void sick_event();
    void birth_event();
    void extra_revenue_event();
    void sick(int);
};

bool rerun();

#endif