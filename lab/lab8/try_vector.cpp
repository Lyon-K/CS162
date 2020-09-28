#include "vector.hpp"
#include <vector>
#include <iostream>

//We do not want to include either stmt. We wouldn't 
//be able to compare our vector template to the Standard 
//using namespace std;
//using std::vector;
using std::cout;
using std::endl;


int main (){
   vector<int> v;   //Our vector class
   std::vector<int> stdv; //Standard vector

   //Compare operation of our vector to std
   v.push_back(23);
   // cout << "push_back 1 -> capacity = " << v.capacity() << endl;
   v.push_back(1);
   // cout << "push_back 2 -> capacity = " << v.capacity() << endl;
   v.push_back(2);
   // cout << "push_back 3 -> capacity = " << v.capacity() << endl;
   v.push_back(3);
   // cout << "push_back 4 -> capacity = " << v.capacity() << endl;
   stdv.push_back(23);
   
   cout << "Our vector size: " << v.size() << endl;
   cout << "STL vector size: " << stdv.size() << endl;

   vector<int> temp = v;


   cout << "v[0] : " << v[0] << endl;
   cout << "v[1] : " << v[1] << endl;
   cout << "OUT OF BOUNDS:\n";
   cout << "v[300] : " << v[300] << endl;



   return 0;
}

