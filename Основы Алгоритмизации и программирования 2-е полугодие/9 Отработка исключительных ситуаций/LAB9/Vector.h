#pragma once
#include <iostream>
#include "Error.h"
using namespace std;
const int MAX_SIZE = 20;
class Vector
{
	int size;
	int* data;
public:
	Vector() { size = 0;data = 0; }
	Vector(int s);
	Vector(int s, int* mas);//не работает при добавлении и удалении элементов.
	Vector(const Vector& a);
	~Vector();
	int len();
	const Vector& operator=(const Vector& a);
	int operator[] (int i);
	Vector operator+(int n);
	Vector operator-(int n);
	friend ostream& operator<<(ostream& out, Vector& a);
	friend istream& operator>>(istream& in, Vector& a);
};