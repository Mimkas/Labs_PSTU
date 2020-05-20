#pragma once
#include "Time.h"
#include <iostream>
#include <set>
#include <iterator>
using namespace std;
template <class T>
class Vector
{
	set <pair<int,T>> v;
	int len;
	
public:
	Vector(void);
	Vector(int n);
	int GetLen();
	void Print();
	~Vector(void);
	void Add(T e);
	T Return(int n);
	T MinSizeElement();
	T MaxSizeElement();
	void DelElem();
	void AddMinMaxSize();
	void PrintVector();
};
template <class T>
void Vector <T>::PrintVector()
{
	for (int i = 0; i < GetLen(); i++)
	{
		time t = Return(i);
		cout << i << "\t" << t << "\n";
	}
}
template <class T>
int Vector<T>::GetLen()
{
	return len;
}
template <class T>
Vector<T>::Vector()
{
	len = 0;
}
template <class T>
Vector<T>::~Vector(void)
{
}
template <class T>
void Vector<T>::Add(T e)
{
	v.insert(make_pair(len,e));
	len++;
}
template <class T>
T Vector<T>::Return(int n)
{
	for (auto& item : v)
	{
		if (item.first == n) return item.second;
	}
}
template <class T>
T Vector<T>::MinSizeElement()
{
	T el = Return(0);
	for (int i = 0; i < len; i++)
	{
		if (el > Return(i)) el = Return(i);
	}
	return el;
}
template <class T>
T Vector<T>::MaxSizeElement()
{
	T el = Return(0);
	for (int i = 0; i < len; i++)
	{
		if (el < Return(i)) el = Return(i);
	}
	return el;
}
template <class T>
void Vector<T>::DelElem()
{
	cout << "put num elem, for search key\t";
	int num;
	cin >> num;
	while (num<len)
	{
		
		T el = Return(num);
		auto key = v.find(make_pair(num, el));
		v.erase(key);
		if (num != len-1)
		{
			el = Return(num+1);
			v.insert(make_pair(num, el));
		}
		num++;
	}
	len=v.size();
}
template <class T>
void Vector<T>::AddMinMaxSize()
{
	T summ = MinSizeElement() + MaxSizeElement();
	for (int i = 0;i < len;i++)
	{
		T el = Return(i);
		auto key = v.find(make_pair(i, el));
		v.erase(key);
		v.insert(make_pair(i, el + summ));
	}
}
