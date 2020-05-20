#pragma once
#pragma once
#include <iostream>
#include <queue>
#include <vector>
using namespace std;
template <class T>
class Vector
{
	queue <T> q;
	vector <T> v;
	int len;
public:
	Vector(void);
	Vector(int n);
	~Vector(void);
	void Print();
	void CopyQueueToVector();
	void CopyVectorToQueue();
	void DeleteElem();
	void AddMinMaxElem();
	T MinSize();
	T MaxSize();
	void Add(T el);
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
		CopyVectorToQueue();
		while (!q.empty())
		{
			cout << q.front() << "\t";
			q.pop();
		}
		cout << "\n";
		CopyVectorToQueue();
	}
	template <class T>
	void Vector<T>::CopyQueueToVector()
	{
		while (!v.empty())
		{
			v.pop_back();
		}
		while (!q.empty())
		{
			v.push_back(q.front());
				q.pop();
		}
	}
	template <class T>
	void Vector<T>::CopyVectorToQueue()
	{
		while (!q.empty())
		{
			q.pop();
		}
		for (int i = 0; i < v.size(); i++)
		{
			q.push(v[i]);
		}
	}
	template <class T>
	T Vector<T>::MinSize()
	{
		T t = v[0];
		for (int i = 1; i < v.size(); i++)
		{
			if (t > v[i]) t = v[i];
		}
		return t;
	}
	template <class T>
	T Vector<T>::MaxSize()
	{
		T t = v[0];
		for (int i = 1; i < v.size(); i++)
		{
			if (t < v[i]) t = v[i];
		}
		return t;
	}
	template <class T>
	void Vector<T>::Add(T el)
	{
		v.push_back(el);
		CopyVectorToQueue();
	}
	template <class T>
	void Vector<T>::DeleteElem()
	{
		T key;
		cout << "Key?\n";
		cin >> key;
		CopyVectorToQueue();
		for (int i = 0; i < v.size(); i++)
		{
			if (q.front() != key)
			{
				q.push(q.front());
			}
			q.pop();
		}
		CopyQueueToVector();
	}
	template <class T>
	void Vector <T>::AddMinMaxElem()
	{
		CopyVectorToQueue();
		T t = MinSize() + MaxSize();
		for (int i = 0;i < v.size();i++)
		{
			q.push(q.front() + t);
			q.pop();
		}
		CopyQueueToVector();
	}
