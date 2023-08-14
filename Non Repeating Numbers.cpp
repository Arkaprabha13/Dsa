//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    vector<int> singleNumber(vector<int> nums) 
    {
        // Code here.
         sort(nums.begin(),nums.end());
        vector<int> v;
        int c=0;
        for(int i=0;i<nums.size()-1;i++){
            if(nums[i]==nums[i+1]) c++;
            else{
                if(c==0) v.push_back(nums[i]);
                c=0;
            }
        }
        if(nums[nums.size()-1]!=nums[nums.size()-2]) 
                v.push_back(nums[nums.size()-1]);
        return v;
    }
};

//{ Driver Code Starts.
int main(){
    int T;
    cin >> T;
    while(T--)
    {
    	int n; 
    	cin >> n;
    	vector<int> v(2 * n + 2);
    	for(int i = 0; i < 2 * n + 2; i++)
    		cin >> v[i];
    	Solution ob;
    	vector<int > ans = ob.singleNumber(v);
    	for(auto i: ans)
    		cout << i << " ";
    	cout << "\n";
    }
	return 0;
}
// } Driver Code Ends
