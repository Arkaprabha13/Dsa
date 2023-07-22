#include <bits/stdc++.h>
using namespace std;
void BT(int r, int c, int **arr)
{

    if (r == 1)
    {
        for (int i = 0; i < c; i++)
            cout << arr[0][i] << " ";
    }
    else if (c == 1)
    {
        for (int i = 0; i < r; i++)
            cout << arr[i][0] << " ";
    }
    else
    {
        for (int i = 0; i < c; i++)
            cout << arr[0][i] << " ";
        for (int i = 1; i < r; i++)
            cout << arr[i][c - 1] << " ";
        for (int i = c - 2; i >= 0; i--)
            cout << arr[r - 1][i] << " ";
        for (int i = r - 2; i >= 1; i--)
            cout << arr[i][0] << " ";
    }
}

int main()
{
    int r, c;
    cout << "R-> ";
    cin >> r;
    cout << "C-> ";
    cin >> c;
    // int arr[r][c];
    // for (int i = 0; i < r; i++)
    // {
    //     for (int j = 0; j < c; j++)
    //     {
    //         cin >> arr[i][j];
    //     }
    // }
    // cout << "Your matrix is : \n";
    // for (int i = 0; i < r; i++)
    // {
    //     for (int j = 0; j < c; j++)
    //     {
    //         cout << arr[i][j] << " ";
    //     }
    //     cout << endl;
    // }
    cout << "Your matrix is : \n";
    int **arr100;

    arr100 = new int *[r];

    for (int i = 0; i < r; i++)
        arr100[i] = new int[c];

    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            cin >> arr100[i][j];

            // cout << arr100[i][j] << " ";
        }
    }
    cout << endl
         << "my matric -> " << endl;
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            // cin >> arr100[i][j];

            cout << arr100[i][j] << " ";
        }
        cout << endl;
    }
    cout << "\nboundary\n";
    BT(r, c, arr100);
    return 0;
}