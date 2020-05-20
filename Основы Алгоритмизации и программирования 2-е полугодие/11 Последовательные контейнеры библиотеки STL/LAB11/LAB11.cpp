#include <iostream>
#include <list>
using namespace std;
typedef list<float>List;
List MakeListFloat()
{
    List l;
    int n;
    cout << "N?\t";
    cin >> n;
        for (int i = 0;i < n;i++)
        {
            float a = rand()*0.01;
            l.push_back(a);
        }
    return l;
}
void PrintList(List l)
{
    for (auto i = l.begin(); i != l.cend(); ++i)
    {
        cout << *i << "\n";
    }   
}
float MinElemList(List l)
{
    float a = 10000;
    for (auto i = l.begin(); i != l.cend(); ++i)
    {
        if (a > *i)
        {
            a = *i;
        }
    }
    return a;
}
float MaxElemList(List l)
{
    float a = 0;
    for (auto i = l.begin(); i != l.cend(); ++i)
    {
        if (a < *i)
        {
            a = *i;
        }
    }
    return a;
}
List DeleteElem(List l)
{
    float a;
    cout << "Key?\t";
    cin >> a;
    int c = 0;
    for (auto i = l.begin();i != l.cend();++i)
    {
        c++;
    }
    int d = 0;
    for (auto i = l.begin();d<c;d++)
    {
        if (*i!=a)
        {
            l.push_back(*i);
        }
        i++;
        l.pop_front();
    }
    return l;
}
List AddSumMinMaxElem(List l)
{
    float a = MinElemList(l) + MaxElemList(l);
    for (auto i = l.begin();i != l.cend();++i)
    {
        *i = *i + a;
    }
    return l;
}
void main()
{
    try
    {
        list <float> l;
        l = MakeListFloat();
        PrintList(l);
        cout << "\n\n\n";
        float a = MinElemList(l);
        l.push_back(a);
        PrintList(l);
        cout << "\n\n\n";
        l = DeleteElem(l);
        PrintList(l);
        cout << "\n\n\n";
        l = AddSumMinMaxElem(l);
        PrintList(l);
    }
    catch (int)
    {
        cout << "error!";
    }
}
