#include "period.h"
#include <iostream>
#include <fstream>
#include "database.h"
#include "Groop.h"
using namespace std;
groop Phoenix;
void main()
{
    period t;
    int k, c;
    char FileName[30];
    do
    {
        cout << "\n0. Exit";
        cout << "\n1. Make File";
        cout << "\n2. Print file";
        cout << "\n3. Sort data on period";
        cout << "\n4. Delite data on file";
        cout << "\n5. EditFile";
        cout << "\n6. MaxProfit on year";
        cout << "\n7. Add file to groop";
        cout << "\n8. Print groop";
        cout << "\n9. Delete file on groop";
        cout << "\n10. The most continuous decline in profit for the unit\n";
        cout << ">";
        cin >> c;
        switch (c)
        {
        case 1: cout << "file name? ";
            cin >> FileName;
            k = CreateOrOpenDataFile(FileName);
            if (k < 0) cout << "Can`t make file";
            break;
        case 2: cout << "file name? ";
            cin >> FileName;
            k = PrintDataFile(FileName);
            if (k == 0) cout << "Empty file\n";
            if (k < 0) cout << "Can`t read file\n";
            break;
        case 3: cout << "file name? ";
            cin >> FileName;
            k = SortData(FileName);
            if (k == -1) cout << "Can`t read file";
            break;
        case 4: cout << "file name? ";
            cin >> FileName;
            k = DeliteData(FileName);
            if (k == -1) cout << "Can`t read file";
            break;
        case 5: cout << "file name? ";
            cin >> FileName;
            k = CorrectData(FileName);
            if (k == -1) cout << "Can`t read file";
            break;
        case 6: cout << "file name? ";
            cin >> FileName;
            k = MaxProfit(FileName);
            if (k == -1) cout << "Can`t read file";
            break;
        case 7: cout << "file name? ";
            cin >> FileName;
            k = Phoenix.AddGroop(FileName);
            if (k == -1) cout << "Can`t read file";
            break;
        case 8: k = Phoenix.PrintGroop();
            if (k == -1) cout << "Can`t read file";
            break;
        case 9: cout << "file name? ";
            cin >> FileName;
            k = Phoenix.DeleteGroop(FileName);
            if (k == -1) cout << "Can`t read file";
            break;
        case 10: cout << "file name? ";
            cin >> FileName;
            k = DayPeriodLowMediumGroopProfit(FileName);
            if (k == -1) cout << "Can`t read file";
            break;
        }
    } while (c != 0);
}