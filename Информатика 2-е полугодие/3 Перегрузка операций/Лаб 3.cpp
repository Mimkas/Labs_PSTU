#include <iostream>
#include "time.h"
using namespace std;
int main()
{
    time a;
    time b;
    time c;
    cin >> a;
    cin >> b;
    if (a != b)
    {
        cout << "\nchisla ne ravni\n";
    }
    else
    {
        cout << "\nchisla ravni\n";
    }
    cout << "\n" << a - b << "\n";
    cout << "a= " << a << "\n";
    cout << "b= " << b << "\n";
    cout << "c= " << c << "\n";
}