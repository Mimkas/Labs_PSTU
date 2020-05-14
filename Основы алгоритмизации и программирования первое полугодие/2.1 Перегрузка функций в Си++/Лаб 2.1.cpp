#include <iostream>
using namespace std;
void summ(double x, double y)
{
    cout << "\nфункция для сложения вещественных чисел:\n";
    cout << x << " + " << y << " = " << (x + y);
}
void summ(float xi, float xc, float yi, float yc)
{
    cout << "\nфункция для сложения комплексных чисел:\n";
    cout << xi << xc << " + " << yi << yc << " = " << xi + yi << "+i" << xc + yc;
}
int main()
{
    setlocale(LC_ALL, "Russian");
    float ai, bi, ac, bc;
    double ad, bd;
    cout << "Введите основную часть комплексного числа 1\t";
    cin >> ai;
    cout << "\nВведите вторичную часть комлексного числа 1\t";
    cin >> ac;
    cout << "\nВведите основную часть комплексного числа 2\t";
    cin >> bi;
    cout << "\nВведите вторичную часть комлексного числа 2\t";
    cin >> bc;
    cout << "\nВведите вещественное число 1\t";
    cin >> ad;
    cout << "\nВведите вещественное число 2\t";
    cin >> bd;
    summ(ai, ac, bi, bc);
    summ(ad, bd);
}
