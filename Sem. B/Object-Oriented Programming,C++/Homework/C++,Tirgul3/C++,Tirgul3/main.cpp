#include <iostream>
#include <conio.h>
#include <math.h>
#include "Circle.h"
using namespace std;




void main() {
	Circle c1(2.5,3.5,10);
	cout <<"Area is:" <<c1.calcArea()<<". perimeter is:"<< c1.calcperimeter()<< endl;
	Circle c2(15);
	cout << "Area is:" << c2.calcArea() << ". perimeter is:" << c2.calcperimeter() << endl;
	c1.printall();
	c2.printall();
	return;
}