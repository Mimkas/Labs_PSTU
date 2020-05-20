#include <iostream>
#include "Vector.h"
#include "time.h"
using namespace std;
void main()
{
    Vector<time>vec(5);
    vec.Print();
    cout << "\n\n\n";
    time t = vec.Minsize();
    vec.Add(t);
    vec.Print();
    cout << "\n\n\n";
    vec = vec.Del();
    vec.Print();
    cout << "\n\n\n";
    vec.AddMinMaxSize();
    vec.Print();
}