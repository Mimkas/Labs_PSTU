#include <iostream>
#include <math.h>
using namespace std;
int main() {
	int i = 1;
	double b = 0, a = 0, c = 0;
	while (i <= 13) {
		a = a + log(i);
		b = b + i * 2 - 1;
		c = c + a / b;
		i++;
	}
	cout << "summ = " << c;
	return 0;
}