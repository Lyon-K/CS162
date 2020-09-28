#include <iostream>
#include <string>

#include <exception> // base class for all other exceptions
#include <stdexcept> // where out_of_range is
#include <new> // where bad_alloc is

using namespace std;

class Divide_By_Zero_Exception : public exception
{
public:
	virtual const char* what() const throw(){
		return "Attempted to divide by zero";
	}
};


void funA() throw (out_of_range){
	throw bad_alloc();
}


float divide (float numerator, float denominator){
	string err = "Tried to divide by zero.";

	// if (denominator == 0)
	// 	throw err;

	if (denominator == 1)
		throw 1;

	if (denominator == 2)
		throw "some exception";

	if (denominator == 0)
		throw Divide_By_Zero_Exception();

	return numerator / denominator;
}



int main(int argc, char const *argv[])
{
	
	// float result = 0.0;
	
	// try{
	// 	// result = divide(5, 2);
	// 	// result = divide(5, 1);
	//		// result = divide(5, 0);
	// 	// result = divide (5, 2.5);
	// }

	// catch(char &e){
	// 	cout << "Error when dividing: " << e << endl;
	// }
	// catch(string& e){
	// 	cout << "Error when dividing: " << e << endl;
	// }
	// catch (int e){
	// 	cout << "int error: " << e << endl;
	// }
	// catch(Divide_By_Zero_Exception &e){
	// 	cout << "Error when dividing: " << e.what() << endl;
	// }
	// catch(...){ //default handler
	// 	cout << "some exception is thrown" << endl;
	// }


	// cout << result << endl;




	// string s;
	// char* str;

	// try{
	// 	str = new char[100000000000000000000000000];
	// 	cout << s.at(2) << endl; // throws out_of_range exception

	// }

	// catch(out_of_range &e){
	// 	cout << "You entered a bad index " << endl;
	// }

	// catch (bad_alloc &e){
	// 	cout << "You ran out of memory " << endl;
	// }


	// //farewell message
	// cout << "program is still running" << endl;



	// float result = 0.0;

	// try {
	// 	result = divide (5,0);
	// } 

	// // catch (Divide_By_Zero_Exception& e){
	// // 	cout << "Error when dividing: " << e.what() << endl;
	// // }

	// catch (exception& e){
	// 	cout << "Error when dividing exception: " << e.what() << endl;
	// }


	// try{
	// 	funA();
	// }
	// catch (bad_alloc& e){
	// 	cout << "error" << endl;
	// }

	return 0;
}