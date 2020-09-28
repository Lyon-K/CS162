#include "shape.h"
#include "circle.h"
#include "square.h"

using namespace std;
int main(){
	Rectangle r;
	Rectangle r_p(10, 2.5);
	Shape *r1 = &r, *r2 = &r_p;
	// Shape *r1 = &r; 
	 print_shape_info(*r1);
	// Shape *r2 = &r_p;   
	 print_shape_info(*r2);
	 if (r1 > r2){
		 cout << "R1 is bigger than R2" << endl;
	 }
	 else
	 	cout << "IT IS NOT\n";
	//  cout << "AREAS:\n";
	//  cout << r2->area() << endl;
	//  cout << r.area() << endl;
	//  cout << r1->area() << endl;
	//  cout << r_p.area() << endl;

	// Circle c1;
	//  c1.display();
	//  cout << "@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@" << endl;
	// Circle c2(10.5);
	//  c2.display();
	//  cout << "############################################" << endl;
	// Square s1;
	//  s1.display();
	//  cout << "$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$" << endl;
	// Square s2(2);
	//  s2.display();
	//  cout << "^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^" << endl;
	return 0;
}