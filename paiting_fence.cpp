#include <bits/stdc++.h>
using namespace std;
int solve_using_recursion(int n, int k)
{
    if (n == 1)
    {
        return k;
    }
    if (n == 2)
    {
        return k + k * (k - 1); // k*k
    }
    int ans = (solve_using_recursion(n - 1, k) + solve_using_recursion(n - 2, k)) * (k - 1);
    return ans;
}

int solve_ussing_memo(int n, int k, vector<int> &dp)
{
    if (n == 1)
    {
        return k;
    }
    if (n == 2)
    {
        return k + k * (k - 1); // k*k
    }
    if (dp[n] != -1)
    {
        return dp[n];
    }
    int ans = (solve_ussing_memo(n - 1, k, dp) + solve_ussing_memo(n - 2, k, dp)) * (k - 1);
    dp[n] = ans;
    return ans;
}
int solve_using_tabulation(int n, int k)
{
    vector<int> dp(n + 1, 0);
    dp[1] = k;
    dp[2] = k * k;

    for (int i = 3; i <= n; i++)
    {
        dp[i] = ((dp[i - 1] + dp[i - 2]) * (k - 1));
    }
    return dp[n];
}
int spacce_optimised_solution(int n, int k)
{
    int prev2 = k;
    int prev1  = k * k;

    for (int i = 3; i <= n; i++)
    {
        int current = ((prev1 + prev2) * (k - 1));

        prev2 = prev1;
        prev1 = current;
    }
    return prev1;
}
int main()
{
    int n = 4;
    int k = 3;
    vector<int> dp(n + 1, -1);
    int ans = spacce_optimised_solution(n, k);
    cout << "ans -> " << ans << endl;
    return 0;
}