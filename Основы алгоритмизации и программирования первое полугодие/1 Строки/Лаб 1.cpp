#include <iostream>
#include <string.h>
#include <cstring>
#include <cctype>
#include <windows.h>
using namespace std;
void main()
{
	setlocale(LC_ALL, "Russian");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	cout << "Введите предложение \n";
	char s[255], character;
	gets_s(s);
	strcat_s(s, " ");
	string a, c, min = s, max;
	int num = 0, maxnum = strlen(s), len1, len2;
	while (num <= maxnum)
	{
		character = s[num];
		if (isspace(character))
		{
			len1 = a.size();
			len2 = min.size();
			if (len1 < len2)
			{
				min = a;
			}
			len2 = max.size();
			if (len1 > len2)
			{
				max = a;
			}
			a = c;
		}
		else
		{
			a = a + character;
		}
		num++;
	}
	cout<< "Самое короткое слово в строке: " << min << "\nСамое длинное слово в строке: " << max;
}
