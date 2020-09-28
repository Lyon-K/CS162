/*********************************************************************
** Program Filename:emp_hours.h
** Author:	Lyon
** Date:	4/27/2020
** Description:	structs for restaurant.cpp
** Input:	n/a
** Output:	n/a
*********************************************************************/
#ifndef EMP_HOURS_H
#define EMP_HOURS_H

#include <string>
using namespace std;
/*********************************************************************
** Function:employee
** Description:stores credentials for employee
** Parameters:-
** Pre-Conditions:-
** Post-Conditions:-
*********************************************************************/ 
struct employee {
  int id;
  string password;
  string first_name;
  string last_name;
};
/*********************************************************************
** Function:hours
** Description:stores the standard data grid for hours
** Parameters:-
** Pre-Conditions:-
** Post-Conditions:-
*********************************************************************/ 
struct hours {
  string day;
  string open_hour;
  string close_hour;
};


#endif