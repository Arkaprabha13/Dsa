//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
	// Complete this function
	void per(string s, int i, int n, vector<string> &v)
	{
		if (i == n - 1)
		{
			v.push_back(s);
			return;
		}
		for (int j = i; j < n; j++)
		{
			swap(s[i], s[j]);
			per(s, i + 1, n, v);
			swap(s[j], s[i]);
		}
	}
	vector<string> permutation(string S)
	{
		// Your code here
		vector<string> v;
		per(S, 0, S.size(), v);
		sort(v.begin(), v.end());
		return v;
	}
};

//{ Driver Code Starts.

int main()
{
	int T;
	cin >> T;
	while (T--)
	{
		string S;
		cin >> S;
		Solution ob;
		vector<string> vec = ob.permutation(S);
		for (string s : vec)
		{
			cout << s << " ";
		}
		cout << endl;
	}
	return 0;
}
// } Driver Code Ends