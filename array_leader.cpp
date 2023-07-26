#include <bits/stdc++.h>
using namespace std;
void leader(int *arr, int n)
{
    //    NAIVE SOLUTION
    // for (int i = 0; i < n; i++)
    // {
    //     bool flag = false;
    //     for (int j = i + 1; j < n; j++)
    //     {
    //         if (arr[i] <= arr[j])
    //         {
    //             flag=true;
    //             break;
    //         }
    //     }
    //     if(flag==false)
    //     {
    //         cout<<arr[i]<<" ";
    //     }
    // }
    int current_leader = arr[n - 1];
    cout << arr[n - 1]<<" ";
    for (int i = n - 2; i >= 0; i--)
    {
        if (current_leader < arr[i])
        {
            current_leader = arr[i];
            cout << current_leader<<" ";
        }
    }
}

int main()
{
    int n;
    cout << "N-> ";
    cin >> n;
    cout << endl;
    int *a = new int[n]; // Allocate memory for the array

    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    leader(a, n);

    return 0;
}