#include <iostream>
#include <cstdarg>
using namespace std;
float mult(int count, ...)
{
    float result = 1;
    va_list data;
    va_start(data, count);
    for (int i = 0; i < count; ++i)
    {
        result *= va_arg(data, double);
    }
    va_end(data);
    return result;
}
void main()
{
    setlocale(LC_ALL, "Russian");
    cout << "функция с 3 параметрами " << mult(3, 100.0f, 10.0f, 0.1f) << "\n";
    cout << "функция с 7 параметрами " << mult(7, 1000.0f, 10.1f, 0.1f, 0.01f, 10.0f, 0.1f, 10.0f) << "\n";
    cout << "функция с 11 параметрами " << mult(11, 1.0f, 1000.0f, 10.1f, 0.1f, 0.01f, 10.0f, 0.1f, 10.0f, 100.0f, 10.0f, 0.1f) << "\n";
}