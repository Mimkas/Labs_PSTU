#include <iostream>
#include <list>
#include "time.h"
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;
typedef queue <time> qu;
typedef list <time> ls;
typedef vector <time> tvector;
int Key;
time summinmax;
qu MakeQueue()
{
    cout << "N?\t";
    int n;
    cin >> n;
    qu q;
    for (int i = 0; i < n;i++)
    {
        time t;
        q.push(t.Randtime());
    }
    return q;
}
/*tvector CopyQueueToVector(qu q)
{
    tvector v;
    while (!q.empty())
    {
        v.push_back(q.front());
        q.pop();
    }
    v.pop_back();
    return v;
}
qu CopyVectorToQueue(tvector v)
{
    qu q;
    for (int i = 0; i < v.size(); i++)
    {
        q.push(v[i]);
    }
    return q;
}*/
ls CopyQueueToList(qu q)
{
    ls l;
    while (!q.empty())
    {
        l.push_back(q.front());
        q.pop();
    }
    return l;
}
qu CopyListToQueue(ls l)
{
    qu q;
    for (auto i = l.begin(); i != l.cend(); ++i)
    {
        q.push(*i);
    }
    return q;
}
void PrintQueue(qu q)
{
    while (!q.empty())
    {
        cout << q.front() << "\n";
        q.pop();
    }
    cout << "\n";
}
int ConvertTimeToInt(time t)
{
    int temp = t.Getmin() * 60 + t.Getsec();
    return temp;
}
void PrintKey(ls l)
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
void AddMinMax(time& t)
{
    t = t + summinmax;
}
int main()
{
    ls::iterator it;
    qu q = MakeQueue();
    PrintQueue(q);
    ls l = CopyQueueToList(q);
    it = min_element(l.begin(), l.end());
    cout << *(it) << "\n\n";
    replace(l.begin(), l.end(), l.back(), *(it));
    cout << "replacement\n";
    q = CopyListToQueue(l);
    PrintQueue(q);
    cout << "\n\n";
    PrintKey(l);
    cout << "key?";
    cin >> Key;
    it = remove_if(l.begin(), l.end(), key());
    l.erase(it, l.end());
    q = CopyListToQueue(l);
    PrintQueue(q);
    cout << "\n\n";
    l.sort(Minsort());
    q = CopyListToQueue(l);
    PrintQueue(q);
    l.sort();
    q = CopyListToQueue(l);
    PrintQueue(q);
    /*tvector v = CopyQueueToVector(q);
    sort(v.begin(), v.end());
    q = CopyVectorToQueue(v);
    PrintQueue(q);
    cout << "\n\n";
    sort(v.begin(), v.end(), Minsort());
    q = CopyVectorToQueue(v);
    PrintQueue(q);
    l = CopyQueueToList(q);*/
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
    q = CopyListToQueue(l);
    PrintQueue(q);
}
