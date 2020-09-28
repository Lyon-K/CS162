/*********************************************************************
** Program Filename:    moss_piglets.h
** Author:              Lyon Kee
** Date:                5/10/2020
** Description:         contains values for being a Moss Piglet("is a" animal)
** Input:               -
** Output:              -
*********************************************************************/
#ifndef MOSS_PIGLETS_H
#define MOSS_PIGLETS_H
#include "animal.h"

#include <iostream>
#include <string.h>

using namespace std;


class Moss_piglets: public Animal{
public:
   /*********************************************************************
   ** Function:         Moss_piglets()
   ** Description:      default constructor of Moss_piglets
   ** Parameters:       -
   ** Pre-Conditions:   declaration of default Moss_piglets
   ** Post-Conditions:  creates default Moss_piglets
   *********************************************************************/
    Moss_piglets();
   /*********************************************************************
   ** Function:         Moss_piglets(string)
   ** Description:      non-default constructor of Moss_piglets
   ** Parameters:       -
   ** Pre-Conditions:   declaration of non-default Moss_piglets
   ** Post-Conditions:  creates a non-default Moss_piglets
   *********************************************************************/
    Moss_piglets(string);
   /*********************************************************************
   ** Function:         Moss_piglets()
   ** Description:      default destructor of Moss_piglets
   ** Parameters:       -
   ** Pre-Conditions:   destructing of Moss_piglets
   ** Post-Conditions:  destructs Moss_piglets
   *********************************************************************/
    ~Moss_piglets();
};


#endif