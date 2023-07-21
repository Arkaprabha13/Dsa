//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
/*You are required to complete this method */

class Solution
{
public:
    int josephus(int n, int k)
    {
        // using array
        // vector<int> people;
        //   //Your code here
        // for (int i = 1; i <= n; i++)
        //     people.push_back(i);

        // int index = 0;
        // while (people.size() > 1) {
        //     index = (index + k - 1) % people.size();
        //     people.erase(people.begin() + index);
        // }

        // return people[0];
        // }
        // using list
        list<int> people;
        for (int i = 1; i <= n; i++)
            people.push_back(i);

        auto it = people.begin();
        while (people.size() > 1)
        {
            for (int i = 0; i < k - 1; i++)
            {
                it++;
                if (it == people.end())
                    it = people.begin();
            }
            it = people.erase(it);
            if (it == people.end())
                it = people.begin();
        }

        return *people.begin();
    }
};

//{ Driver Code Starts.

int main()
{

    int t;
    cin >> t; // testcases
    while (t--)
    {
        int n, k;
        cin >> n >> k; // taking input n and k

        // calling josephus() function
        Solution ob;
        cout << ob.josephus(n, k) << endl;
    }
    return 0;
}
// } Driver Code Ends