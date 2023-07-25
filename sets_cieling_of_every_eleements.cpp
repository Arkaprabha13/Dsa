#include <bits/stdc++.h>
using namespace std;
// naive method
void print_cieling(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        int diff = INT_MAX;
        for (int j = i + 1; j < n; j++)
        {
            if (arr[j] >= arr[i])
            {
                diff = min(diff, arr[j] - arr[i]);
            }
        }
        if (diff == INT_MAX)
        {
            cout << " -1 ";
        }
        else
        {
            cout << arr[i] + diff << " ";
        }
    }
}
void print_cieling_right(int arr[], int n)
{
    set<int> s;
    int result[n];
    for (int i = n-1; i >=0; i--)
    {
        auto it = s.lower_bound(arr[i]);
        if (it == s.end())
        {
            result[i] = -1;
        }
        else
        {
            result[i] = *it;
        }
        s.insert(arr[i]);
    }
    for (int i = 0; i < n; i++)
    {
        cout << result[i] << " ";
    }
}
int main()
{
    return 0;
}