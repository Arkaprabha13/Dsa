//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    vector<int> find(int arr[], int n, int x)
    {
        // code here

        vector<int> ans{-1, -1}; // Initialize with -1, indicating not found

        int low = 0;
        int high = n - 1;

        // Find the first occurrence of x
        while (low <= high)
        {
            int mid = low + (high - low) / 2; // Avoid potential integer overflow
            if (arr[mid] == x)
            {
                ans[0] = mid;
                high = mid - 1; // Continue searching in the left subarray
            }
            else if (arr[mid] < x)
            {
                low = mid + 1;
            }
            else
            {
                high = mid - 1;
            }
        }

        low = 0;
        high = n - 1;

        // Find the last occurrence of x
        while (low <= high)
        {
            int mid = low + (high - low) / 2;
            if (arr[mid] == x)
            {
                ans[1] = mid;
                low = mid + 1; // Continue searching in the right subarray
            }
            else if (arr[mid] < x)
            {
                low = mid + 1;
            }
            else
            {
                high = mid - 1;
            }
        }

        return ans;
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
        int arr[n], i;
        for (i = 0; i < n; i++)
            cin >> arr[i];
        vector<int> ans;
        Solution ob;
        ans = ob.find(arr, n, x);
        cout << ans[0] << " " << ans[1] << endl;
    }
    return 0;
}

// } Driver Code Ends