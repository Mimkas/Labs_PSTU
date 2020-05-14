#include "vector.h"
#include <iostream>

using namespace std;

int main()
{
	Vector a(5);
	cout << "Vector A \n" << a << "\n";
	cout << "Vvedite 5 chisel Vectora A\n";
	cin >> a;
	cout << a << "\n";
	a[2] = 100;
	cout << a << "\n\n";
	Vector b(5);
	cout << "Vector B \n" << b << "\n";
	cout << "Vvedite 5 chisel Vectora B\n";
	cin >> b;
	Vector c(5); 
	cout << "\nA + B\n";
	c = a + b;
	cout << c << "\n";
	cout << "\nRazmer vectora C=" << c() << "\n";
	cout << *(a.first()) << "\n";
	Iterator i = a.first();
	cout << *i << "\n";
	cout << "\n(*i)+3 = " << (*i) + 3 << "\n";
	for (i = a.first(); i != a.last(); ++i)
	cout << *i << "\n";
	return 0;
}