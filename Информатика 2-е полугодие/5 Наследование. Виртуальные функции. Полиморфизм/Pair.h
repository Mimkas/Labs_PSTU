#pragma once
#include <iostream>
#include "Pup.h"
using namespace std;
class Pair:public Pup
{

public:
	int first, second;
	Pair() { first = 0; second = 0; }
	Pair(int f, int s) { first = f; second = s; }
	Pair(const Pair& p) { first = p.first; second = p.second; }
	~Pair() {};
	int Getfirst() { return first; }
	int Getsecond() { return second; }
	void Setfirst(int f) { first = f; }
	void Setsecond(int s) { second = s; }
	Pair& operator=(const Pair&);
	Pair operator+(const Pair&);
	Pair operator-(const Pair&);
	Pair operator*(const Pair&);
	Pair operator/(const Pair&);
	bool operator==(const Pair&);
	bool operator!=(const Pair&);
	friend istream& operator >> (istream& in, Pair& p);
	friend ostream& operator << (ostream& out, const Pair& p);
	void Perimetr() override
	{
		cout << "\nPerimetr is\n" << first + second;
	}
	void Area() override
	{
		cout << "\nArea is\n" << (first * second)/2;
	}
	void Show() override
	{
		cout << "\nPair:\nfirst\n" << first << "\nsecond\n" << second;
	}
};