#include <iostream> 
using namespace std;
int main()
{
	int m, n;
	cout << "Vvedite znachenia m i n \n";
	cin >> m >> n;
	cout << "(n+1) * (m+1) \n" << (++n * ++m) << "\n";
	cout << "m++ < n? 1 da, 0 net \n" << (m++ < n) << "\n";
	cout << "n++ > m? 1 da, 0 net \n" << (n++ > m) << "\n";
	return 0;
}