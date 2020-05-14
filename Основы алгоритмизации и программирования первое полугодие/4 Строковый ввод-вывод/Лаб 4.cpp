#include <Iostream>
#include <fstream>
#include <windows.h>
using namespace std;
void main()
{
	setlocale(LC_ALL, "Russian");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	ofstream fout;
	ifstream fin;
	fout.open("infile.txt");
	char instring[100];
	int sym = 0;
	for (int numberstring = 10; numberstring > 0; numberstring--)
	{
		cout << "введите предложение, осталось: " << numberstring << "\n";
		gets_s(instring);
		strcat_s(instring, "\n");
		fout << instring;
	}
	fout.close();
	fin.open("infile.txt");
	fout.open("outfile.txt");
	while (!fin.eof())
	{
		fin >> instring;
		strcat_s(instring, " ");
		if (instring[0] == 'a')
		{
			sym++;
			fout << instring;
		}
		else if (instring[0] == 'а')
		{
			sym++;
			fout << instring;
		}
		else if (instring[0] == 'A')
		{
			sym++;
			fout << instring;
		}
		else if (instring[0] == 'А')
		{
			sym++;
			fout << instring;
		}
	}
	cout << "\nВ изложенном тексте " << sym << " слов начинаются с буквы А.\n";
}