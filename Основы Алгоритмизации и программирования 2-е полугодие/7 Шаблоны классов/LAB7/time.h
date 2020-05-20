#pragma once
#include <iostream>
using namespace std;
class time
{
private:
	int min, sec;
public:
	time() { min = 0; sec = 0; }
	time(int m, int s) { min = m; sec = s; }
	time(const time& t) { min = t.min; sec = t.sec; }
	virtual ~time(void) {};
	int Getmin() { return min; }
	int Getsec() { return sec; }
	void Setmin(int m) { min = m; }
	void Setsec(int s) { sec = s; }
	time& operator=(const time&);
	time operator-(const time&);
	friend istream& operator>>(istream& in, time& t);
	friend ostream& operator<<(ostream& out, const time& t);
	bool operator!=(const time&);
	time operator+(time k);
};
