#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#pragma warning(disable : 4996)
using namespace std;

typedef struct employee
{
	char surname[30];
	char name[30];
	char patronymic[30];
	char position[30];
	char btyear[30];
	int salary;
	int id;
};

employee Add(void) {
	employee w;
	cout << "Фамилия: ";
	cin >> w.surname;
	cout << "Имя: ";
	cin >> w.name;
	cout << "Отчество: ";
	cin >> w.patronymic;
	cout << "Должность: ";
	cin >> w.position;
	cout << "Дата рождения: ";
	cin >> w.btyear;
	cout << "Заработная плата: ";
	cin >> w.salary;
	return w;
}

void Print(employee w)
{
	cout << "\nID: " << w.id;
	cout << "\nФамилия: " << w.surname;
	cout << "\nИмя: " << w.name;
	cout << "\nОтчество: " << w.patronymic;
	cout << "\nДолжность: " << w.position;
	cout << "\nДата рождения: " << w.btyear;
	cout << "\nЗаработная плата: " << w.salary << "\n\n";
}

void fin(void)
{
	FILE* data;
	int num = 0;
	if ((data = fopen("data.txt", "wb")) == NULL) perror("не удается открыть фаил"), exit(110);
	bool cont = true;
	while (cont)
	{
		++num;
		employee w = Add();
		w.id = num;
		fwrite(&w, sizeof(employee), 1, data);
		cout << "Продолжить ввод данных (y/n): ";
		char h;
		cin >> h;
		cout << "\n";
		while (h != 'y' && h != 'n') {
			cout << "Ответ не распознан\n";
			cout << "Продолжить ввод данных, введите y(да) или n(нет):\n";
			cin >> h;
		}
		if (h == 'y') cont = true;
		else if (h == 'n') cont = false;
	}
	fclose(data);
}

int fout(void)
{
	int num = 0;
	FILE* data;
	employee w;
	if ((data = fopen("data.txt", "rt")) == NULL) perror("не удается открыть фаил"), exit(210);
	fread(&w, sizeof(employee), 1, data);
	while (!feof(data))
	{
		Print(w);
		num = w.id;

		fread(&w, sizeof(employee), 1, data);
	}
	fclose(data);
	if (!num) perror("ошибка номерации"), exit(230);
	return num;
}

void del(void)
{
	FILE* data, * bof;
	char serch[30];
	cout << "\nВведите фамилию для поиска и удаления: ";
	cin >> serch;
	if ((data = fopen("data.txt", "rb")) == NULL) perror("не удается открыть фаил"), exit(310);
	employee w;
	bof = fopen("bof.txt", "wb");
	while (fread(&w, sizeof(employee), 1, data) == 1)
	{
		if (strcmp(w.surname, serch) != 0)
		{
			fwrite(&w, sizeof(employee), 1, bof);
		}
		else
			cout << "Сотрудник " << w.surname << " удален\n";
	}
	fclose(data);
	fclose(bof);
	remove("data.txt");
	if (rename("bof.txt", "data.txt") != 0) perror("ошибка переименовывания"), exit(320);
}

void add(int number)
{
	FILE* data, * bof;
	employee w;
	employee bofw;
	int num;
	cout << "\nУкажите номер (ID): ";
	cin >> num;
	++number;
	if ((data = fopen("data.txt", "rb")) == NULL) perror("не удается открыть фаил извлечения"), exit(410);
	if ((bof = fopen("bof.txt", "wb")) == NULL) perror("не удается открыть фаил для записи"), exit(411);
	while (fread(&w, sizeof(employee), 1, data) == 1)
	{

		if (w.id != num) fwrite(&w, sizeof(employee), 1, bof);
		else
		{
			fwrite(&w, sizeof(employee), 1, bof);

			bofw = Add();
			bofw.id = number;

			fwrite(&bofw, sizeof(employee), 1, bof);
		}
	}
	fclose(data);
	fclose(bof);
	remove("data.txt");
	if (rename("bof.txt", "data.txt") != 0) perror("ошибка переименовывания"), exit(420);
	return;
}

void main()
{
	setlocale(LC_ALL, "Russian");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	int number = 0;
	fin();
	number = fout();
	del();
	number = fout();
	add(number);
	number = fout();
}