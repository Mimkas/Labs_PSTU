#include <iostream>
#include <stdlib.h>
using namespace std;
void main() 
{
	int m[9], g[100];
	for (int i = 0; i < 9; i++)
	{
		m[i] = rand() % 50;
		cout << m[i] << "\t";
	}
	cout << "\n";
	int d = 0;
	for (int c = 0;c < 9;c++)
	{
		if (m[c] != 0)
		{
			g[d] = m[c];
			int k = (g[d] % 2);
			if (k == 0)
			{
				g[d+1] = g[d -1]+2;
				d++;
			}
			d++;
		}
	}
	cout << "obnovleniy massiv \n";
	for (int i = 0; i < d; i++)
	{
		cout << g[i] << "\t";
	}
	cout << "\n";
}
