#include <iostream>
#include "Vector.h"
#include <set>
#include "Time.h"
using namespace std;
/*int ConvertTimeToInt(time t)
{
    int temp = t.Getmin() * 60 + t.Getsec();
    return temp;
}
time ConvertIntToTime(int i)
{
    time t;
    t.Setmin(i / 60);
    t.Setsec(i % 60);
    return t;
} какое-то время без этого не работало, пока не разобрался, что нужна константа в сравнении:*/
Vector <time> MakeVector(Vector <time> v)
{
    cout << "N?\t";
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        time t;
        t.Randtime();
        v.Add(t);
    }
    return v;
}

void main()
{
    Vector <time> v;
    v = MakeVector(v);
    v.PrintVector();
    cout << "\n\n\n";
    time t = v.MinSizeElement();
    v.Add(t);
    v.PrintVector();
    cout << "\n\n\n";
    v.DelElem();
    v.PrintVector();
    cout << "\n\n\n";
    v.AddMinMaxSize();
    v.PrintVector();
}
