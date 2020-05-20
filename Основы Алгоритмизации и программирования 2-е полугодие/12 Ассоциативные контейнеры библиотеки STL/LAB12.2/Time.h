#pragma once
#include <iostream>
using namespace std;
class time
{
private:
	int min, sec;
public:
	time() { min = 0; sec = 0; }
	time Randtime() { min = rand() % 60; sec = rand() % 60; return *this; }
	time(int m, int s) { min = m; sec = s; }
	time(const time& t) { min = t.min; sec = t.sec; }
	~time() {};
	int Getmin() { return min; }
	int Getsec() { return sec; }
	void Setmin(int m) { min = m; }
	void Setsec(int s) { sec = s; }
	time& operator=(const time&);
	time operator-(const time&);
	time operator+(const time&);
	time operator /(const time&);
	time operator /(const int&);
	friend istream& operator>>(istream& in, time& t);
	friend ostream& operator<<(ostream& out, const time& t);
	bool operator!=(const time&);
	bool operator <(const time&) const;
	bool operator >(const time&) const;
	bool operator==(const time&);
};
