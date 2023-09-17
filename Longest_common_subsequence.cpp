#include <bits/stdc++.h>
using namespace std;
int lcs_recursion(string s1, string s2, int m, int n)
{

    if (m == 0 || n == 0)
    {
        return 0;
    }
    if (s1[m - 1] == s2[n - 1])
    {
        return lcs_recursion(s1, s2, m - 1, n - 1) + 1;
    }
    else
    {
        return max(lcs_recursion(s1, s2, m, n - 1), lcs_recursion(s1, s2, m - 1, n));
    }
}
// bootom up approach 
int lcs_using_tabulation(string s1, string s2)
{
    int m = s1.length();
    int n = s2.length();

    // Create a 2D array to store the length of LCS
    int dp[m + 1][n + 1];

    // Initialize the first row and first column to 0
    for (int i = 0; i <= m; i++)
    {
        for (int j = 0; j <= n; j++)
        {
            if (i == 0 || j == 0)
            {
                dp[i][j] = 0;
            }
        }
    }

    // Fill in the dp table using a bottom-up approach
    for (int i = 1; i <= m; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (s1[i - 1] == s2[j - 1])
            {
                dp[i][j] = dp[i - 1][j - 1] + 1;
            }
            else
            {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }
    return dp[m][n];
}
// top down approach
int lcs_using_memozisation(string s1, string s2, int m, int n, vector<vector<int>> &memo)
{
    if (memo[m][n] != -1)
    {
        return memo[m][n];
    }
    if (m == 0 || n == 0)
    {
        memo[m][n] = 0;
    }
    else if (s1[m - 1] == s2[n - 1])
    {
        memo[m][n] = 1 + lcs_using_memozisation(s1, s2, m - 1, n - 1, memo);
    }
    else
    {
        memo[m][n] = max(lcs_using_memozisation(s1, s2, m - 1, n, memo), lcs_using_memozisation(s1, s2, m, n - 1, memo));
    }
    return memo[m][n];
}
int main()
{
    string s1, s2;
    cout << "Enter the 1st string -> ";
    cin >> s1;
    cout << "Enter the 2nd string -> ";
    cin >> s2;

    // 2d array for memozization
    vector<vector<int>> memo(s1.length() + 1, vector<int>(s2.length() + 1, -1));

    cout << "The longest common subsequence is  -> " << lcs_recursion(s1, s2, s1.length(), s2.length()) << endl;
    cout << "\nThe longest common subsequence using tabulation is  -> " << lcs_using_tabulation(s1, s2) << endl;
    cout << "\nThe longest common subsequence using Memozisation is  -> " << lcs_using_memozisation(s1, s2, s1.length(), s2.length(), memo) << endl;
    return 0;
}
