#include <iostream>
#include "Time.h"
#include <list>
using namespace std;
typedef list<time>TimeList;
TimeList MakeListTime()
{
    TimeList tl;
    int n;
    cout << "N?\t";
    cin >> n;
    for (int i = 0;i < n;i++)
    {
        time t;
        t.Randtime();
        tl.push_back(t);
    }
    return tl;
}
void PrintList(TimeList tl)
{
    for (auto i = tl.begin(); i != tl.cend(); ++i)
    {
        cout << *i << "\n";
    }
}
time MinElemList(TimeList tl)
{
    time a(10000,10000);
    for (auto i = tl.begin(); i != tl.cend(); ++i)
    {
        if (a > * i)
        {
            a = *i;
        }
    }
    return a;
}
time MaxElemList(TimeList tl)
{
    time a(0, 0);
    for (auto i = tl.begin(); i != tl.cend(); ++i)
    {
        if (a < * i)
        {
            a = *i;
        }
    }
    return a;
}
TimeList DeleteElem(TimeList tl)
{
    time a;
    cout << "Key?\n";
    cin >> a;
    int c = 0;
    for (auto i = tl.begin();i != tl.cend();++i)
    {
        c++;
    }
    int d = 0;
    for (auto i = tl.begin();d < c;d++)
    {
        if (*i != a)
        {
            tl.push_back(*i);
        }
        i++;
        tl.pop_front();
    }
    return tl;
}
TimeList AddSumMinMaxElem(TimeList tl)
{
    time t = MinElemList(tl) + MaxElemList(tl);
    for (auto i = tl.begin();i != tl.cend();++i)
    {
        *i = *i + t;
    }
    return tl;
}
void main()
{
    try
    {
        list <time> tl;
        tl = MakeListTime();
        PrintList(tl);
        cout << "\n\n\n";
        time t = MinElemList(tl);
        tl.push_back(t);
        PrintList(tl);
        cout << "\n\n\n";
        tl = DeleteElem(tl);
        PrintList(tl);
        cout << "\n\n\n";
        tl = AddSumMinMaxElem(tl);
        PrintList(tl);
    }
    catch (int)
    {
        cout << "error!";
    }
}