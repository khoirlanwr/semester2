#include <iostream>
using namespace std;

class Polygon {
	protected:
		int width, height;
	
	public:
		Polygon(int a, int b): width(a), height(b) {}
		virtual int area(void) = 0;
		void print() {
			cout << this->area() << endl;	
		};
};

class Rectangle: public Polygon {
	public:
		Rectangle(int a, int b): Polygon(a, b) {}
		int area() {
			return width* height;
		};
};

class Triangle: public Polygon {
	public:
		Triangle(int a, int b): Polygon(a, b) {}
		int area() {
			return width* height /2;
		}
};

int main() 
{
	
	Polygon* ppoly1 = new Rectangle(4, 6);
	Polygon* ppoly2 = new Triangle(9, 8);
		
	ppoly1->area(); 
	ppoly2->area();
	
	ppoly1->print();
	ppoly2->print();
	
	delete ppoly1;
	delete ppoly2;
	
	return 0;	
}
