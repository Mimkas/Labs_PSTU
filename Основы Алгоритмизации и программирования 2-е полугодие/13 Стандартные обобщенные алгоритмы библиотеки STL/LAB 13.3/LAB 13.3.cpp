#include <iostream>
#include <set>
#include "time.h"
#include <algorithm>
using namespace std;
typedef multiset <pair<int,time>> mset;
mset::iterator it;
time summinmax;
int Key;
void MakeSet(mset &mt)
{
    cout << "N? ";
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        time t;
        t.Randtime();
        mt.insert(make_pair(i, t));
    }
}
void PrintMSet(mset mt)
{
    for (auto &i : mt)
    {
        cout << i.first << "\t" << i.second << "\n";
    }
}
int ConvertTimeToInt(time t)
{
    int temp = t.Getmin() * 60 + t.Getsec();
    return temp;
}
struct MinElem
{
    bool operator() (pair<int,time> p, pair<int, time> a)
    {
        if (p.second < a.second) return true;
        else return false;
    }
};
struct MaxElem
{
    bool operator() (pair<int, time> p, pair<int, time> a)
    {
        if (p.second > a.second) return false;
        else return true;
    }
};
void DeleteKey(mset &mt)
{
    time t;
    for (auto& item : mt)
    {
        if (item.first == Key) t = item.second;
    }
    it = mt.find(make_pair(Key, t));
    if (it != mt.end())
    {
        mt.erase(it);
    }
    else cout << "key not found.\n";
}
void UpSort(mset& mt)
{
    multiset <time> m;
    for (auto& i : mt)
    {
        m.insert(i.second);
    }
    mt.clear();
    int a = 0;
    for (auto& i : m)
    {
        if (a == Key) a++;
        mt.insert(make_pair(a,i)), a++;
    }
}
void DownSort(mset& mt)
{
    multiset <time,greater<time>> m;
    for (auto& i : mt)
    {
        m.insert(i.second);
    }
    mt.clear();
    int a = 0;
    for (auto& i : m)
    {
        if (a == Key) a++;
        mt.insert(make_pair(a, i)), a++;
    }
}
mset AddMinMax(mset mt)
{
    mset bof;
    for (auto& i : mt)
    {
        time t = i.second;
        bof.insert(make_pair(i.first, t + summinmax));
    }
    return bof;
}
void main()
{
    mset mt;
    MakeSet(mt);
    PrintMSet(mt);
    it = min_element(mt.begin(), mt.end(), MinElem());
    pair <int, time>  p = *it;
    cout <<"\n" << p.first << "\t" << p.second << "\n\n";
    it = max_element(mt.begin(), mt.end());
    pair <int, time> f = *it;
    p.first = f.first+1;
    mt.insert(p);
    PrintMSet(mt);
    cout << "\nKey? ";
    cin >> Key;
    DeleteKey(mt);
    PrintMSet(mt);
    cout << "\n";
    UpSort(mt);
    PrintMSet(mt);
    cout << "\n";
    DownSort(mt);
    PrintMSet(mt);
    cout << "\nnumber?\n";
    time t;
    int i;
    cin >> i >> t;
    it = mt.find(make_pair(i, t));
    if (it != mt.end()) cout << "Item found\n\n";
    else cout << "Item not found\n\n";
    it = min_element(mt.begin(),mt.end(), MinElem());
    f = *it;
    summinmax = f.second;
    it = max_element(mt.begin(), mt.end(), MaxElem());
    f = *it;
    summinmax = summinmax + f.second;
    mt = AddMinMax(mt);
    PrintMSet(mt);
}
