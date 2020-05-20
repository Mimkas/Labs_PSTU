#include <iostream>
#include "Object.h"
#include "Person.h"
#include "Emloyee.h"
#include "Vector.h"
using namespace std;
Vector::Vector()
{
}
Vector::Vector(int n)
{
	beg = new Object * [n];
	cur = 0;
	size = n;
}
Vector::~Vector(void)
{
	if (beg != 0)delete[] beg;
	beg = 0;
}
void Vector::Add(Object* o)
{
	if (cur < size)
	{
		beg[cur] = o;
		cur++;
	}
}
void Vector::Add()
{
	Object* o;
	cout << "1.Person\n2.Emloyee\n";
	int y;
	cin >> y;
	if (y == 1)
	{
		Person* p = new (Person);
		p->Input();
		o = p;

		if (cur < size)
		{
			beg[cur] = o;
			cur++;
		}
	}
	else if (y == 2)
	{
		Emloyee* e = new Emloyee;
		e->Input();
		o = e;
		if (cur < size)
		{
			beg[cur] = o;
			cur++;
		}
	}
	else return;
}
void Vector::Show()
{
	if (cur == 0) cout << "Empty\n";
	Object** o = beg;
	for (int i = 0;i < cur;i++)
	{
		(*o)->Show();
		o++;
	}
}
void Vector::ShowElem()
{
	if (cur == 0) cout << "Empty\n";
	Object** o = beg;
	for (int i = 0;i < cur;i++)
	{
		(*o)->ShowElem();
		o++;
	}
}
int Vector::operator() ()
{
	return cur;
}
void Vector::Del()
{
	if (cur == 0)return;
	cur--;
}
void Vector::GetName(int k)
{
	k = k - 1;
	if (cur == 0 || k >= cur) cout << "\nError - number > size\n";
	else
	{
		Object** o = beg;
		for (int i = 0;i < cur;i++)
		{
			if (k == i) cout << "\n Name is:\t" << (*o)->GetName() << "\n";
			o++;
		}
	}
}