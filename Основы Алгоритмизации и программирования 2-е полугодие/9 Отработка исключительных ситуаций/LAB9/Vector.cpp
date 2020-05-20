#include <iostream>
#include "Vector.h"
using namespace std;
Vector::Vector(int s)
{
	if (s > MAX_SIZE) throw error("Vector length more than MAXSIZE\n");
	size = s;
	data = new int[s];
	for (int i = 0;i < size;i++)
	{
		data[i] = 0;
	}
}
Vector::Vector(const Vector& a)
{
	size = a.size;
	data = new int[size];
	for (int i = 0;i < size;i++)
	{
		data[i] = a.data[i];
	}
}
Vector::~Vector()
{
	if (data!=0) delete[] data;
}
Vector::Vector(int s, int* mas)
{
	if (s > MAX_SIZE) throw error("Vector length more than MAXSIZE\n");
	size = s;
	data = new int[size];
	for (int i = 0; i < size; i++)
	data[i] = mas[i];
}
const Vector& Vector::operator=(const Vector& a)
{
	if (this == &a) return *this;
	if (data != 0) delete []data;
	size = a.size;
	data = new int[size];
	for (int i = 0;i < size;i++)
	{
		data[i] = a.data[i];
	}
	return *this;
}
int Vector::operator[](int index)
{
	if (index < 0) throw error("index<0");
	if (index >= size) throw error("index>size");
	return data[index];
}
Vector Vector ::operator+(int n)
{
	if (size + n >= MAX_SIZE) throw error("Sum>Max size");
	if (size + n < size) throw error("Sum<size");
	else 
	{
		int c = size;
		int *b;
		b = new int[size];
		for (int i=0; i<size; i++)
		{
			b[i] = data[i];
		}
		data = new int[size + n];
		for (int i = 0; i < size; i++)
		{
			data[i] = b[i];
		}
		size += n;
		for (;c < size;c++)
		{
			int d;
			cout << "\nData " << c << "?\n";
			cin >> d;
			data[c] = d;
		}
		return *this;
	}
}
Vector Vector ::operator-(int n)
{
	if (size - n < 0) throw error("size < 0");
	if (size - n > size) throw error("size-n>size");
	else
	{
		int* b;
		b = new int[size];
		for (int i = 0; i < size; i++)
		{
			b[i] = data[i];
		}
		size -= n;
		data = new int[size];
		for (int i = 0; i < size; i++)
		{
			data[i] = b[i];
		}
		return *this;
	}
}
int Vector::len() {
	return size;
}
ostream& operator<<(ostream& out, Vector& a)
{
	if (a.size == 0) out << "Empty\n";
	for (int i = 0; i < a.size; i++)
		out << a.data[i] << " ";
	return out;
}
istream& operator>>(istream& in, Vector& a)
{
	for (int i = 0; i < a.size; i++)
		in >> a.data[i];
	return in;
}