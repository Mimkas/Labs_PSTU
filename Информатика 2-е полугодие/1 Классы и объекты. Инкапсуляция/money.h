#pragma once
#include <iostream>
using namespace std;
struct money
{
    int nom, mass;
    void Setnom(int n)
    {
        int val[] = { 1,2,5,10,50,100,500,1000,5000 };
        bool a = false;
        for (int i = 0; i < 9; i++)
        {
            if (val[i] == n)
            {
                nom = val[i];
                a = true;
            }
        }
        if (a == false)
        {
            cout << "Ошибка! Несуществующий номинал.\nВведите номинал заново:\n";
            cin >> nom;
            Setnom(nom);
        }
    }
    int Setmass(int m)
    {
        mass = m;
    }
    money(int n, int m)
    {
        Setnom(n);
        mass = m;
    }
    int moneysumm()
    {
        int summ = nom * mass;
        return summ;
    }
    void print()
    {
        cout << "\nсумма денежных средств составляет:\n" << moneysumm();
    }
};