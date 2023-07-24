#include <bits/stdc++.h>
using namespace std;
void print_k_largest_elements(int arr[], int n, int k)
{
    priority_queue<int, vector<int>, greater<int>> pq(arr, arr + k);
    for (int i = k; i < n; i++)
    {
        if (arr[i] > pq.top())
        {
            pq.pop();
            pq.push(arr[i]);
        }
    }
    while (!pq.empty())
    {
        cout << pq.top();
        pq.pop();
    }
}
int main()
{
    return 0;
}