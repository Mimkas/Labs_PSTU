#include <iostream>
using namespace std;
void workmatrix(int matrix[])
{
    int bof = matrix[2];
    matrix[2] = matrix[3];
    matrix[3] = matrix[1];
    matrix[1] = matrix[0];
    matrix[0] = bof;
    for (bof = 0; bof < 4; bof++)
    {
        cout << matrix[bof] << "\t";
        if (bof == 1) cout << "\n\n";
    }
    if (matrix[0] == matrix[2] && matrix[1] == matrix[0] && matrix[2] == matrix[3] && matrix[3] == matrix[1])
    {
        cout << "матрица симметрична";
    }
    else cout << "матрица не симметрична";
}

void main()
{
    setlocale(LC_ALL, "Rus");
    int matrix[4];
    for (int i = 0; i < 4; i++)
    {
        cout << "Введите число для создания матрицы " << i + 1 << "\t";
        cin >> matrix[i];
    }
    workmatrix(matrix);
}
