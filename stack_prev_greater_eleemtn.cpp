//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    // Function to find the next greater element for each element of the array.
    vector<long long> nextLargerElement(vector<long long> arr, int n)
    {
        // Your code here
        vector<long long> v;
        // vector<int>v;
        stack<long long> s;
        s.push(arr[0]);
        v.push_back(-1);
        for (int i = 0; i < n; i++)
        {
            while (s.empty() == false && s.top() <= arr[i])
            {
                s.pop();
            }
            long long span = (s.empty()) ? (-1) : s.top();
            v.push_back(span);
            s.push(arr[i]);
        }
        return v;
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {

        int n;
        cin >> n;
        vector<long long> arr(n);
        for (int i = 0; i < n; i++)
            cin >> arr[i];

        Solution obj;
        vector<long long> res = obj.nextLargerElement(arr, n);
        for (long long i : res)
            cout << i << " ";
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends