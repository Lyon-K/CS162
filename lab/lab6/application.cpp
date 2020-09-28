#include "shape.h"
#include "rectangle.h"
#include "circle.h"
#include "square.h"

using namespace std;
int main(){
	Rectangle r1;
	 r1.display();
	 cout << endl;
	Rectangle r2(10, 2.5);
	 r2.display();
	 cout << endl;
	Circle c1;
	 c1.display();
	 cout << endl;
	Circle c2(10.5);
	 c2.display();
	 cout << endl;
	Square s1;
	 s1.display();
	 cout << endl;
	Square s2(2);
	 s2.display();
	 cout << endl;
}