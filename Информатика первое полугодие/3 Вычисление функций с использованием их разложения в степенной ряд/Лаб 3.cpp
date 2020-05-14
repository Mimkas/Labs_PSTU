#include <iostream>
#include <cmath>
#define N 40
#define EPS 0.0001
#define PI 3.1415926535897932384626433832795
#define a PI/5.
#define b PI*9/5.
using namespace std;
int main()
{
	double x, dx, d = 1, y = 0;
	dx = (b - a) / 10;
	cout << "\tX\t\t\tSN\t\t\tSE\t\t\tY\t" << endl;
	for (x = a; x < b; x += dx)
	{
		double SN = 0, SE = 0;
		y = -log(fabs(2 * sin(x / 2)));
		for (int i = 1; i <= N; i++)
		{
			SN += cos(i * x) / i;
		}
		int i = 0;
		do {
			++i;
			d = cos(i * x) / i;
			SE += d;
		} while (fabs(d) > EPS);
		cout << "\t" << x << "\t\t\t" << SN << "\t\t" << SE << "\t\t" << y << "\n";
	}
	return 0;
}