#include <iostream>
#include <string>
#include "book.h"
using namespace std;
book Newbook() 
{
	string p, o;
	int d;
	cout << "vvedite nazvanie:\n";
	cin >> p;
	cout << "vvedite avtora:\n";
	cin >> o;
	cout << "vvedite god izdaniya:\n";
	cin >> d;
	book b(p, o, d);
	return b;
}
void Coutbook(book b)
{
	b.show();
}
void main()
{
	book b1;
	b1.show();
	book b2("vsadnic bez golovi", "main rid", 1865);
	b2.show();
	book b3 = b2;
	b3.Settitle("aivengo");
	b3.Setauthor("valter skott");
	b3.Setyear(1819);
	Coutbook(b3);
	b1 = Newbook();
	b1.show();
}