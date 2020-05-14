#pragma once
#include <iostream>
using namespace std;
class Pup
{
public:
	Pup(void)
	{}
	~Pup(void)
	{}
	virtual void Perimetr() = 0;
	virtual void Area() = 0;
	virtual void Show() = 0;
};
