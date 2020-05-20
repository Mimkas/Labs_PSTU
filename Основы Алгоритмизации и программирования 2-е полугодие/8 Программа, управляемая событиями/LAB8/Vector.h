#pragma once
#include <iostream>
#include "Object.h"
#include "Person.h"
#include "Emloyee.h"
using namespace std;
class Vector
{
protected:
	Object**beg;
	int size;
	int cur;
public:
	Vector();
	Vector(int);
	~Vector(void);
	void Add();
	void Add(Object* o);
	void Del();
	void Show();
	void ShowElem();
	void GetName(int k);
	int operator()();
};