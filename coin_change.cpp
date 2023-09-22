#include <bits/stdc++.h>
using namespace std;
int solve_memo(vector<int> &coins, int amount, vector<int> &dp)
{
    if (amount == 0)
    {
        return 0;
    }
    if (amount < 0)
    {
        return INT_MAX;
    }
    if (dp[amount] != -1)
    {
        return dp[amount];
    }
    int minimum = INT_MAX;
    for (int i = 0; i < coins.size(); i++)
    {
        int ans = solve_memo(coins, amount - coins[i], dp);
        if (ans != INT_MAX)
        {
            minimum = min(minimum, 1 + ans);
        }
    }
    dp[amount] = minimum;
    return minimum;
}

int solve_tabulation(vector<int> &coins, int amount)
{
    vector<int> dp(amount + 1, INT_MAX);
    dp[0] = 0;

    for (int i = 1; i <= amount; i++)
    {
        for (int j = 0; j < coins.size(); j++)
        {
            if (i - coins[j] >= 0 && dp[i - coins[j]] != INT_MAX)
            {
                int ans = dp[i - coins[j]];
                dp[i] = min(dp[i], 1 + ans);
            }
        }
    }
    return dp[amount];
}
int coinChange(vector<int> &coins, int amount)
{
    vector<int> dp(amount + 1, -1);
    int ans = solve_tabulation(coins, amount);
    if (ans == INT_MAX)
    {
        return -1;
    }
    else
        return ans;
}
int main()
{
   
    int n;
    cout << "Enter number of coins - >";
    cin >> n;
     vector<int> coins(n);
    int amount;
    cout << "Amoutn -> ";
    cin >> amount;
    for (int i = 0; i < n; i++)
    {
        int value;
        cin >> value;
        coins.push_back(value);
    }
    cout << coinChange(coins, amount);
    return 0;
}