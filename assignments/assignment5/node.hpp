/*********************************************************************
** Program Filename:	node.hpp
** Author:				Lyon Kee
** Date:					6/8/2020
** Description:		node class to create nodes
** Input:				-
** Output:				-
*********************************************************************/
#ifndef NODE_H
#define NODE_H

#include <iostream>

template <class T>
class Node{
public:
	T val; // the value that this node stores
	Node *next; // a pointer to the next node in the list
	// you can add constructors or other functionality if you find it useful or necessary

	
	/*********************************************************************
	** Function:			Node
	** Description:		default constructor to initialize node
	** Parameters:			-
	** Pre-Conditions:	-
	** Post-Conditions:	-
	*********************************************************************/ 
	Node(){
		this->val = 0;
		this->next = NULL;
	}
	
	
	/*********************************************************************
	** Function:			Node
	** Description:		parametalized constructor to initialize val of node 
									and the next node
	** Parameters:			T val, Node* next = NULL
	** Pre-Conditions:	-
	** Post-Conditions:	val and next is set to argumetns passed in
	*********************************************************************/ 
	Node(T val, Node* next = NULL){
		this->val = val;
		this->next = next;
	};
};


#endif