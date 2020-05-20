#include <iostream>
#include "Time.h"
#include <list>
#include <queue>
using namespace std;
typedef queue <time> qu;
typedef list <time> ls;
qu MakeQueue()
{
    cout << "N?\t";
    int n;
    cin >> n;
    qu q;
    for (int i=0; i < n;i++)
    {
        time t;
        q.push(t.Randtime());
    }
    return q;
}
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
       cout << q.front() << "\t";
       q.pop();
    }
    cout << "\n";
}
time MinElemQueue(qu q)
{
    time t=q.front();
    while (!q.empty())
    {
        if (t > q.front()) t = q.front();
        q.pop();
    }
    return t;
}
time MaxElemQueue(qu q)
{
    time t = q.front();
    while (!q.empty())
    {
        if (t < q.front()) t = q.front();
        q.pop();
    }
    return t;
}
qu DeleteElem(qu q)
{
    ls l = CopyQueueToList(q);
    time a;
    cout << "Key?\n";
    cin >> a;
    int c = 0;
    for (auto i = l.begin();i != l.cend();++i)
    {
        c++;
    }
    int d = 0;
    for (auto i = l.begin();d < c;d++)
    {
        if (*i != a)
        {
            l.push_back(*i);
        }
        i++;
        l.pop_front();
    }
    q = CopyListToQueue(l);
    return q;
}
qu AddSumMinMaxElem(qu q)
{   
    ls l = CopyQueueToList(q);
    time t = MinElemQueue(q) + MaxElemQueue(q);
    for (auto i = l.begin();i != l.cend();++i)
    {
        *i = *i + t;
    }
    q = CopyListToQueue(l);
    return q;
}
void main()
{
    qu q;
    q = MakeQueue();
    PrintQueue(q);
    cout << "\n\n\n";
    time t = MinElemQueue(q);
    q.push(t);
    PrintQueue(q);
    cout << "\n\n\n";
    q = DeleteElem(q);
    PrintQueue(q);
    cout << "\n\n\n";
    q = AddSumMinMaxElem(q);
    PrintQueue(q);
}
