#include <iostream>
#include <string>
#include "book.h"
using namespace std;
book::book()
{
	title = "";
	author = "";
	year = 0;
	cout << "constructor bez paramentrov dlya objecta " << this << "\n";
}
book::book(string T, string A, int Y)
{
	title = T;
	author = A;
	year = Y;
	cout << "constructor s parametrami dlya objecta " << this << "\n";
}
book::book(const book& b)
{
	title = b.title;
	author = b.author;
	year = b.year;
	cout << "constructor copirovaniya dlya objecta " << this << "\n";
}
book::~book()
{
	cout << "destructor dlya objecta " << this << "\n";
}
string book::Gettitle()
{
	return title;
}
string book::Getauthor()
{
	return author;
}
int book::Getyear()
{
	return year;
}
void book::Settitle(string T)
{
	title = T;
}
void book::Setauthor(string A)
{
	author = A;
}
void book::Setyear(int Y)
{
	year = Y;
}
void book::show()
{
	cout << "nazvanie " << title << "\n";
	cout << "avtor " << author << "\n";
	cout << "god izdaniya " << year << "\n";
}