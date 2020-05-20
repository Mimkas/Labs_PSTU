#include <iostream>
#include "Time.h"
#include <set>
using namespace std;
typedef set <pair<int, time>> tset;
tset::iterator it;
tset MakeSet()
{
    cout << "N? ";
    int n;
    cin >> n;
    tset f;
    for (int i = 0; i < n;i++)
    {
        time a;
        a.Randtime();
        f.insert(make_pair(i, a));
    }
    return f;
}
void PrintSet(tset f)
{
    for (auto& item : f)
    {
        cout << item.first << " " << item.second << "\n";
    }
}
time MinSize(tset f)
{
    time t (1000,1000);
    for (auto& item : f)
    {
        if (t > item.second) t = item.second;
    }
    return t;
}
time MaxSize(tset f)
{
    time t (0,0);
    for (auto& item : f)
    {
        if (t < item.second) t = item.second;
    }
    return t;
}
tset AddElem(tset f, time t)
{
    int i = 0;
    for (auto& item : f) if (i < item.first)i = item.first;
    i++;
    f.insert(make_pair(i, t));
    return f;
}
tset DeleteElem(tset f)
{
    cout << "put num elem, for search key\t";
    int key;
    cin >> key;
    time t;
    for (auto& item : f)
    {
        if (item.first == key) t = item.second;
    }
    it = f.find(make_pair(key, t));
    if (it != f.end())
    {
        f.erase(it);
    }
    else cout << "key not found.\n";
    return f;
}
tset AddMinMaxElem(tset f)
{
    time t = MinSize(f) + MaxSize(f);
    tset bof;
    for (auto& item : f)
    {
        time ft = item.second;
        bof.insert(make_pair(item.first, ft+ t));
    }
    return bof;
}
void main()
{
    tset f;
    f = MakeSet();
    PrintSet(f);
    cout << "\n\n\n";
    time t = MinSize(f);
    f = AddElem(f,t);
    PrintSet(f);
    cout << "\n\n\n";
    f = DeleteElem(f);
    PrintSet(f);
    cout << "\n\n\n";
    f = AddMinMaxElem(f);
    PrintSet(f);
}