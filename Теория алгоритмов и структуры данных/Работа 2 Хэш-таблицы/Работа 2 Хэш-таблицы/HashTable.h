#pragma once
#include <iostream>
#include <ctime>
#include <string>
#include <vector>
using namespace std;
int collision = 0;
struct HashTableCell
{
	string Key;
	string nsp;
	int Summ;

	HashTableCell(string Key, string nsp, int Summ) 
	{
		this->Key = Key;
		this->nsp = nsp;
		this->Summ = Summ;
	}
};

class HashTable
{
	HashTableCell** c;
public:
	const int Tablelength = 400;
	double A = 0.35;
	int HashFunc(string Key)
	{
		int g = 0;
		for (int i = 0, s = 1; i < Key.size(); i++,s++)
		{
			g+=s*Key[i];
		}
		int bal = A * g;
		double kAmod1 = (A * g) - bal; //дробные числа с остатком не делятся.
		return Tablelength*kAmod1;
	}
	HashTable()
	{
		c = new HashTableCell * [Tablelength];
		for (int i = 0; i < Tablelength; i++)
		{
			c[i] = NULL;
		}
	}
	void AddTable(string Key, string nsp, int Summ)
	{
		int i = HashFunc(Key);
		while (c[i] != NULL && c[i]->Key != Key)
		{
			i++;
			collision++;
		}
		if (c[i] != NULL) delete c[i];
		c[i] = new HashTableCell(Key, nsp, Summ);
	}
	void MakeTable(int size)
	{
		if (size < 0)
		{
			cout << "size < 0";
			return;
		}
		else if (size > Tablelength)
		{
			cout << "size > table lenght";
		}
		vector <string> name =
		{
			"Sergey", "Alexander", "Ivan", "Oleg", "Roman", "Dmitriy", "Andrey", "Leonid", "Vadim"
		};
		vector <string> surname =
		{
			"Petrov", "Ivanov", "Pupkin", "Smirnov" , "Popov", "Fedotov", "Pastukhov", "Fedoseev","Romanov"
		};
		vector <string> patronymic
		{
			"Sergeevich", "Alexandrovich", "ivanovich", "Olegovich", "Romanovich", "Dmitrievich", "Andreevich", "Leonidovich", "Vadimovich"
		};
		srand(time(NULL));
		for (int i = 0; i < size; i++)
		{
			string Key = to_string(rand() % 9 + 1) + to_string(rand() % 10) + to_string(rand() % 10) + to_string(rand() % 10) + "." + to_string(rand() % 10) + to_string(rand() % 10) + to_string(rand() % 10) + to_string(rand() % 10) + "." + to_string(rand() % 10) + to_string(rand() % 10) + to_string(rand() % 10) + to_string(rand() % 10) + "." + to_string(rand() % 10) + to_string(rand() % 10) + to_string(rand() % 10) + to_string(rand() % 10);
			string nsp = surname[rand() % 9] + " " + name[rand() % 9] + " " + patronymic[rand() % 9];
			int summ = rand() % 25001;
			cout << Key << "\n";
			AddTable(Key, nsp, summ);
		}
	}
	void KeySearch(string Key) 
	{
		int i = HashFunc(Key);
		while (c[i] != NULL && c[i]->Key != Key)
		{
			i++;
		}
		if (c[i] != NULL)
		{
			cout << "NSP " << c[i]->nsp;
			cout << "\nAccount number " << c[i]->Key;
			cout << "\nSumm " << c[i]->Summ << "\n";
		}
		else 
		{
			cout << "Key not found!\n";
		}
	}
	void TableCollision()
	{
		cout << "\nnumber of collisions in the table " << collision << "\n";
	}
};