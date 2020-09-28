/*********************************************************************
** Program Filename:    sloth.h
** Author:              Lyon Kee
** Date:                5/10/2020
** Description:         contains values for being a Sloth("is a" animal)
** Input:               -
** Output:              -
*********************************************************************/
#ifndef SLOTH_H
#define SLOTH_H
#include "animal.h"

#include <iostream>
#include <string.h>

using namespace std;


class Sloth: public Animal{
public:
   /*********************************************************************
   ** Function:         Sloth()
   ** Description:      default constructor of Sloth
   ** Parameters:       -
   ** Pre-Conditions:   declaration of default Sloth
   ** Post-Conditions:  creates default Sloth
   *********************************************************************/
   Sloth();
   /*********************************************************************
   ** Function:         Sloth(string)
   ** Description:      non-default constructor of Sloth
   ** Parameters:       -
   ** Pre-Conditions:   declaration of non-default Sloth
   ** Post-Conditions:  creates a non-default Sloth
   *********************************************************************/
   Sloth(string);
   /*********************************************************************
   ** Function:         Sloth()
   ** Description:      default destructor of Sloth
   ** Parameters:       -
   ** Pre-Conditions:   destructing of Sloth
   ** Post-Conditions:  destructs Sloth
   *********************************************************************/
   ~Sloth();
};


#endif