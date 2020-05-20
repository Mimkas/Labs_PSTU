#include <iostream>
#include "time.h"
using namespace std;
time& time::operator=(const time& t)
{
	if (&t == this) return *this;
	min = t.min;
	sec = t.sec;
	return *this;
}
time time::operator-(const time& t)
{
	int temp1 = min * 60 + sec;
	int temp2 = t.min * 60 + t.sec;
	time p;
	p.min = (temp1 - temp2) / 60;
	p.sec = (temp1 - temp2) % 60;
	return p;
}
time time::operator+(const time& t)
{
	int temp1 = min * 60 + sec;
	int temp2 = t.min * 60 + t.sec;
	time p;
	p.min = (temp1 + temp2) / 60;
	p.sec = (temp1 + temp2) % 60;
	return p;
}
istream& operator>>(istream& in, time& t)
{
	cout << "min? "; in >> t.min;
	cout << "sec? "; in >> t.sec;
	return in;
}
ostream& operator<<(ostream& out, const time& t)
{
	return (out << t.min << " : " << t.sec);
}

bool time::operator!=(const time& other)
{
	int temp1 = min * 60 + sec;
	int temp2 = other.min * 60 + other.sec;
	return !(temp1 == temp2);
}
bool time::operator<(const time& other)
{
	int temp1 = min * 60 + sec;
	int temp2 = other.min * 60 + other.sec;
	return temp1 < temp2;
}
bool time::operator>(const time& other)
{
	int temp1 = min * 60 + sec;
	int temp2 = other.min * 60 + other.sec;
	return temp1 > temp2;
}
bool time::operator==(const time& other)
{
	int temp1 = min * 60 + sec;
	int temp2 = other.min * 60 + other.sec;
	return temp1 == temp2;
}