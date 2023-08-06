#include <bits/stdc++.h>
using namespace std;
int max_distinct_items(int a[], int n, int k)
{
    unordered_set<int> s;
    for (int i = 0; i < n; i++)
    {
        s.insert(a[i]);
    }
    int d = s.size();
    if (d >= n / k)
    {
        return n / k;
    }
    else
    {
        return d;
    }
}
int main()
{
    int arr[] = {1, 1, 2, 2, 3, 3};
    int n = 6;
    cout << max_distinct_items(arr, n,2);
    return 0;
}