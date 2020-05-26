#include <iostream>
#include "HashTable.h"

void main()
{
    HashTable i;
    char c = 'y';
    while (c != 'n')
    {
        int s;
        cout << "put table size\n";
        cin >> s;
        i.MakeTable(s);
        i.TableCollision();
        cout << "find item in table\n";
        string item;
        cin >> item;
        i.KeySearch(item);
        cin >> c;
    }
}