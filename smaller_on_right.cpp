//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;

int countSmallerRight(int *,int );

int main(){
    
    int t;
    cin >> t;
    
    while(t--){
        int n;
        cin >> n;
        int arr[n];
        
        for(int i = 0;i<n;i++)
            cin >> arr[i];
        
        cout << countSmallerRight(arr,n) << endl;
        
    }
    
    return 0;
}
// } Driver Code Ends


// User function template for C++

// arr : given array'
// n : size of the array 
int  countSmaller(int arr[], int n , set<int>&ms)
{
    int res=0;
    for(int i=n-1;i>=0;i--)
    {
        ms.insert(arr[i]);
        int count=0;
        auto it = ms.lower_bound(arr[i]);
            count = distance(ms.begin(),it);
            res=max(count,res);
    }
    return res;
}
int countSmallerRight(int arr[], int n) {
    //code here
    set<int>ms;
    int ans = countSmaller(arr,n,ms);
    return ans;
}
