#pragma once
#include <iostream>
#include "Object.h"
#include "Person.h"
using namespace std;
class Emloyee : public Person
{
protected:
	float salary;
	string position;
public:
	Emloyee(void);
	~Emloyee(void);
	void Show();
	void ShowElem();
	void Input();
	Emloyee(string, int, string, float);
	Emloyee(const Emloyee&);
	float GetSalary() { return salary; }
	string GetPosition() { return position; }
	void SetSalary(float);
	void SetPosition(string);
	Emloyee& operator=(const Emloyee&);
};