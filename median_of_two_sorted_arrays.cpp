//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function template for C++

class Solution
{
public:
    // Function to find the median of the two arrays when they get merged.
    int findMedian(int a1[], int n1, int a2[], int n2)
    {
        // code here
        //     int begin1 = 0, end1 = n1;

        // 	while(begin1 < end1)
        // 	{
        // 		int i1 = (begin1 + end1) / 2;
        // 		int i2 = (n1 + n2 + 1) / 2 - i1;

        // 		int min1 = (i1 == n1)?INT_MAX:a1[i1];
        // 		int max1 = (i1 == 0)?INT_MIN:a1[i1 - 1];

        // 		int min2 = (i2 == n2)?INT_MAX:a2[i2];
        // 		int max2 = (i2 == 0)?INT_MIN:a2[i2 - 1];

        // 		if(max1 <= min2 && max2 <= min1)
        // 		{
        // 			if((n1 + n2) % 2 == 0)
        // 				return ((double)max(max1, max2) + min(min1, min2)) / 2;
        // 			else
        // 				return (double)max(max1, max2);
        // 		}
        // 		else if(max1 > min2)
        // 			end1 = i1 - 1;
        // 		else
        // 			begin1 = i1 + 1;
        // 	    }return -1;
        int ans[n2 + n1];
        for (int i = 0; i < n1; i++)
        {
            ans[i] = a1[i];
        }
        for (int i = 0; i < n2; i++)
        {
            ans[n1 + i] = a2[i];
        }
        sort(ans, ans + n1 + n2);
        int s = n2 + n1;
        if (s & 1)
        {
            int media = (ans[s / 2]);
            return media;
        }
        else
        {
            int media = ((ans[s / 2] + ans[(s - 1) / 2]) / 2);
            return media;
        }
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        int n, m;
        cin >> n >> m;
        int arr[n];
        int brr[m];

        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }

        for (int i = 0; i < m; i++)
        {
            cin >> brr[i];
        }
        Solution obj;
        if (n < m)
            cout << obj.findMedian(arr, n, brr, m) << endl;
        else
            cout << obj.findMedian(brr, m, arr, n) << endl;
    }
}
// } Driver Code Ends