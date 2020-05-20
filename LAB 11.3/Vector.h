#pragma once
#include <iostream>
#include <vector>
using namespace std;
template <class T>
class Vector
{
	vector <T> v;
	int len;
public:
	Vector(void);
	Vector(int n);
	~Vector(void);
	void Print();
	T Minsize();
	T Maxsize();
	void Add(T el);
	Vector<T> Del();
	void AddMinMaxSize();
};
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
	Vector<T>::Vector(int n)
	{
		T a;
		for (int i = 0;i < n;i++)
		{
			cin >> a;
			v.push_back(a);
		}
		len = v.size();
	}
	template <class T>
	void Vector<T>::Print()
	{
		for (int i = 0; i < v.size();i++)
			cout << v[i] << "\t";
		cout << "\n";
	}
	template <class T>
	T Vector<T>::Minsize()
	{
		T s = v[0];
			for (int i = 1;i < v.size();i++)
				if (s > v[i]) s = v[i];
		return s;
	}
	template <class T>
	T Vector<T>::Maxsize()
	{
		T s = v[0];
		for (int i = 1;i < v.size();i++)
			if (s < v[i]) s = v[i];
		return s;
	}
	template <class T>
	void Vector<T>::Add(T el)
	{
		v.push_back(el);
	}
	template <class T>
	Vector<T> Vector<T>::Del()
	{
		T key;
		cout << "Key?\n";
		cin >> key;
		int n;
		Vector<T> buf;
		for (int i = 0; i < v.size(); i++)
		{
			if (v[i] != key) 
			{
				buf.Add(v[i]);
			}
		}
		return buf;
	}
	template <class T>
	void Vector<T>::AddMinMaxSize()
	{
		T m = Minsize()+Maxsize();
		
		for (int i = 0;i < v.size();i++)
		{
			v[i] = v[i] + m;
		}
	}