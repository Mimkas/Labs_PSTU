#include <iostream>
using namespace std;
int main() {
	setlocale(LC_ALL, "Russian");
	int b = 0, a = 0, c;
	while (a < 100) {
		a++;
		c = a;
		if ((c % 2) == 0) {
			b = b + a;
		}
	}
	cout << "Сумма всех чётных чисел до 100 равна: " << b;
	return 0;
}