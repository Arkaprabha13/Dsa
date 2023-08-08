//{ Driver Code Starts
// A C++ program to find if there is a zero sum
// subarray
#include <bits/stdc++.h>
using namespace std;



// } Driver Code Ends
class Solution{
    public:
    //Complete this function
    //Function to check whether there is a subarray present with 0-sum or not.
    bool subArrayExists(int arr[], int n)
    {
        //Your code here
      unordered_set<int> s;
    int prefix_sum = 0;
    s.insert(0);  // Inserting 0 as a prefix sum to cover cases where the subarray itself sums up to 0.
    
    for (int i = 0; i < n; i++)
    {
        prefix_sum += arr[i];  // Calculate the prefix sum up to the current element.
        
        if (s.find(prefix_sum) != s.end())
        {
            return true;  // If the current prefix sum is already in the set, a subarray with sum 0 is found.
        }
        else if (prefix_sum == 0)
        {
            return true;  // If the prefix sum is 0, a subarray starting from the beginning has sum 0.
        }
        
        s.insert(prefix_sum);  // Insert the current prefix sum into the set.
    }
    
    return false;  // If no subarray with sum 0 is found, return false
    }
};

//{ Driver Code Starts.
// Driver code
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
	    int n;
	    cin>>n;
	    int arr[n];
	    for(int i=0;i<n;i++)
	    cin>>arr[i];
	    Solution obj;
	    	if (obj.subArrayExists(arr, n))
		cout << "Yes\n";
	else
		cout << "No\n";
	}
	return 0;
}
// } Driver Code Ends