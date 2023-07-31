#include <bits/stdc++.h>
using namespace std;
int index_of_first_occurences(vector<int> v, int x)
{
    int n = v.size();
    for (int i = 0; i < n; i++)
    {
        if (v[i] == x)
        {
            return i;
        }
    }
    return -1;
}
int recursive_efficient(vector<int> v, int low, int high, int x)
{
    // int high = v[v.size() - 1], low = v[0], mid;
    if (low > high)
    {
        return -1;
    }
    int mid = (low + high) / 2;
    if (x > v[mid])
    {
        return recursive_efficient(v, mid + 1, high, x);
    }
    else if (x < v[mid])
    {
        return recursive_efficient(v, low, mid - 1, x);
    }
    else
    {
        if (mid == 0 || v[mid - 1] != v[mid])
        {
            return mid;
        }
        else
        {
            return recursive_efficient(v, low, mid - 1, x);
        }
    }
}
//iterative function
int firstOcc(int arr[], int n, int x)
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
            if (mid == 0 || arr[mid - 1] != arr[mid])
                return mid;

            else
                high = mid - 1;
        }
    }

    return -1;
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
         << "First occurence of 3 is ->";
    cout << recursive_efficient(v, 0, n - 1, 3);
    return 0;
}