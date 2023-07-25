#include <bits/stdc++.h>
using namespace std;
int purchase_max(int arr[], int n, int sum)
{
    priority_queue<int, vector<int>, greater<int>> pq(arr, arr + n);
    int result = 0;
    while (!pq.empty() && sum >= 0 && pq.top() <= sum)
    {
        sum -= pq.top();
        pq.pop();
        result++;
    }
    return result;
}
int main()
{
    return 0;
}