#include <iostream>
#include "time.h"
#include "Vector.h"
using namespace std;

void main()
{
    cout << "Programm working" << "\n";
    Vector <int> A(5, 0);
    cin >> A;
    cout << A << "\n";
    Vector <int> B(10,1);
    cout << B << "\n";
    B = A;
    cout << A + B << "\n\n";
    cout << A[3] << "\n";
    cout << "size= " << A() << "\n";
    time t;
    cin >> t;
    cout << t << "\n";
    time k;
    cout << "k?\n";
    cin >> k;
    time p;
    p = t + k;
    cout << "\np=" << p << "\n";
    Vector<time>Y(5, t);
    cin >> Y;
    cout << Y << "\n";
    Vector<time>K(10, k);
    K=Y;
    cout << "Summ Y & K = "<< Y + K << "\n";
    cout << Y[2] << "\n";
    cout << "size= " << Y() << "\n";
}
