/*********************************************************************
** Program Filename:    monkey.h
** Author:              Lyon Kee
** Date:                5/10/2020
** Description:         contains values for being a monkey("is a" animal)
** Input:               -
** Output:              -
*********************************************************************/
#ifndef MONKEY_H
#define MONKEY_H
#include "animal.h"

#include <iostream>
#include <string.h>

using namespace std;


class Monkey: public Animal{
public:
   /*********************************************************************
   ** Function:         Monkey()
   ** Description:      default constructor of Monkey
   ** Parameters:       -
   ** Pre-Conditions:   declaration of default Monkey
   ** Post-Conditions:  creates default Monkey
   *********************************************************************/
    Monkey();
   /*********************************************************************
   ** Function:         Monkey(string)
   ** Description:      non-default constructor of Monkey
   ** Parameters:       -
   ** Pre-Conditions:   declaration of non-default Monkey
   ** Post-Conditions:  creates a non-default Monkey
   *********************************************************************/
    Monkey(string);
   /*********************************************************************
   ** Function:         Monkey()
   ** Description:      default destructor of Monkey
   ** Parameters:       -
   ** Pre-Conditions:   destructing of Monkey
   ** Post-Conditions:  destructs Monkey
   *********************************************************************/
    ~Monkey();
};


#endif