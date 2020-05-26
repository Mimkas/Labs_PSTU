#pragma once
#include <iostream>
#include <fstream>
using namespace std;
class period
{
private:
	int year, month;
public:
	period() { year = 0; month = 0; }
	period(int m, int s) { year = m; month = s; year = year + month / 12; }
	period(const period& t) { year = t.year; month = t.month; }
	~period() {};
	int Getyear() { return year; }
	int Getmonth() { return month; }
	void Setyear(int m) { year = m; }
	void Setmonth(int s) { month = s; }
	period& operator=(const period&);
	period operator-(const period&);
	bool operator<(const period&) const;
	bool operator>(const period&) const;
	bool operator<=(const period& other);
	bool operator>=(const period& other);
	friend istream& operator>>(istream& in, period& t);
	friend ostream& operator<<(ostream& out, const period& t);
	bool operator!=(const period&);
	bool operator==(const period&);
	friend fstream& operator >> (fstream& fin, period& t);
	friend fstream& operator << (fstream& fout, const period& t);
};