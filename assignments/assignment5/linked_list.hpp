/*********************************************************************
** Program Filename:	node.hpp
** Author:				Lyon Kee
** Date:					6/8/2020
** Description:		LL methods that is performed on nodes
** Input:				-
** Output:				-
*********************************************************************/
#ifndef LINKED_LIST
#define LINKED_LIST

#include "node.hpp"

using namespace std;

template <class T>
class Linked_List {
private:
	unsigned int length; // the number of nodes contained in the list
	Node<T> *head; // a pointer to the first node in the list
	// anything else you need...
public:
	/*********************************************************************
	** Function:			Linked_List
	** Description:		default constructor
	** Parameters:			-
	** Pre-Conditions:	-
	** Post-Conditions:	creates a node
	*********************************************************************/ 
	Linked_List(){
		this->length = 0;
		this->head = NULL;
	}


	/*********************************************************************
	** Function:			~Linked_List
	** Description:		default desructor that frees memory
	** Parameters:			-
	** Pre-Conditions:	-
	** Post-Conditions:	frees a node memory
	*********************************************************************/ 
	~Linked_List(){
		this->clear();
		delete this->head;
	}
	

	/*********************************************************************
	** Function:			get_length
	** Description:		gets the length of the linked list
	** Parameters:			-
	** Pre-Conditions:	-
	** Post-Conditions:	returns the length
	*********************************************************************/ 
	// note: there is no set_length(unsigned int) (the reasoning should be intuitive)
	int get_length(){
			return this->length;
	}
	

	/*********************************************************************
	** Function:			print
	** Description:		prints the entire linked list
	** Parameters:			-
	** Pre-Conditions:	-
	** Post-Conditions:	-
	*********************************************************************/ 
	void print(){ // output a list of all integers contained within the list
		Node<T> *current = head;
		while(current != NULL){
			cout << current->val << " ";
			current = current->next;
		}
		cout << endl;
	}
	

	/*********************************************************************
	** Function:			clear
	** Description:		removes all nodes from the linked list
	** Parameters:			-
	** Pre-Conditions:	-
	** Post-Conditions:	-
	*********************************************************************/ 
	void clear(){ // delete the entire list (remove all nodes and reset length to 0)
		Node<T> *current = this->head;
		while(current != NULL){
			this->head = this->head->next;
			delete current;
			current = this->head;
		}
		this->length = 0;
	}
	

	/*********************************************************************
	** Function:			push_front
	** Description:		adds a node infront
	** Parameters:			int val
	** Pre-Conditions:	-
	** Post-Conditions:	adds a node of value val infront
	*********************************************************************/ 
	void push_front(int val){ // insert a new value at the front of the list 
		this->head = new Node<T>(val, this->head);
		this->length++;
	}
	

	/*********************************************************************
	** Function:			push_back
	** Description:		adds a node at the back
	** Parameters:			int val
	** Pre-Conditions:	-
	** Post-Conditions:	adds a node of value val at the end of the LL
	*********************************************************************/ 
	void push_back(int val){ // insert a new value at the back of the list 
		if(head == NULL){
			this->head = new Node<T>(val);
			this->length++;
			return;
		}
		Node<T> *current = this->head;
		for(;current->next != NULL; current = current->next);
		current->next = new Node<T>(val);
		this->length++;
	}
	

	/*********************************************************************
	** Function:			insert
	** Description:		adds a node at the specified index
	** Parameters:			int val, unsigned int index
	** Pre-Conditions:	-
	** Post-Conditions:	a node of value val is added to the specified index
	*********************************************************************/ 
	void insert(int val, unsigned int index){ // insert a new value in the list at the specified index 
		if(this->length < index){
			cout << "Error: Linked_List insert " << val << " at index " << index << ", out of range\n";
			return;
		}
		if(index == 0){
			this->head = new Node<T>(val, this->head);
			this->length++;
			return;
		}
		Node<T> *current = head;
		for(;index > 1; index--)
			current = current->next;
		current->next = new Node<T>(val, current->next);
		this->length++;
	}
	

	/*********************************************************************
	** Function:			FrontBackSplit
	** Description:		splits the LL into halves
	** Parameters:			Node<T>* source, Node<T>** frontRef, Node<T>** backRef
	** Pre-Conditions:	-
	** Post-Conditions:	splits the linked list in half
	** Explanation:		it iterates through the LL with a fast and slow which
									breaks it up into 2 LL with fast being larger than the
									LL slow by 1 element
	*********************************************************************/ 
	// sort the nodes in ascending order. You must implement the recursive Merge Sort algorithm
	// Note: it's okay if sort_ascending() calls a recursive private function to perform the sorting.
	void FrontBackSplit(Node<T>* source, Node<T>** frontRef, Node<T>** backRef){ 
		Node<T>* fast; 
		Node<T>* slow; 
		slow = source; 
		fast = source->next; 
	
		/* Advance 'fast' two nodes, and advance 'slow' one node */
		while (fast != NULL) { 
			fast = fast->next; 
			if (fast != NULL) { 
					slow = slow->next; 
					fast = fast->next; 
			} 
		} 
	
		/* 'slow' is before the midpoint in the list, so split it in two  
		at that point. */
		*frontRef = source; 
		*backRef = slow->next; 
		slow->next = NULL; 
	} 
  

	/*********************************************************************
	** Function:			SortedMerge
	** Description:		sorts the nodes according to the value
	** Parameters:			Node<T>* a, Node<T>* b
	** Pre-Conditions:	-
	** Post-Conditions:	sorted nodes are produced
	** Explanation:		This method merges the Sorted smaller LLs and adds
									the node to the LL named result, when it is all
									added to the result LL it is returned as 1 LL
	*********************************************************************/ 
	Node<T>* SortedMerge(Node<T>* a, Node<T>* b){ 
		Node<T>* result = NULL; 
		/* Base cases */
		if (a == NULL) 
			return b; 
		else if (b == NULL) 
			return a; 
	
		/* Pick either a or b, and recur */
		if (a->val <= b->val) { 
			result = a; 
			result->next = SortedMerge(a->next, b); 
		} 
		else { 
			result = b; 
			result->next = SortedMerge(a, b->next); 
		} 
		return result; 
	} 


	/*********************************************************************
	** Function:			MergeSort
	** Description:		recursive call method for merge sort
	** Parameters:			Node<T>** headRef
	** Pre-Conditions:	-
	** Post-Conditions:	merges the 2 linked list and assign it to another node
	** explanation:		this method first splits the LL into 2 halves namely a
									and b using the method FrontBackSplit recursively
									then merges the individual LLs created with MergeSort
									the final sorted LL is then combined with SortedMerge
									back into larger LLs
	*********************************************************************/ 
	void MergeSort(Node<T>** headRef){
		Node<T>* head = *headRef;
		Node<T>* a;
		Node<T>* b;
	
		/* Base case -- length 0 or 1 */
		if ((head == NULL) || (head->next == NULL)) { 
			return; 
		} 
	
		/* Split head into 'a' and 'b' sublists */
		FrontBackSplit(head, &a, &b);
	
		/* Recursively sort the sublists */
		MergeSort(&a);
		MergeSort(&b);
	
		/* answer = merge the two sorted lists together */
		*headRef = SortedMerge(a, b);
	}


	/*********************************************************************
	** Function:			sort_ascending
	** Description:		sort the linked list in ascending order
	** Parameters:			-
	** Pre-Conditions:	-
	** Post-Conditions:	the LL becomes sorted in ascending order
	*********************************************************************/ 
	void sort_ascending(){
		this->MergeSort(&this->head);
	}


	/*********************************************************************
	** Function:			find_max
	** Description:		looks for th maximum index in the linked list
	** Parameters:			Node<T> *current, int& max_val, int& max_index
	** Pre-Conditions:	-
	** Post-Conditions:	changes max_val and max_index to the corresponding max in the LL
	*********************************************************************/ 
	void find_max(Node<T> *current, int& max_val, int& max_index){
		max_val = current->val, max_index = 0;
		int i = 0;
		for(;current != NULL; current = current->next){
			if(current->val > max_val){
				max_val = current->val;
				max_index = i;
			}
			i++;
		}
	}


	/*********************************************************************
	** Function:			selection_sort
	** Description:		uses a recursive selection sort on LL
	** Parameters:			Node<T> *current, int i
	** Pre-Conditions:	-
	** Post-Conditions:	sorts the LL using selection sort
	*********************************************************************/ 
	void selection_sort(Node<T> *current, int i){
		// cout << "LL IS CURENTLY: ";
		// this->print();
		if(current->next->next == NULL)
			return;
		else{
			Node<T> *biggest = current, *prev;
			int max_val, max_index;
			this->find_max(current->next, max_val, max_index);
			max_index++;
			for(int j = 0; j < max_index; j++){
				prev = biggest;
				biggest = biggest->next;
			}
			prev->next = biggest->next;
			biggest->next = current->next;
			current->next = biggest;
			this->selection_sort(current->next, i+1);
		}
	}

	/*********************************************************************
	** Function:			sort_descending
	** Description:		sort the linked lsit in descending recursive selection sort
	** Parameters:			-
	** Pre-Conditions:	-
	** Post-Conditions:	sorts the LL in descending order
	*********************************************************************/ 
	// sort the nodes in descending order
	void sort_descending(){
		if(length < 2)
			return;

		Node<T> *current = head, *biggest = head, *prev;
		int max_val, max_index;
		this->find_max(head, max_val, max_index);
		for(int i = 0; i < max_index; i++){
			prev = biggest;
			biggest = biggest->next;
		}
		if(biggest != head){
			prev->next = biggest->next;
			biggest->next = head;
			head = biggest;
			cout << "PREV IS " << prev->val << endl;
			cout << "BIGGEST IS " << biggest->val << endl;
			cout << "CURRENT IS " << current->val << endl;
		}
		this->selection_sort(head, 0);
	}
	

	/*********************************************************************
	** Function:			count_prime
	** Description:		loops through all values and check if its prime and return
									the number of primes in the LL
	** Parameters:			-
	** Pre-Conditions:	-
	** Post-Conditions:	returns the number of primes in the LL
	*********************************************************************/ 
	//count and return the number of prime numbers within the list
	// you can add extra member variables or functions as desired
	unsigned int count_prime(){
		int n_primes = 0;
		Node<T> *current = head;
		for(; current != NULL; current = current->next){
			bool is_prime = true;
			if(current->val > 1){
				if(current->val%2 == 0 && current->val != 2){
					is_prime = false;
				}
				else{
					for(int i = 3; i < current->val/2; i += 2){
						if(current->val % i == 0){
							is_prime = false;
							break;
						}
					}
				}
				if(is_prime){
					n_primes++;
				}
			}
		}
		return n_primes;
	} 
};
#endif