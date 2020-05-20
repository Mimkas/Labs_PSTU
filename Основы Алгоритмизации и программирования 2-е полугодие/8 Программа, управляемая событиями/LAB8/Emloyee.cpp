#include <iostream>
#include "Object.h"
#include "Person.h"
#include "Emloyee.h"
using namespace std;
Emloyee::Emloyee(void) :Person()
{
	salary = 0;
	position = "";
}
Emloyee::~Emloyee(void)
{
}
Emloyee::Emloyee(string n, int a, string p, float s) :Person(n, a)
{
	salary = s;
	position = p;
}
Emloyee::Emloyee(const Emloyee& E)
{
	name = E.name;
	age = E.age;
	position = E.position;
	salary = E.salary;
}
void Emloyee::SetSalary(float s)
{
	salary = s;
}
void Emloyee::SetPosition(string p)
{
	position = p;
}
Emloyee& Emloyee::operator=(const Emloyee& E)
{
	if (&E == this) return *this;
	name = E.name;
	age = E.age;
	position = E.position;
	salary = E.salary;
	return *this;
}
void Emloyee::Show()
{
	cout << "\nName:\t" << name;
	cout << "\nAge:\t" << age;
	cout << "\nposition:\t" << position;
	cout << "\nsalary:\t" << salary;
	cout << "\n";
}
void Emloyee::ShowElem()
{
	cout << "\nEmloyee\n";
}
void Emloyee::Input()
{
	cout << "\nName?\t";
	cin >> name;
	cout << "Age?\t";
	cin >> age;
	cout << "position?\t";
	cin >> position;
	cout << "salary?\t";
	cin >> salary;
	cout << "\n";
}