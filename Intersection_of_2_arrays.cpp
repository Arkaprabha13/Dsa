//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function template for C++

class Solution
{
public:
    // Function to return the count of the number of elements in
    // the intersection of two arrays.
    int NumberofElementsInIntersection(int a[], int b[], int n, int m)
    {
        // Your code goes here
        unordered_set<int> s;
        int res = 0;
        if (m >= n)
        {
            for (int i = 0; i < n; i++)
            {
                s.insert(a[i]);
            }
            for (int i = 0; i < m; i++)
            {
                if (s.find(b[i]) != s.end())
                {
                    res++;
                    s.erase(b[i]);
                }
            }
            return res;
        }
        else
        {
            for (int i = 0; i < m; i++)
            {
                s.insert(b[i]);
            }
            for (int i = 0; i < n; i++)
            {
                if (s.find(a[i]) != s.end())
                {
                    res++;
                    s.erase(a[i]);
                }
            }
            return res;
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
        int a[n], b[m];
        for (int i = 0; i < n; i++)
            cin >> a[i];

        for (int i = 0; i < m; i++)
            cin >> b[i];
        Solution ob;
        cout << ob.NumberofElementsInIntersection(a, b, n, m) << endl;
    }
    return 0;
}
// } Driver Code Ends