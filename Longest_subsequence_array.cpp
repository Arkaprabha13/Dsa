#include <bits/stdc++.h>
using namespace std;
int longest_subsequence(int arr[], int n)
{
    sort(arr, arr + n);
    int result = 1;
    int current = 1;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == arr[i - 1] + 1)
        {
            current++;
        }
        else if (arr[i] != arr[i - 1])
        {
            result = max(result, current);
            current = 1;
        }
        return max(result, current);
    }
}
// using hasmap for O(n) time above sorting is O(nlogn)
int ls(int arr[], int n)
{
    // unordered_set<int> s(arr, arr + n);
    // int result = 1;
    // for (auto x : s)
    // {
    //     if (s.find(x - 1) == s.end())
    //     {
    //         int currrent = 1;
    //         while (s.find(x + 1) != s.end())
    //         {
    //             currrent++;
    //         }
    //         result = max(result, currrent);
    //     }
    // }
    // return result;

    unordered_set<int> s;
    int res = 0;

    for (int i = 0; i < n; i++)
        s.insert(arr[i]);

    for (int i = 0; i < n; i++)
    {
        if (s.find(arr[i] - 1) == s.end())
        {
            int curr = 1;
            while (s.find(curr + arr[i]) != s.end())
                curr++;

            res = max(res, curr);
        }
    }
    return res;
}
int main()
{
    int arr[] = {1, 9, 3, 4, 2, 10, 13};

    int n = sizeof(arr) / sizeof(arr[0]);
    cout << ls(arr, n);
    return 0;
}
