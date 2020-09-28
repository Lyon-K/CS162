#include <iostream>
#include <cstdlib>

using namespace std;


int* merge(int* arr1, int size1, int* arr2, int size2){
	int* merged = new int[size1 + size2];
	int counter = 0;
	while(size1 != 0 && size2 != 0){
		if(*arr1 <= *arr2){
			merged[counter] = *arr1;
			arr1++;
			size1--;
			counter++;
		}
		if(*arr2 < *arr1){
			merged[counter] = *arr2;
			arr2++;
			size2--;
			counter++;
		}
	}
	while(size1 > 0){
		merged[counter] = *arr1;
		arr1++;
		size1--;
		counter++;
	}
	while(size2 > 0){
		merged[counter] = *arr2;
		arr2++;
		size2--;
		counter++;
	}
	return merged;
}


int* merge_sort(int* arr, int size){
	if(size == 1 || size == 0)
		return arr;
	int* arr1 = arr;
	int* arr2 = &arr[size/2];
	arr1 = merge_sort(arr1, size/2);
	arr2 = merge_sort(arr2, size - size/2);
	return merge(arr1, size/2, arr2, size - size/2);
}


bool is_prime(int n){
	if(n%2 == 0)
		return false;
	for(int i = 3; i < n/2; i += 2){
		if(n % i == 0)
			return false;
	}
	return true;
}


void print_primes(int* arr, int size){
	for(int i = 0; i < size; i++){
		if(is_prime(arr[i]))
			cout << arr[i] << " ";
	}
}


int main(){
	int count;
	do{
		cout << "Please enter the length of array you would like to have: ";
		cin >> count;
	}while(count < 0 || count > 20);
	int arr[count];
	cout << "\nThe array is: ";
	for(int i = 0; i < count; i++){
		arr[i] = rand()%50 + 1;
		cout << arr[i] << " ";
	}
	int* merge_sort_arr = new int[count];
	for(int i = 0; i < count; i++){
		merge_sort_arr[i] = arr[i];
	}
	merge_sort_arr = merge_sort(merge_sort_arr, count);
	cout << "\nThe sorted array is: ";
	for(int i = 0; i < count; i++){
		cout << merge_sort_arr[i] << " ";
	}
	cout << "\nThe primes are: ";
	print_primes(arr, count);	
	cout << endl;

	return 0;
}	
