#include <iostream>
using namespace std;

int main()
{
    int rows1, cols1, rows2, cols2;
    cout << "Enter the number of rows and columns of first matrix: ";
    cin >> rows1 >> cols1;
    int mat1[rows1][cols1];
    cout << "Enter the first matrix:\n";
    for (int i = 0; i < rows1; i++)
        for (int j = 0; j < cols1; j++)
            cin >> mat1[i][j];
    cout << "Enter the number of rows and columns of second matrix: ";
    cin >> rows2 >> cols2;
    int mat2[rows2][cols2];
    cout << "Enter the second matrix:\n";
    for (int i = 0; i < rows2; i++)
        for (int j = 0; j < cols2; j++)
            cin >> mat2[i][j];
    if (cols1 != rows2)
    {
        cout << "Matrix multiplication not possible.";
        return 0;
    }
    int ans[rows1][cols2];
    for (int i = 0; i < rows1; i++)
        for (int j = 0; j < cols2; j++)
        {
            ans[i][j] = 0;
            for (int k = 0; k < rows1; k++)
                ans[i][j] += mat1[i][k] * mat2[k][j];
        }
    for (int i = 0; i < rows1; i++)
    {
        for (int j = 0; j < cols2; j++)
            cout << ans[i][j] << " ";
        cout << "\n";
    }
    return 0;
}