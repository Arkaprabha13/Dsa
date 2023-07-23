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

        vector<long long> nextGreater(n, -1); // Initialize all elements with -1
        stack<long long> s;

        for (int i = 0; i < n; i++)
        {
            // While the stack is not empty and the current element is greater than the top of the stack
            while (!s.empty() && arr[i] > arr[s.top()])
            {
                nextGreater[s.top()] = arr[i]; // Set the next greater element for the element at the top of the stack
                s.pop();                       // Pop the element from the stack
            }                                  
            s.push(i); // Push the current index into the stack
        }

        return nextGreater;
    }
    void next_greater_element(vector<long long> arr, int n)
    {
        stack<long long> s;
        s.push(arr[n - 1]);
        cout << "-1 ";
        for (int i = n - 2; i >= 0; i--)
        {
            /* code */
            while (s.empty() == false && s.top() < arr[i])
            {
                s.pop();
            }
            int next_greater = (s.empty()) ? (-1) : (s.top());
            cout << next_greater << " ";
            s.push(arr[i]);
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

        int n;
        cin >> n;
        vector<long long> arr(n);
        for (int i = 0; i < n; i++)
            cin >> arr[i];

        Solution obj;
        vector<long long> res = obj.nextLargerElement(arr, n);
        
        for (long long i : res)
                cout
            << i << " ";
        cout << endl;
        cout << endl;
        obj.next_greater_element(arr,n);
    }
    return 0;
}
// } Driver Code Ends