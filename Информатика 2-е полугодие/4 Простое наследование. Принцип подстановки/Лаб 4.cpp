#include <iostream>
#include "Pair.h"
using namespace std;
class Rectangle
{
private:
    Pair parties;
public:
    Rectangle() { parties; }
    Rectangle(int f, int s) 
    { 
        parties.Setfirst(f);
        parties.Setsecond(s);

    }
    friend istream& operator >> (istream& in, Rectangle& r)
    {
        cout << "\nparties?\n"; in >> r.parties;
        return in;
    }
    friend ostream& operator<<(ostream& out, const Rectangle& r)
    {
        return (out << "\nparties:\n" << r.parties);
    }
    Rectangle& operator=(const Rectangle& other)
    {
        if (&other == this) return *this;
        parties = other.parties;
        return *this;
    }
    void Perimetr(Rectangle other)
    {
        cout << "\nPerimetr is:\n" << other.parties.Getfirst() + other.parties.Getfirst() + other.parties.Getsecond() + other.parties.Getsecond();
    }
    void Area(Rectangle other)
    {
        cout << "\nArea is:\n" << other.parties.Getfirst() * other.parties.Getsecond();
    }
};
int main()
{
    Rectangle a (3,6);
    Pair b(9,8);
    Pair c;
    cin >> c;
    cin >> a;
    cout << c;
    cout << a << "\n";
    a.Perimetr(a);
    a.Area(a);
    cout << "\n\n" << b+c;
    cout << "\n" << b * c;
    cout << "\n" << b - c;
    cout << "\n" << b/c;
    return 0;
}