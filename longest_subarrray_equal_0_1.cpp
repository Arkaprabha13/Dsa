#include <bits/stdc++.h>
using namespace std;
int largest_subarray_with_given_sum(int a[], int n, int sum)
{
    int prefix_suum = 0;
    int result = 0;
    unordered_map<int, int> m;
    for (int i = 0; i < n; i++)
    {
        prefix_suum += a[i];
        if (prefix_suum == sum)
        {
            result = i + 1;
        }
        if (m.find(prefix_suum) == m.end())
        {
            m.insert({prefix_suum, i});
        }
        if (m.find(prefix_suum - sum) != m.end())
        {
            result = max(result, i - m[prefix_suum - sum]);
        }
    }
    return result;
}
int long_sub(int a[], int n)
{
    int result = 0;
    for (int i = 0; i < n; i++)
    {
        int c_0 = 0, c_1 = 0;
        for (int j = i; j < n; j++)
        {
            if (a[i] == 0)
            {
                c_0++;
            }
            else
            {
                c_1++;
            }
            if (c_0 == c_1)
            {
                result = max(result, c_0 + c_1);
            }
        }
    }
    return result;
}
int largestZeroSubarray(int arr[], int n)
{
    for (int i = 0; i < n; i++)
        arr[i] = (arr[i] == 0) ? -1 : 1;

    unordered_map<int, int> ump;
    int sum = 0, maxLen = 0;
    for (int i = 0; i < n; i++)
    {
        sum += arr[i];
        if (sum == 0)
            maxLen = i + 1;

        if (ump.find(sum + n) != ump.end())
        {
            if (maxLen < i - ump[sum + n])
                maxLen = i - ump[sum + n];
        }
        else
            ump[sum + n] = i;
    }

    return maxLen;
}
int effficient(int a[], int n)
{
    for (int i = 0; i < n; i++)
    {
        if (a[i] == 0)
        {
            a[i] = -1;
        }
    }
    return largest_subarray_with_given_sum(a, n, 0);
}

int main()
{
    int arr[] = {1, 1, 1, 0, 1, 0, 1, 1, 1};
    int n = sizeof(arr) / sizeof(arr[0]);

    cout << largestZeroSubarray(arr, n);
    return 0;
}