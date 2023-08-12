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
int main()
{
    int arr[] = {8, 3, 1, 5, -6, 6, 2, 2};
    int n = sizeof(arr) / sizeof(arr[0]);
    int sum = 4;
    cout << largest_subarray_with_given_sum(arr, n, sum);
    return 0;
}