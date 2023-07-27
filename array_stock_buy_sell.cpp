#include <bits/stdc++.h>
using namespace std;
int max_profit(int *price, int start, int end)
{
    // int start = 0, end = n - 1;
    if (end <= start)
    {
        return 0;
    }
    int profit = 0;
    for (int i = start; i < end; i++)
    {
        for (int j = i + 1; j <= end; j++)
        {
            if (price[j] > price[i])
            {
                // int current_profit = price[j] - price[i] + max_profit(price, start, i - 1) + max_profit(price, j + 1, end);
                // profit = max(profit, current_profit);
                int current_profit = price[j] - price[i] + max_profit(price, start, i - 1) + max_profit(price, j + 1, end);
                profit = max(profit, current_profit);
            }
        }
    }
    return profit;
}
int max_profit_efficient(int *price, int n)
{
    int profit = 0;
    for (int i = 1; i < n; i++)
    {
        if (price[i] > price[i - 1])
        {
            profit += price[i] - price[i - 1];
        }
    }
    return profit;
}
int main()
{
    int n;
    cout << "N-> ";
    cin >> n;
    cout << endl;
    int *a = new int[n]; // Allocate memory for the array

    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    cout << "Profit -> " << max_profit(a, 0, n - 1);
    cout << "\nProfit -> " << max_profit_efficient(a, n);
    return 0;
}