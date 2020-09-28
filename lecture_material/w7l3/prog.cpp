#include <iostream>
#include <vector>
#include "custom_array.hpp"

using namespace std;


template <class T>
const T& minimum(const T& x, const T& y){
	//check and return the smaller value
	if (x < y)
		return x;
	else 
		return y;

	//return (x<y)? x:y;
}

int main(int argc, char const *argv[])
{
	
	int i = minimum(3, 9); // i will be 3
	cout << "minimum(3, 9) is: " << endl;
	cout << i << endl;

	double d = minimum(2.56, 2.718); // d will be 2.56
	cout << "minimum(2.56, 2.718) is:  " << endl;
	cout << d << endl;

	Custom_Array<double> arr(10);
	for (int i = 0; i < arr.getLength(); ++i)
	{
		arr[i] = i*2.0;
	}
	cout << "value of arr at index 4 is: " << arr[4] << endl;



	vector<int> v;
	
	cout << "push back" << endl;
	for (int i = 0; i < 10; ++i)
	{
		v.push_back(i);
		cout << "Size: " << v.size() << endl;
		cout << "Capicity: " << v.capacity() << endl;
		cout <<"-------------------------" << endl;
	}

	cout << endl;
	cout << "pop back" << endl;
	for (int i = 0; i < 10; ++i)
	{
		v.pop_back();
		cout << "Size: " << v.size() << endl;
		cout << "Capicity: " << v.capacity() << endl;
		cout <<"-------------------------" << endl;
	}


	return 0;
}