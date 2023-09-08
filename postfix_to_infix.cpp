//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution
{
public:
    string postToInfix(string a)
    {
        stack<string> s; // Use a stack of strings to hold operands and sub-expressions
        for (int i = 0; i < a.length(); i++)
        {
            if ((a[i] >= 'a' && a[i] <= 'z') || (a[i] >= 'A' && a[i] <= 'Z'))
            {
                // If it's an operand, push it onto the stack as a string
                string operand(1, a[i]);
                s.push(operand);
            }
            else
            {
                // If it's an operator, pop two operands from the stack, combine them with the operator,
                // and push the result back onto the stack as a sub-expression
                string operand_1 = s.top();
                s.pop();
                string operand_2 = s.top();
                s.pop();

                string sub_expression = "(" + operand_2 + a[i] + operand_1 + ")";
                s.push(sub_expression);
            }
        }

        return s.top(); // The final result is at the top of the stack
    }
};

//{ Driver Code Starts.

int main()
{
    int t = 1;
    cin >> t;

    // freopen ("output_gfg.txt", "w", stdout);

    while (t--)
    {
        // Input
        string postfix;
        cin >> postfix;
        // char marker; cin >> marker;

        Solution obj;
        cout << obj.postToInfix(postfix) << endl;

        // cout << "~\n";
    }
    fclose(stdout);

    return 0;
}

// } Driver Code Ends