#include <bits/stdc++.h>
using namespace std;
void spiral_matrix(int **a, int r, int c)
{
    // a = new int *[r];
    // for (int i = 0; i < r; i++)
    // {
    //     a[i] = new int[c];
    // }
    int left = 0, top = 0, bottom = r - 1, right = c - 1;
    while (top <= bottom && left <= right)
    {
        for (int i = left; i <= right; i++)
        {
            cout << a[top][i] << " ";
        }
        top++;
        for (int i = top; i <= bottom; i++)
        {
            cout << a[i][right] << " ";
        }
        right--;
        if (top <= bottom)
        {
            for (int i = right; i >= left; i--)
            {
                cout << a[bottom][i] << " ";
            }
            bottom--;
        }

        if (left <= right)
        {
            for (int i = bottom; i >= top; i--)
            {
                cout << a[i][left] << " ";
            }
            left++;
        }
    }
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
         << "spiral matrix -> \n";
    spiral_matrix(arr, r, c);

    return 0;
}