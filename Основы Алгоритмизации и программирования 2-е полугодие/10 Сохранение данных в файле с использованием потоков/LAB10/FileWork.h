#pragma once
#include <iostream>
#include <fstream>
#include "time.h"
using namespace std;
int MakeFile(const char* FileName)
{
	fstream stream(FileName, ios::out | ios::trunc);
	if (!stream) return -1;
	int c;
	time t;
	cout << "How much data to enter?"; cin >> c;
	for (int i = 0;i < c;i++)
	{
		cin >> t;
		stream << t << "\n";
	}
	stream.close();
	return c;
}
int PrintFile(const char* FileName)
{
	fstream stream(FileName, ios::in);
	if (!stream) return -1;
	time t;
	int i = 0;
	while (stream >> t)
	{
		cout << t << "\n";
		i++;
	}
	stream.close();
	return i;
}
int DelFile(const char* FileName, int l,int r)
{
	if (l < 0 || r < 0 || r < l) return -2;
	fstream temp("temp", ios::out);
	fstream stream(FileName, ios::in);
	if (!stream) return -1;
	int i = 0;
	time t;
	while (stream >> t)
	{
		if (stream.eof()) break;
		i++;
		if (i >= l && i <= r) temp << t;
	}
	stream.close();
	temp.close();
	remove(FileName);
	rename("temp", FileName);
	return i;
}
int SubtractFile(const char* FileName, int l, int r)
{
	if (l < 0 || r < 0 || r < l) return -2;
	fstream temp("temp", ios::out);
	fstream stream(FileName, ios::in);
	if (!stream) return -1;
	int i = 0;
	time t;
	time e(1, 30);
	while (stream >> t)
	{
		if (stream.eof()) break;
		i++;
		if (i >= l && i <= r)
		{
			t = t - e;
			temp << t;
		}
		else temp << t;
	}
	stream.close();
	temp.close();
	remove(FileName);
	rename("temp", FileName);
	return i;
}
int EditFile(const char* FileName)
{
	int i = 0;
	i = MakeFile("temp");
	fstream temp("temp", ios::app);
	fstream stream(FileName, ios::in);
	if (!stream) return -1;
	time t;
	while (stream >> t)
	{
		if (stream.eof()) break;
		i++;
		temp << t;
	}
	stream.close();
	temp.close();
	remove(FileName);
	rename("temp", FileName);
	return i;
}