#pragma once
#include <iostream>
#include <string>
using namespace std;
class book
{
private:
    string title;
    string author;
    int year;
public:
    book();
    book(string, string, int);
    book(const book&);
    ~book();
    string Gettitle();
    void Settitle(string);
    string Getauthor();
    void Setauthor(string);
    int Getyear();
    void Setyear(int);
    void show();
};