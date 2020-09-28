#include <iostream>

using namespace std;

struct Node
{
	int val;
	Node* next;
};

void delete_ll(Node* node){
	if(node->next == NULL){	
		delete node;
	}
	else
	{
			delete_ll(node->next);
			delete node;
	}
}

int main(int argc, char const *argv[])
{
	Node* head = new Node;
	Node* current = head;
	int size = 3;

	// Task 1: What does this code do?
	// Trace through the code and draw the picture out
	for (int i = 0; i < size; ++i){
		current->val = i+1;
		if (i == size-1)
			current->next = NULL;
		else{
			current->next = new Node;
			current = current->next;
		}
	}
	current = head;
	while(current != 0){
		cout << current->val << endl;
		current = current->next;
	}
	// delete_ll(head);
	// head = NULL;
	while(current != NULL){
		Node* temp = current->next;
		delete current;
		current = temp;
	}
	head = NULL;


	return 0;
}