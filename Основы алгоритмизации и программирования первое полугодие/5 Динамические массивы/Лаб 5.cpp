#include <iostream>
using namespace std;
void main()
{
	setlocale(LC_ALL, "Russian");
	int size;
	cout << "Введите размеры массивов:\n";
	cin >> size;
	int* mas = new int[size];
	int i, c, b;
	for (i = 0; i < size; i++)
	{
		mas[i] = rand() % 10 + 1;
	}
	int* arr = new int[size];
	for (i = 0; i < size; i++)
	{
		arr[i] = rand() % 100 + 1;
		cout << arr[i] << "\n";
	}
	cout << "введите ключ для удаления: ";
	int key;
	cin >> key;
	for (i = 0; i < size - 1; i++)
	{
		if (i >= key)
		{
			arr[i] = arr[i + 1];
		}
		cout << arr[i] << "\n";
	}
	arr[size] = 0;
	cout << "введите ключ для добавления: ";
	cin >> key;
	for (i = 0; i < size; i++)
	{
		b = arr[i];
		if (i > key)
		{
			arr[i] = c;
		}
		else if (i == key)
		{
			arr[i] = mas[i];
		}
		c = b;
		cout << arr[i] << "\n";
	}
	delete[]mas;
}