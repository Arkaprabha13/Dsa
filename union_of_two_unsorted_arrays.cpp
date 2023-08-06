#include <bits/stdc++.h>
using namespace std;
// Binary search for arr2[i] in arr1[]
bool binary_search(int x, int *arr, int m)
{
    int left = 0;
    int right = m - 1;

    while (left <= right)
    {
        int mid = left + (right - left) / 2;

        if (arr[mid] == x)
        {
            return true;
        }
        else if (arr[mid] < x)
        {
            left = mid + 1;
        }
        else
        {
            right = mid - 1;
        }
    }

    return false;
}
bool search(int x, int *arr, int m)
{
    for (int i = 0; i < m; i++)
    {
        if (arr[i] == x)
            return true;
        return false;
    }
}
void print_2_Union(int arr1[], int arr2[], int m, int n)
{
    // Printing arr1[]
    for (int i = 0; i < m; i++)
    {
        cout << arr1[i];
    }

    // Printing arr2[]
    for (int i = 0; i < n; i++)
    {
        // Searching for elements
        if (!search(arr2[i], arr1, m))
        {
            cout << arr2[i];
        }
    }
}
void printUnion(int arr1[], int arr2[], int m, int n)
{
    // Printing arr1[]
    for (int i = 0; i < m; i++)
    {
        cout << arr1[i]<<" ";
    }

    // Sort using QuickSort
    sort(arr1, arr1 + m);

    // Printing arr2[]
    for (int i = 0; i < n; i++)
    {
        // Searching for elements
        if (!search(arr2[i], arr1, m))
        {
            cout << arr2[i]<<" ";
        }
    }
}

// Using unorderred set

void print_union(int a[], int b[], int n, int m)
{
    unordered_set<int> s;
    for (int i = 0; i < n; i++)
    {
        cout << a[i] << " ";
        s.insert(a[i]);
    }
    for (int i = 0; i < m; i++)
    {
        if (s.find(b[i]) == s.end())
        {
            cout << b[i] << " ";
        }
    }
}
int main()
{
    int arr1[] = {7, 6, 13, 10};
    int m = 4;

    // Second array arr2[]
    int arr2[] = {10, 9, 4, 5, 7, 20};
    int n = 6;

    // Calling the Union method
    printUnion(arr1, arr2, m, n);
    return 0;
}
