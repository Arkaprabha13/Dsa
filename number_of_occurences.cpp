//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

// } Driver Code Ends
// User function template for C++
class Solution
{
public:
    /* if x is present in arr[] then returns the count
        of occurrences of x, otherwise returns 0. */
    // int count(int arr[], int n, int x) {
    //     // code here
    //   unordered_map<int, int> m;
    //     for (int i = 0; i < n; i++)
    //     {
    //         m[arr[i]]++;
    //     }
    //     for (auto k : m)
    //     {
    //         if (k.first == x)
    //         {
    //             // cout << k.second;
    //             return k.second;

    //         }
    //     }
    //     return 0;
    // }
    int upperbound(int a[], int n, int x)
    {
        int low = 0;
        int high = n - 1;
        int ans = n;
        while (low <= high)
        {
            int mid = (low + high) / 2;
            if (a[mid] <= x)
            {
                low = mid + 1;
            }
            else
            {
                high = mid - 1;
                ans = mid; // Update ans only when a[mid] > x
            }
        }
        return ans;
    }
    int lowerbound(int a[], int n, int x)
    {
        int low = 0;
        int high = n - 1;
        int ans = n;
        while (low <= high)
        {
            int mid = (low + high) / 2;
            if (a[mid] >= x)
            {
                high = mid - 1;
                ans = mid; // Update ans only when a[mid] >= x
            }
            else
            {
                low = mid + 1;
            }
        }
        return ans;
    }
    int count(int arr[], int n, int x)
    {
        // code here
        return (upperbound(arr, n, x) - lowerbound(arr, n, x));
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, x;
        cin >> n >> x;
        int arr[n];
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.count(arr, n, x);
        cout << ans << "\n";
    }
    return 0;
}

// } Driver Code Ends