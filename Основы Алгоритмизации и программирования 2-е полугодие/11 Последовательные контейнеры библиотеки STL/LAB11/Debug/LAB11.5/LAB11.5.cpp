#include <iostream>
#include "Time.h"
#include "Vector.h"
#include <queue>
using namespace std;
/*qu MakeQueue()
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
}*/
int main()
{
    Vector<time>v(6);
    v.CopyVectorToQueue();
    v.CopyQueueToVector();
    v.Print();
    cout << "\n\n\n";
    time t = v.MinSize();
    v.Add(t);
    v.Print();
    cout << "\n\n\n";
    v.DeleteElem();
    v.Print();
    cout << "\n\n\n";
    v.AddMinMaxElem();
    v.Print();
}