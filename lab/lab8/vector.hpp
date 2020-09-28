#include <iostream>
#include <stdlib.h>
#include <string>
#include <stdexcept>

// using namespace std;
using std::string;
using std::cout;
using std::endl;

template <class T>
class vector {
   private:
      T *v;
      int s;
      int cap;
   public:
      vector(){
	     s = 0;
        v = new T[1];
        cap = 1;
      }
	  
      ~vector(){
	     delete [] v;
        v = NULL;
      }
	  
      vector(vector &other){
         // for(int i = 0; i < other.size() + 2; i++){
         //    cout << other[i] << endl;
         // }

         this->s = other.s;
         this->cap = other.cap;
         this->v = new T[other.cap];
         for(int i = 0; i < other.s; i++){
            // cout << "INDEX " << i << " added " << other.v[i] << endl;
            this->v[i] = other.v[i];
         }
      }

      void operator=(vector<T> &other){
         this->s = other.s;
         this->cap = other.cap;
         delete this->v;
         this->v = new T[cap];
         for(int i = 0; i < s; i++){
            this->v[i] = other.v[i];
         }
      }

      int size() {
	     return s;
      }

      int capacity(){
         return cap;
      }

      void push_back(T ele) {
         if(this->s >= this->cap){
            T *temp;
            temp = new T[this->cap *= 2];
            for(int i=0; i < s; i++)
               temp[i]=this->v[i];

            delete [] this->v;
            this->v=temp;
            temp = NULL;
         }
         this->v[s++]=ele;
         // cout << "ADDED " << this->v[s-1] << " to index " << s-1 << endl;
      }

      void reserve(int n){
         if(n > this->cap){
            T *temp = new T[n];
            for(int i = 0; i < this->s; i++){
               temp[i] = v[i];
            }
            delete[] v;
            v = temp;
            temp = NULL;
         }
      }

      void resize(int n){
         if(n > this->s){
            this->reserve(n);
            return;
         }
         T *temp = new T[n];
         for(int i = 0; i < n; i++){
            temp[i] = this->v[i];
         }
         this->s = n;
         delete[] this->v;
         this->v = temp;
         temp = NULL;
      }

      T operator[](int n) {
         return this->v[n]; //program breaks with error message
         // program continues displaying error message
         // try{
         //    return this->at(n);
         // }
         // catch(std::exception &e){
         //    cout << "Error when accessing index " << n << ": " << e.what() << endl;
         //    return 0;
         // }
      }

      T at(int n) {
         if(n >= this->s){
            throw std::out_of_range("out of my vector bounds");
         }
         return this->v[n];
      }

};
