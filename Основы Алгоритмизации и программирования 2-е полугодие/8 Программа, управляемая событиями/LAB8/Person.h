#pragma once
#include <iostream>
#include "Object.h"
using namespace std;
class Person :public Object
{
protected:
	string name;
	int age;
public:
	virtual ~Person(void);
	void Show();
	void ShowElem();
	void Input();
	Person(void);
	Person(string, int);
	Person(const Person&);
	string GetName() { return name; }
	int GetAge() { return age; }
	void SetName(string);
	void SetAge(int);
	Person& operator=(const Person&);

};