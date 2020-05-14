#include <iostream>
#include "Pair.h"
#include "Pup.h"
using namespace std;
Pair& Pair::operator=(const Pair& other)
{
	if (&other == this) return *this;
	first = other.first;
	second = other.second;
	return *this;
}
Pair Pair::operator-(const Pair& other)
{
	Pair p;
	p.first = (first - other.first);
	p.second = (second - other.second);
	return p;
}
Pair Pair::operator+(const Pair& other)
{
	Pair p;
	p.first = (first + other.first);
	p.second = (second + other.second);
	return p;
}
Pair Pair::operator*(const Pair& other)
{
	Pair p;
	p.first = (first * other.first);
	p.second = (second * other.second);
	return p;
}
Pair Pair::operator/(const Pair& other)
{
	Pair p;
	p.first = (first / other.first);
	p.second = (second / other.second);
	return p;
}
bool Pair::operator!=(const Pair& other)
{
	return !(first == other.first && second == other.second);
}
bool Pair::operator==(const Pair& other)
{
	return first == other.first && second == other.second;
}
istream& operator>>(istream& in, Pair& p)
{
	cout << "first? "; in >> p.first;
	cout << "second?"; in >> p.second;
	return in;
}
ostream& operator<<(ostream& out, const Pair& p)
{
	return (out << p.first << "\t" << p.second);
}