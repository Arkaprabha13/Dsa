#include <bits/stdc++.h>
using namespace std;
int solve_using_recursion(int weight[], int value[], int index, int capacity)
{
    // for one item
    if (index == 0)
    {
        if (weight[0] <= capacity)
        {
            return value[0];
        }
        else
        {
            return 0;
        }
    }
    int include = 0;
    if (weight[index] <= capacity)
    {
        include = solve_using_recursion(weight, value, index - 1, capacity - weight[index]) + value[index];
    }
    int exclude = solve_using_recursion(weight, value, index - 1, capacity);

    int ans = max(exclude, include);
    return ans;
}
int solve_using_memo(int weight[], int value[], int index, int capacity, vector<vector<int>> &dp)
{
    if (index == 0)
    {
        if (weight[0] <= capacity)
        {
            return value[0];
        }
        else
        {
            return 0;
        }
    }
    if (dp[index][capacity] != -1)
    {
        return dp[index][capacity];
    }
    int include = 0;
    if (weight[index] <= capacity)
    {
        include = solve_using_memo(weight, value, index - 1, capacity - weight[index], dp) + value[index];
    }
    int exclude = solve_using_memo(weight, value, index - 1, capacity, dp);

    int ans = max(exclude, include);
    dp[index][capacity] = ans;
    return ans;
}

int solve_using_tabulation(int weight[], int value[], int n, int capacity)
{
    vector<vector<int>> dp(n + 1, vector<int>(capacity + 1, -1));

    for (int w = weight[0]; w <= capacity; w++)
    {
        if (weight[0] <= capacity)
        {
            dp[0][w] = value[0];
        }
        else
        {
            dp[0][w] = 0;
        }
    }
    for (int index = 1; index < n; index++)
    {
        for (int wt = 0; wt <= capacity; wt++)
        {
            int include = 0;
            if (weight[index] <= wt)
            {
                include = dp[index - 1][wt - weight[index]] + value[index];
            }
            int exclude = dp[index - 1][wt];

            dp[index][wt] = max(exclude, include);
        }
    }
    return dp[n - 1][capacity];
}

int space_optimised(int weight[], int value[], int n, int capacity)
{
    vector<int> prev(capacity + 1, 0);
    vector<int> current(capacity + 1, 0);
    for (int w = weight[0]; w <= capacity; w++)
    {
        if (weight[0] <= capacity)
        {
            prev[w] = value[0];
        }
        else
        {
            prev[w] = 0;
        }
    }
    for (int index = 1; index < n; index++)
    {
        for (int wt = 0; wt <= capacity; wt++)
        {
            int include = 0;
            if (weight[index] <= wt)
            {
                include = prev[wt - weight[index]] + value[index];
            }
            int exclude = prev[wt];

            current[wt] = max(exclude, include);
        }
        prev = current;
    }
    return prev[capacity];
}
int space_optimised_more(int weight[], int value[], int n, int capacity)
{
    // vector<int> prev(capacity + 1, 0);
    vector<int> current(capacity + 1, 0);
    for (int w = weight[0]; w <= capacity; w++)
    {
        if (weight[0] <= capacity)
        {
            current[w] = value[0];
        }
        else
        {
            current[w] = 0;
        }
    }
    for (int index = 1; index < n; index++)
    {
        for (int wt = capacity; wt >=0; wt--)
        {
            int include = 0;
            if (weight[index] <= wt)
            {
                include = current[wt - weight[index]] + value[index];
            }
            int exclude = current[wt];

            current[wt] = max(exclude, include);
        }
        // prev = current;
    }
    return current[capacity];
}
int main()
{
    int weight[] = {4, 5, 1};
    int value[] = {1, 2, 3};
    int n = 3;
    int capacity = 4;

    vector<vector<int>> dp(n, vector<int>(capacity + 1, -1));

    int ans = space_optimised_more(weight, value, n, capacity);
    cout << "ans -> " << ans;
    return 0;
}