Name: Lyon
ONID: 934057854
Section: CS 162-020
Assignment 5, due 6/7/2020

Description:

Welcome to the Linked List sorting program!There are 9 methods namely
get_length, clear, push_front, push_back, insert, sort_ascending,
sort_descending, count_prime. The tests is already written out in int main();

Instructions:

1) Compile the program with

make

2) Run the program with

./assignment5

3) Ensure the Linked list is defined as such: 
		Linekd_List<<data_type>> <variable name>

4) The series of tests begins with creating a linked list of type long int
because the class Linekd_List is templated, a test is then ran on get_length
to ensure the value of 0,  then 5 elements is pushed to the front of the linked
list namely: 5, 100, 0, -8, 16; expecting a printed linked list of 16 -8 0 100 5,
and a length of 5. Secondly, we push back 5, 1, 2, 7, 7919 which should print out
a linked list of 16 -8 0 100 5 5 1 2 7 7919 and length 10. Thirdly, the insert 
method is tested by inserting 11 at index 0; 20 at index 100; 50 at index 
l.get_length(); 9 at index 5. Next we test both sort ascending and descending,
expecting -8 0 1 2 5 5 7 9 11 16 50 100 7919, and 7919 100 50 16 11 9 7 5 5 2 1 0 -8
respectively. After that we'll procede to count the number to primes in the linked list
which should be 6. and Finally clear all nodes of the linked list, which should result 
in a linekd list of no nodes, length of 0, as well as no memory leaked or lost.


4) Limitations:
- There is no interface so you cannot choose to add another item halfway through
	run time
- The entire linked list have to be of one single data type and different nodes 
	of the same linked list cannot have different types, for example, a linked 
	list of head->int->long int->char->float->NULL and so on is not possible.

5) Extra credit:
- This program allows you to have a linked list of different type instead of just ints, 
- This program's sort descending method is done through a recursive selection sort

The Linekd_List method before you are:
1: int get_length()
2: void print()
3: void clear()
4: void push_front(int val)
5: void push_back(int val)
6: void insert(int val, unsigned int index)
7: void sort_ascending()
8: void sort_descending()
9: unsigned int count_prime()

Algorithm naalysis:
	merge sort:
		breaks all nodes to individual nods then compare the node and assign
			it back into a LL, this is done because there will be lesser repetition
			as compared to looping every node a more than once which results in a
			time complexity of O(n^2) or power 3 or higher

	selection sort:
		we loop through all elements of a LL then brings the largest or smallest node 
			to the front while linking back the nodes after the one removed, after the 
			first iteration we find that 1 element is in order, as the iterations follow 
			more and more is being sorted into the front. Therefore we see a sorted and 
			unsorted part of a LL in one single LL.

Complexity Analysis:
	a. sort_ascending()		O(nlogn)
			spliting all elements would result in an iteration from the firs to last which is
				O(n) and then merging the elements would be half of that which makes it O(logn)
				and thus the complexity is given by O(nlogn)

	b. sort_descending()		O(n^2)
		we loop through all elements once then again t find the Max which results in 2N
		and the next iteration would be n-1 + n-1 and so on until 2 + 2 and 1 + 1.
		after simplification of O(4n^2) we arrive at O(n^2)

	c. count_prime()			O(n^2)
		we loop through every element which is O(n) and at every element we loop from 2 
			until the element's value to check if anythin's divisible which is another O(n)
			after optimization to loop until half of the value we get O(n/2) and after optimization 
			to increment by 2 to skip all even number checks we arrive at O(n/4) which becomes
			O(n*(n/4)) which is O(n^2);

References:
	https://www.geeksforgeeks.org/merge-sort-for-linked-list/
