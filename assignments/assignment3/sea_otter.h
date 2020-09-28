/*********************************************************************
** Program Filename:    sea_otter.h
** Author:              Lyon Kee
** Date:                5/10/2020
** Description:         contains values for being a Sea Otter("is a" animal)
** Input:               -
** Output:              -
*********************************************************************/
#ifndef SEA_OTTER_H
#define SEA_OTTER_H
#include "animal.h"

#include <iostream>
#include <string.h>

using namespace std;


class Sea_otter: public Animal{
public:
   /*********************************************************************
   ** Function:         Sea_otter()
   ** Description:      default constructor of Sea_otter
   ** Parameters:       -
   ** Pre-Conditions:   declaration of default Sea_otter
   ** Post-Conditions:  creates default Sea_otter
   *********************************************************************/
    Sea_otter();
   /*********************************************************************
   ** Function:         Sea_otter(string)
   ** Description:      non-default constructor of Sea_otter
   ** Parameters:       -
   ** Pre-Conditions:   declaration of non-default Sea_otter
   ** Post-Conditions:  creates a non-default Sea_otter
   *********************************************************************/
    Sea_otter(string);
   /*********************************************************************
   ** Function:         Sea_otter()
   ** Description:      default destructor of Sea_otter
   ** Parameters:       -
   ** Pre-Conditions:   destructing of Sea_otter
   ** Post-Conditions:  destructs Sea_otter
   *********************************************************************/
    ~Sea_otter();
};


#endif