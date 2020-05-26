#pragma once
#include <iostream>
#include <fstream>
#include "period.h"
#include <set>
int MaxYearProfit(const char* FileName,period oldp, period c)
{
	int i,m=0;
	period p;
	fstream stream(FileName, ios::in);
	while (stream >> p, stream >> i)
	{
		if (p > oldp && p < c) { m = m + i; }
	}
	stream.close();
	return m;
}
void Structperiod(period& p) { int temp = p.Getyear() * 12 + p.Getmonth(); p.Setyear(temp / 12);p.Setmonth(temp % 12); }
int CreateOrOpenDataFile(const char* FileName)
{
	fstream stream(FileName, ios::out | ios::app);
	if (!stream) return -1;
	int n = 0;
	while (n != 1 && n != 2)
	{
		cout << "please select a method of entering information\n1. auto (program testing method add 5 years)\n2. manual method\n";
		cin >> n;
	}
	if (n == 1)
	{
		period c(5, 0);
		for (period p(0, 1);p <= c; p.Setmonth(p.Getmonth() + 1))
		{
			int d = rand() % 10001 + 15000;
			//cout << p << " " << d << "\n";
			Structperiod(p);
			stream << p << " " << d << "\n";
		}
	}
	else if (n == 2)
	{
		int d;
		period p;
		cout << "period?\n";
		cin >> p;
		Structperiod(p);
		cout << "data?\n";
		cin >> d;
		//cout << p << " " << d << "\n";
		stream << p << " " << d << "\n";
	}
	stream.close();
	return 0;
}
int PrintDataFile(const char* FileName)
{
	fstream stream(FileName, ios::in);
	if (!stream) return -1;
	period p;
	int i;
	while (stream >> p, stream >> i)
	{
		cout << p << " " << i << "\n";
	}
	stream.close();
	return i;
}
int SortData(const char* FileName)
{
	fstream stream(FileName, ios::in);
	if (!stream) return -1;
	period p;
	int i;
	set <pair <period, int>> pset;
	while (stream >> p, stream >> i)
	{
		pset.insert(make_pair(p, i));
	}
	stream.close();
	fstream streams(FileName, ios::out | ios::trunc);
	for (auto& item : pset)
	{
		pair <period, int> p = item;
		Structperiod(p.first);
		streams << p.first << " " << p.second << "\n";
	}
	streams.close();
	return i;
}
int DeliteData(const char* FileName)
{
	fstream stream(FileName, ios::in);
	if (!stream) return -1;
	period p,d;
	int i;
	cout << "chose period on delite\n";
	cin >> d;
	fstream temp("temp", ios::out);
	while (stream >> p, stream >> i)
	{
		if(p!=d)temp << p << " " << i << "\n";
	}
	stream.close();
	temp.close();
	remove(FileName);
	rename("temp", FileName);
	return i;
}
int CorrectData(const char* FileName)
{
	fstream stream(FileName, ios::in);
	if (!stream) return -1;
	period p, d, c;
	int i, n;
	cout << "choise period on correct\n";
	cin >> d;
	cout << "put new period and data\n";
	cin >> c >> n;
	fstream temp("temp", ios::out);
	while (stream >> p, stream >> i)
	{
		if (p != d)temp << p << " " << i << "\n";
		else temp << c << n;
	}
	stream.close();
	temp.close();
	remove(FileName);
	rename("temp", FileName);
	return i;
}
int MaxProfit(const char* FileName)
{
	int i, maxprofit = 0;
	period d,oldp (0,0),l;
	fstream stream(FileName, ios::in);
	if (!stream) return -1;
	while (stream >> d >> i);
	stream.close();
	for (period c(1, 0); c < d; c.Setyear(c.Getyear() + 1))
	{
		int m = MaxYearProfit(FileName,oldp,c);
		oldp = c;
		if (maxprofit < m) maxprofit = m, l=c;
	}
	cout << maxprofit << "\t" << l;
	stream.close();
	return 0;
}
int MediumProfit(const char* FileName)
{
	fstream stream(FileName, ios::in);
	if (!stream) return -1;
	period p;
	int i,a=0,t=0;
	while (stream >> p, stream >> i)
	{
		a = a + i;
		t++;
	}
	stream.close();
	return a / t;
}
int MediumGroopProfit()
{
	int a = 0, t = 0;
	char FileName[30];
	fstream stream("Groop", ios::in);
	if (!stream) return -1;
	while (stream >> FileName)
	{
		a = a + MediumProfit(FileName);
		if (MediumProfit(FileName) == -1) return -1;
		t++;
	}
	stream.close();
	return a / t;
}
int DayPeriodLowMediumGroopProfit(const char* FileName)
{
	int m = MediumGroopProfit();
	if (m == -1) return -1;
	int i = 0, l = 0, p;
	period f;
	fstream stream(FileName, ios::in);
	if (!stream) return -1;
	while (stream >> f, stream >> p)
	{
		if (p < m) i++;
		else if (l < i) l = i;
		else i = 0;
	}
	cout << "the most prolonged decline in profits was " << l << " month";
	stream.close();
	return 0;
}