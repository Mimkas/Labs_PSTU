#pragma once
#include <iostream>
#include <fstream>
using namespace std;
struct groop
{
    int AddGroop(const char* FileName)
    {
        fstream stream("Groop", ios::out | ios::app);
        if (!stream) return -1;
        stream << FileName << "\n";
        stream.close();
        return 0;
    }
    int PrintGroop()
    {
        fstream stream("Groop", ios::in);
        if (!stream) return -1;
        char FileName[30];
        while (stream >> FileName) cout << FileName << "\n";
        stream.close();
        return 0;
    }
    int DeleteGroop(const char* FileName)
    {
        fstream stream("Groop", ios::in);
        if (!stream) return -1;
        char Name[30];
        fstream temp("temp", ios::out);
        while (stream >> Name)
        {
            if (Name != FileName)temp << Name << "\n";
        }
        stream.close();
        temp.close();
        remove("Groop");
        rename("temp", "Groop");
        return 0;
    }
};