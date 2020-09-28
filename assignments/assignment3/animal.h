/*********************************************************************
** Program Filename:    animal.h
** Author:              Lyon Kee
** Date:                5/10/2020
** Description:         stores the characteristics of an animal
** Input:               -
** Output:              -
*********************************************************************/
#ifndef ANIMAL_H
#define ANIMAL_H

#include <iostream>

class Animal{
protected:
    int age;
    float price;
    int births;
    float food_cost_percentage;
    float revenue;
    float cure_cost;
    float selling_price;
public:
   /*********************************************************************
   ** Function:         Animal()
   ** Description:      default constructor of Animal
   ** Parameters:       -
   ** Pre-Conditions:   declaration of default Animal
   ** Post-Conditions:  creates default Animal
   *********************************************************************/
    Animal();
   /*********************************************************************
   ** Function:         Animal(const Animal&)
   ** Description:      copy constructor of Animal
   ** Parameters:       -
   ** Pre-Conditions:   1 existing Animal
   ** Post-Conditions:  creates Animal with values of existing animal
   *********************************************************************/
    Animal(const Animal&);
   /*********************************************************************
   ** Function:         Animal& operator=(const Animal&)
   ** Description:      Assignment Operator Overload of Animal
   ** Parameters:       -
   ** Pre-Conditions:   2 existing Animal
   ** Post-Conditions:  changes 2nd Animal with values of existing animal
   *********************************************************************/
    Animal& operator=(const Animal&);
   /*********************************************************************
   ** Function:         Animal()
   ** Description:      default destructor of Animal
   ** Parameters:       -
   ** Pre-Conditions:   destructing of Animal
   ** Post-Conditions:  destructs Animal
   *********************************************************************/
    ~Animal();

    int get_age();
    float get_revenue();
    float get_selling_price();


    void increment_age();
};

#endif