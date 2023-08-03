//{ Driver Code Starts
//Initial function template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++


class Solution
{
    public:
    //Function to find repeated element and its frequency.
    pair<long, long> findRepeating(long *arr, int n){
        //code here
       pair<long,long> ans;
        int l=0;
        int h=n-1;
        while(l<h){
            int mid=(l+h)/2;
            if(arr[mid]>=(arr[0]+mid)){
                l=mid+1;
            }
            else{
                h=mid;
            }
        }
        if(n-(arr[n-1]-arr[0])==1){
            ans={-1,-1};
        }
        else{
        ans={arr[l],n-(arr[n-1]-arr[0])};
        }
        return ans;}
};

//{ Driver Code Starts.

int main() {
	
	int t;
	cin >> t;
	
	while(t--){
	    int n;
	    cin >> n;
	    long arr[n];
	    
	    for(int i = 0;i<n;i++){
	        cin >> arr[i];
	    }
	    Solution obj;
	    pair<long, long> ans = obj.findRepeating(arr,n);
	    
	    cout << ans.first << " " << ans.second << endl;
	    
	}
	
}
// } Driver Code Ends
