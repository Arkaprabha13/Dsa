#include <bits/stdc++.h>
using namespace std;
// iterative
int lastOcc(int arr[], int n, int x)
{
    int low = 0, high = n - 1;

    while (low <= high)
    {
        int mid = (low + high) / 2;

        if (x > arr[mid])
            low = mid + 1;

        else if (x < arr[mid])
            high = mid - 1;

        else
        {
            if (mid == n - 1 || arr[mid + 1] != arr[mid])
                return mid;

            else
                low = mid + 1;
        }
    }

    return -1;
}

// recursive    
int lastOcc(vector<int> arr, int low, int high, int x, int n)
{
    if (low > high)
        return -1;

    int mid = (low + high) / 2;

    if (x > arr[mid])
        return lastOcc(arr, mid + 1, high, x, n);

    else if (x < arr[mid])
        return lastOcc(arr, low, mid - 1, x, n);

    else
    {
        if (mid == n - 1 || arr[mid + 1] != arr[mid])
            return mid;

        else
            return lastOcc(arr, mid + 1, high, x, n);
    }
}
int main()
{
    int n;
    cout << "Enter number of elements int the array -> ";
    cin >> n;
    vector<int> v;
    v.resize(n);
    for (int x = 0; x < n; x++)
    {
        cin >> v[x];
    }
    for (auto x : v)
    {
        cout << x << " ";
    }
    cout << endl
         << "last occurence of 3 is ->";
    cout << lastOcc(v, 0, n - 1, 3, n);

    return 0;
}