#include <bits/stdc++.h>
using namespace std;
int median_of_matrix(int **a, int r, int c)
{
    int min = a[0][0];
    int max = a[0][c - 1];
    for (int i = 1; i < r; i++)
    {
        if (a[i][0] < min)
        {
            min = a[i][0];
        }
        if (a[i][c - 1] > max)
        {
            max = a[i][c - 1];
        }
    }
    int median_position = (r * c + 1) / 2;
    while (min < max)
    {
        int mid = (min + max) / 2;
        int mid_position = 0;
        for (int i = 0; i < r; i++)
        {
            mid_position += upper_bound(a[i], a[i] + c, mid) - a[i];
        }
        if (mid_position < median_position)
        {
            min = mid + 1;
        }
        else
        {
            max = mid;
        }
    }
    return min;
}

int matMed(int **mat, int r, int c)
{
    int min = mat[0][0], max = mat[0][c - 1];
    for (int i = 1; i < r; i++)
    {
        if (mat[i][0] < min)
            min = mat[i][0];

        if (mat[i][c - 1] > max)
            max = mat[i][c - 1];
    }

    int medPos = (r * c + 1) / 2;
    while (min < max)
    {
        int mid = (min + max) / 2;
        int midPos = 0;

        for (int i = 0; i < r; ++i)
            midPos += upper_bound(mat[i], mat[i] + c, mid) - mat[i];
        if (midPos < medPos)
            min = mid + 1;
        else
            max = mid;
    }
    return min;
}
int main()
{
    int r, c;
    cout << "R-> ";
    cin >> r;
    cout << "C-> ";
    cin >> c;
    int **arr;
    arr = new int *[r];
    for (int i = 0; i < r; i++)
    {
        arr[i] = new int[c];
    }
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            cin >> arr[i][j];

            // cout << arr100[i][j] << " ";
        }
    }
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)

        {
            cout << arr[i][j] << " ";
        }

        cout << endl;
    }
    cout << endl
         << "median -> " << median_of_matrix(arr, r, c);
    cout << endl
         << "median -> " << matMed(arr, r, c);
    return 0;
}