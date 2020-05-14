#pragma once
#include <iostream>
#include "Pair.h"
using namespace std;
class Rectangle : public Pair
{
public:
    Rectangle() { first = 0; second = 0; };
    Rectangle(int f, int s) { first = f; second = s; }
    Rectangle(const Rectangle& r) { first = r.first; second = r.second; }
    ~Rectangle() {};
    void Perimetr() override
    {
        cout << "\nPerimetr is\n" << first+first+second+second;
    }
    void Area() override
    {
        cout << "\nArea is\n" << first * second;
    }
    void Show() override
    {
        cout << "\nPair:\nfirst\n" << first << "\nsecond\n" << second;
        Perimetr();
        Area();
    }
};