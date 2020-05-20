#include <iostream>
#include "Time.h"
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
	return !(min==other.min||sec==other.sec);
}
bool time::operator<(const time& other) const
{
	if (min < other.min) return true;
	else if (min == other.min && sec < other.sec) return true;
	else return false;
}
bool time::operator>(const time& other) const
{
	if (min > other.min) return true;
	else if (min == other.min && sec > other.sec) return true;
	else return false;
}
bool time::operator==(const time& other)
{
	return min == other.min && sec == other.sec;
}
time time::operator/(const time& other)
{
	int temp1 = min * 60 + sec;
	int temp2 = other.min * 60 + other.sec;
	time t;
	t.min = (temp1 / temp2) / 60;
	t.sec = (temp1 / temp2) % 60;
	return t;
}
time time::operator/(const int& other)
{
	int temp1 = min * 60 + sec;
	time t;
	t.min = (temp1 / other) / 60;
	t.sec = (temp1 / other) % 60;
	return t;
}