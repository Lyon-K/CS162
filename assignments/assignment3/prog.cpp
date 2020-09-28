/******************************************************************************
** Program:       prog.cpp
** Author:        Lyon Kee
** Date:          05/01/2020
** Description:   runs the program
** Input:         -
** Output:        -
******************************************************************************/

#include "zoo.h"

int main(){
   srand(time(NULL));
   Zoo zoo;
   zoo.initiate();
   while(zoo.get_bank() >= 0 && rerun()){
      zoo.next_day();
   }
   cout << "\nYour progress is finalised as:\n";
   zoo.display_zoo();
   cout << "Thank you for playing!\nSee you again!\n";

   return 0;
}