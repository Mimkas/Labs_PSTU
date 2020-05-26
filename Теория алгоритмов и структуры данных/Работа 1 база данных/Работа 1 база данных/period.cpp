#include <iostream>
#include "period.h"
using namespace std;
period& period::operator=(const period& t)
{
	if (&t == this) return *this;
	year = t.year;
	month = t.month;
	return *this;
}
period period::operator-(const period& t)
{
	int temp1 = year * 12 + month;
	int temp2 = t.year * 12 + t.month;
	period p;
	p.year = (temp1 - temp2) / 12;
	p.month = (temp1 - temp2) % 12;
	if (p.year < 0 || p.month < 0) p.year = 0, p.month = 0;
	return p;
}
istream& operator>>(istream& in, period& t)
{
	cout << "year? "; in >> t.year;
	cout << "month? "; in >> t.month;
	return in;
}
ostream& operator<<(ostream& out, const period& t)
{
	return (out << t.year << " . " << t.month);
}

bool period::operator!=(const period& other)
{
	int temp1 = year * 12 + month;
	int temp2 = other.year * 12 + other.month;
	return !(temp1 == temp2);
}
bool period::operator==(const period& other)
{
	int temp1 = year * 12 + month;
	int temp2 = other.year * 12 + other.month;
	return temp1 == temp2;
}
fstream& operator >>(fstream& fin, period& t)
{
	fin >> t.year;
	fin >> t.month;
	return fin;
}
fstream& operator <<(fstream& fout, const period& t)
{
	fout << t.year << "\n" << t.month << "\n";
	return fout;
}
bool period::operator<(const period& other) const
{
	int temp1 = year * 12 + month;
	int temp2 = other.year * 12 + other.month;
	return temp1 < temp2;
}
bool period::operator<=(const period& other)
{
	int temp1 = year * 12 + month;
	int temp2 = other.year * 12 + other.month;
	return temp1 <= temp2;
}
bool period::operator>=(const period& other)
{
	int temp1 = year * 12 + month;
	int temp2 = other.year * 12 + other.month;
	return temp1 >= temp2;
}
bool period::operator>(const period& other) const
{
	int temp1 = year * 12 + month;
	int temp2 = other.year * 12 + other.month;
	return temp1 > temp2;
}