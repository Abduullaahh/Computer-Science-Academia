// Abdullah Tahir
// 21L-5419
// OOP LAB 5
// l215419@lhr.nu.edu.pk

#include <iostream>
using namespace std;

void RotateMatrix(int** a, int m, int n);

int main()
{
    int n, m, N, M;
    int **a;

    cout << "Enter rows : "; cin >> m;
    cout << "Enter columns : "; cin >> n;

    a = new int* [m];
    for (int i = 0; i < n; i++)
    {
        a[i] = new int[n];
    }
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> a[i][j];
        }
    }

    cout << "\nReal Matrix :-\n\n";
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << a[i][j] << "\t";
        }
        cout << endl << endl << endl;
    }

    M = m;
    N = n;

    RotateMatrix(a, m, n);

    cout << "\nRotated Matrix :-\n\n";
    for (int i = 0; i < M; i++)
    {
        for (int j = 0; j < N; j++)
        {
            cout << a[i][j] << "\t";
        }
        cout << endl << endl << endl;
    }

    return 0;
}

void RotateMatrix(int** a, int m, int n)
{
    int row = 0, col = 0, pev, cur;

    for (; row < m && col < n;)
    {

        if (row + 1 == m || col + 1 == n)
        {
            break;
        }

        pev = a[row + 1][col];

        for (int i = col; i < n; i++)
        {
            cur = a[row][i];
            a[row][i] = pev;
            pev = cur;
        }
        row++;

        for (int i = row; i < m; i++)
        {
            cur = a[i][n - 1];
            a[i][n - 1] = pev;
            pev = cur;
        }
        n--;

        if (row < m)
        {
            for (int i = n - 1; i >= col; i--)
            {
                cur = a[m - 1][i];
                a[m - 1][i] = pev;
                pev = cur;
            }
        }
        m--;

        if (col < n)
        {
            for (int i = m - 1; i >= row; i--)
            {
                cur = a[i][col];
                a[i][col] = pev;
                pev = cur;
            }
        }
        col++;
    }
}