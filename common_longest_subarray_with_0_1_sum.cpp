#include <bits/stdc++.h>
using namespace std;
int max_common(int a[], int b[], int n)
{
    int result = 0;
    for (int i = 0; i < n; i++)
    {
        int sum1 = 0, sum2 = 0;
        for (int j = i; j < n; j++)
        {
            sum1 += a[j];
            sum2 += b[j];
            if (sum1 == sum2)
            {
                result = max(result, j - i + 1);
            }
        }
    }
    return result;
}
int longestCommonSum(int arr1[], int arr2[], int n)
{
    // Find difference between the two
    int arr[n];
    for (int i = 0; i < n; i++)
        arr[i] = arr1[i] - arr2[i];

    // Creates an empty hashMap hM
    unordered_map<int, int> hM;

    int sum = 0;     // Initialize sum of elements
    int max_len = 0; // Initialize result

    // Traverse through the given array
    for (int i = 0; i < n; i++)
    {
        // Add current element to sum
        sum += arr[i];

        // To handle sum=0 at last index
        if (sum == 0)
            max_len = i + 1;

        // If this sum is seen before,
        // then update max_len if required
        if (hM.find(sum) != hM.end())
            max_len = max(max_len, i - hM[sum]);

        else // Else put this sum in hash table
            hM[sum] = i;
    }

    return max_len;
}
int main()
{
    int arr1[] = {0, 1, 0, 1, 1, 1, 1};
    int arr2[] = {1, 1, 1, 1, 1, 0, 1};
    int n = sizeof(arr1) / sizeof(arr1[0]);
    cout << max_commonx(arr1, arr2, n);
    return 0;
}