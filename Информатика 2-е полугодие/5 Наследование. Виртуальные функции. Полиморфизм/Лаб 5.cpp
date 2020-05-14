#include <iostream>
#include "Pair.h"
#include "Rectangle.h"
#include "Pup.h"
using namespace std;
class vector
{
public:
    vector(void)
    {
        beg = 0;
        size = 0;
        cur = 0;
    }
    vector(int n)
    {
        beg = new Pup * [n];
        cur = 0;
        size = n;
    }
    ~vector(void)
    {
        if (beg != 0) delete[] beg;
        beg = 0;
    }
    void Add(Pup* p)
    {
        if (cur < size)
        {
            beg[cur] = p;
            cur++;
        }
    }
    friend ostream& operator<<(ostream& out, const vector& v)
    {
        if (v.size == 0) out << "Empty\n";
        Pup **p = v.beg;
        for (int i = 0; i < v.cur;i++)
        {
            (*p)->Show();
            p++;
        }
        return out;
    }
    void Perimetr(Pup* pup)
    {
        pup->Perimetr();
    }
    void Area(Pup* pup)
    {
        pup->Area();
    }
private:
    Pup** beg;
    int size;
    int cur;
};

int main()
{
    Rectangle a(8, 12);
    Rectangle b(4,6);
    vector c;
    Pair d(8, 12);
    c.Perimetr(&a);
    c.Area(&b);
    cout << "\na+b is\n" << a + b;
    cout << "\na-b is\n" << a - b;
    cout << "\na*b is\n" << a * b;
    cout << "\na/b is\n" << a / b;
    a.Perimetr();
    b.Perimetr();
    a.Area();
    b.Area();
    c.Perimetr(&d);
    c.Area(&b);
    cout << "\n\n";
    vector e(5);
    Pair f;
    cin >> f;
    Rectangle g;
    cin >> g;
    Pup* p = &f;
    e.Add(p);
    p = &g;
    e.Add(p);
    cout << e;
}