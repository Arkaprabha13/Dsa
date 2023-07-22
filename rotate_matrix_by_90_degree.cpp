#include <bits/stdc++.h>
using namespace std;
void rotate_by_90_degree(int **a, int n)
{
    int **temp;
    temp = new int *[n];
    for (int i = 0; i < n; i++)
    {
        temp[i] = new int[n];
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            temp[n - j - 1][i] = a[i][j];
        }
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            a[i][j] = temp[i][j];
        }
    }
}
void effcient_rotaion(int **a, int n)
{
    // transpose
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            swap(a[i][j], a[j][i]);
        }
    }
    // reverse
    for (int i = 0; i < n; i++)
    {
        int low = 0, high = n - 1;
        while (low < high)
        {
            swap(a[low][i], a[high][i]);
            low++;
            high--;
        }
    }
}
int main()
{
    int n;
    cout << "N-> ";
    cin >> n;
    int **arr;
    arr = new int *[n];
    for (int i = 0; i < n; i++)
    {
        arr[i] = new int[n];
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> arr[i][j];

            // cout << arr100[i][j] << " ";
        }
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)

        {
            cout << arr[i][j] << " ";
        }

        cout << endl;
    }
    cout << endl
         << "Rotate bye 90 degfree -> " << endl;
    effcient_rotaion(arr, n);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)

        {
            cout << arr[i][j] << " ";
        }

        cout << endl;
    }
    return 0;
}