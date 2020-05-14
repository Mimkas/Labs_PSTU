#include <iostream>
#include <stdlib.h>
using namespace std;
void main (int argc, const char * argv[]){
	cout <<"vvedite kollichestvo chisel v massive \n";
	int z;
	cin >> z;
	int* m = new int[z];
	int c = 0, f, t;
	int b = 0;
	int a = 50;
	float summ=0;
	while (c<z) {
		m [c] = {rand() % 50};
		if (b<m [c]) {
			f=c;
			b = m[c];
		}
		else if (a>m[c]){
			t=c;
			a = m[c];
		}
		summ = summ+ m[c];
		cout << m[c] << "\n";
		c++;
	}
	m[t] = b;
	m[f] = a;
	summ = summ/z;
	float p = (summ + (summ / 100 * 10));
	float o = (summ - (summ/ 100 * 10));
	while (c<z) {
		if (p > m[c] && o < m[c]) {
			cout << "\n chislo v promezhutke " << m[c] <<"\n";
		} else {
			m[c] = m[c++];
		}
		c=c+1;
		}
	
	cout <<"\n" << summ << " " << o << " " << p << "\n" << f << " " << a  << "\n" << t << " " << b;
	delete []m;
}