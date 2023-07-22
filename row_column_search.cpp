#include <bits/stdc++.h>
using namespace std;
void naive_search(int **mat, int r, int c, int x)
{
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            if (mat[i][j] == x)
            {
                cout << "found at [" << i << "][" << j << "] -> " << x;
                return;
            }
        }
    }
    cout << "\nNot found \n";
}
void efficient_search(int **a, int r, int c, int x)
{
    int i = 0,
        j = c - 1;
    while (i < r && j >= 0)
    {
        if (a[i][j] == x)
        {
            cout << "found at [" << i << "][" << j << "] -> " << x;
            return;
        }
        else if (a[i][j] > x)
        {
            j--;
        }
        else
        {
            i++;
        }
    }
    cout << "\nNot found \n";
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
    cout << endl;
    int x;
    cout << "\nENter the element for search -> ";
    cin >> x;
    efficient_search(arr, r, c, x);
    return 0;
}