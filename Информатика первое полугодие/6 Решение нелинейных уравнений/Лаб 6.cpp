#include <iostream>
#include <stdlib.h>
#include <cmath>
#include <ctime>
using namespace std;
double Iter(double x, double eps)
{
	double rez; int iter = 0;
	cout << "x0= " << x << "\n";
	do {
		rez = x;
		x = sqrt(2);
		iter++;
	} while (fabs(rez - x) > eps && iter < 20000);
	return x;
}
double Nyut(double x, double eps)
{
	double f, df; int iter = 0;
	cout << "x0= " << x << "\n";
	do {
		f = x * x - 2;
		df = 2 * x;
		x = x - f / df;
		iter++;
	} while (fabs(f) > eps && iter < 20000);
	return x;
}
double Div(double left, double right, double eps)
{
	double x, fl, fr, f;
	int iter = 0;
	cout << "начало = " << left << " конец = " << right << "\n";
	do {
		x = (left + right) / 2;
		f = x * x - 2;
		if (f > 0) right = x;
		else left = x;
		iter++;
	} while (fabs(f) > eps && iter < 20000);
	return x;
}
void main()
{
	setlocale(LC_ALL, "Rus");
	double left, right, eps, r;
	cout << "Начало диапозона: ";
	cin >> left;
	cout << "Конец диапозона: ";
	cin >> right;
	cout << "Точность: ";
	cin >> eps;

	srand(time(0));
	r = rand() % 10;

	cout << "Результат методом итерации: " << Iter(r, eps) << "\n";
	cout << "Результат методом ньютона: " << Nyut(r, eps) << "\n";
	cout << "Результат методом деления: " << Div(left, right, eps) << "\n";
}