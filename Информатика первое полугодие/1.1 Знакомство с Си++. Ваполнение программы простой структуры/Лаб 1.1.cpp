#include <iostream>
using namespace std;
int main()
{
	double a, b, result;
	float a1, b1, result1;
	//a = 1000;
	//b = 0.0001;
	cout << "ukazhite a \n";
	cin >> a;
	a1 = a;
	cout << "ukazhite b \n";
	cin >> b;
	b1 = b;
	result = ((a * a - 2 * a * b + b * b) - (a * a - 2 * a * b)) / (b * b);
	result1 = ((a1 * a1 - 2 * a1 * b1 + b1 * b1) - (a1 * a1 - 2 * a1 * b1)) / (b1 * b1);
	cout << "result (float): \n" << result1 << "\n" << "result (double): \n" << result << "\n";
	return 0;
}