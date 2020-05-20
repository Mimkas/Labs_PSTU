#include <iostream>
#include "Object.h"
#include "Person.h"
using namespace std;
Person::Person(void)
{
	age = 0;
	name = "";
}
Person::Person(string n, int a)
{
	age = a;
	name = n;
}
Person::Person(const Person& Person)
{
	age = Person.age;
	name = Person.name;
}
Person::~Person(void)
{
}
void Person::SetName(string n)
{
	name = n;
}
void Person::SetAge(int a)
{
	age = a;
}
Person& Person::operator=(const Person &Person)
{
	if (&Person == this) return *this;
	age = Person.age;
	name = Person.name;
	return *this;
}
void Person::Show()
{
	cout << "\nName:\t" << name;
	cout << "\nAge:\t" << age;
	cout << "\n";
}
void Person::ShowElem()
{
	cout << "\nPerson\n";
}
void Person::Input()
{
	cout << "\nName?\t";
	cin >> name;
	cout << "Age?\t";
	cin >> age;
	cout << "\n";
}