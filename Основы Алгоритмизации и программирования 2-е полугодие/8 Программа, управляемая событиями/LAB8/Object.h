#pragma once
#include <iostream>
using namespace std;
class Object
{
public:
	Object(void)
	{
	}
	virtual string GetName() = 0;
	virtual void ShowElem() = 0;
	virtual void Show() = 0;
	virtual void Input() = 0;
	virtual ~Object(void)
	{
	}
};
