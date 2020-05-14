#include "money.h"
#include <iostream>
using namespace std;

int main()
{
    setlocale(LC_ALL, "Russian");
    bool confirm = true;
    while (confirm == true)
    {
        cout << "Введите номинал денежной единицы:\n";
        int n;
        cin >> n;
        int m;
        cout << "\nВведите колличество денежных единиц\n";
        cin >> m;
        money mon (n, m);
        mon.print();
        cout << "\nИзменить денежные единицы? (y/n):\n";
        char h;
        cin >> h;
        cout << "\n";
        while (h!= 'y' && h !='n') 
        {
            cout << "Ответ не распознан\n";
            cout << "Добавить денежные единицы? Введите y (да) или n (нет):\n";
            cin >> h;
        }
        if (h == 'y') confirm = true;
        else if (h == 'n') confirm = false;
    } 
    return 0;
}