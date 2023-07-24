#include <bits/stdc++.h>
using namespace std;

// USING MAX HEAP
void my_sort(int arr[], int n)
{
    priority_queue<int> pq(arr, arr + n);
    // for (int i = n - 1; i >= 0; i--)
    // {
    //     // arr[i] = pq.top();
    //     // pq.pop();
    //     pq.push(arr[i]);
    // }
    while (!pq.empty()) {
    cout << pq.top() << " ";
        pq.pop();
    }
}
// using min heap
void sorting(int arr[], int n)
{
    priority_queue<int, vector<int>, greater<int>> pq;
    for (int i = 0; i < n; i++)
    {
        // arr[i] = pq.top();
        // pq.pop();
        pq.push(arr[i]);
    }
     while (!pq.empty()) {
        cout << pq.top() << " ";
        pq.pop();
    }
}
int main()
{
    int n;
    cout << "N-> ";
    cin >> n;
    cout << endl;
    int *a;

    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    // my_sort(a, n);
    my_sort(a,n);

    // for (int i = 0; i < n; i++)
    // {
    //     cout << a[i];
    // }
    return 0;
}