#include <iostream>
#include <vector>
#include "time.h"
#include <list>
#include <algorithm>
using namespace std;
int Key;
time summinmax;
typedef vector<time> tvector;
typedef list<time> tlist;
tlist MakeList(int n)
{
	time t;
	tlist l;
	for (int i = 0; i < n;i++)
	{
		l.push_back(t.Randtime());
	}
	return l;
}
/*tvector CopyListToVector(tlist l)
{
	tvector v;
	for (auto i = l.begin(); i != l.end(); i++) v.push_back(*i);
	v.pop_back();
	return v;
}
tlist CopyVectorToList(tvector v)
{
	tlist l;
	for (int i = 0; i < v.size(); i++) l.push_back(v[i]);
	return l;
}*/
void PrintList(tlist l)
{
	for (auto i = l.begin(); i != l.end(); i++) cout << *i << "\n";
}
int ConvertTimeToInt(time t)
{
	int temp = t.Getmin() * 60 + t.Getsec();
	return temp;
}
void PrintKey(tlist l)
{
	for (auto i = l.begin(); i != l.end(); i++) cout << ConvertTimeToInt(*i) << "\n";
}
struct key
{
	bool operator() (time t)
	{
		if (Key == ConvertTimeToInt(t)) return true;
		else return false;
	}
};
struct Minsort
{
	bool operator() (time t, time other)
	{
		return t > other;
	}
};
void AddMinMax (time &t)
{
	t=t+summinmax;
}
void main()
{
	tlist::iterator it;
	tlist l = MakeList(10);
	PrintList(l);
	it = min_element(l.begin(), l.end());
	cout << *(it) << "\n\n";
	replace(l.begin(), l.end(), l.back(), *(it));
	cout << "replacement\n";
	PrintList(l);
	cout << "\n\n";
	PrintKey(l);
	cout << "key?";
	cin >> Key;
	it = remove_if(l.begin(), l.end(), key());
	l.erase(it, l.end());
	PrintList(l);
	cout << "\n\n";
	l.sort(Minsort());
	/*tvector v = CopyListToVector(l);
	sort(v.begin(), v.end());
	l = CopyVectorToList(v);
	PrintList(l);
	cout << "\n\n";
	sort(v.begin(), v.end(), Minsort());
	l = CopyVectorToList(v);*/
	PrintList(l);
	cout << "\n\n";
	l.sort();
	PrintList(l);
	cout << "\n\n";
	cout << "\n\n";
	cout << "time?\n";
	time t;
	cin >> t;
	it = find(l.begin(), l.end(), t);
	if (it != l.end()) cout << "Item found: " << *it << "\n\n";
	else cout << "Item not found!\n\n";
	it = min_element(l.begin(), l.end());
	summinmax = *(it);
	it = max_element(l.begin(), l.end());
	summinmax = summinmax + *(it);
	for_each(l.begin(), l.end(), AddMinMax);
	cout << "\n\n";
	PrintList(l);
}