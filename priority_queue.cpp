#include <bits/stdc++.h>
using namespace std;

int main()
{
    priority_queue<int, vector<int>, greater<int>> pq; // MIN HEAP
    pq.push(10);
    pq.push(15);
    pq.push(5);
    // pq.push(10);
    cout << "pq->size -> " << pq.size() << " pq->top -> " << pq.top() << "\n";
    while (!pq.empty())
    {
        cout << pq.top() << " ";
        pq.pop();
    }
    cout << "\nNEXT way\n";
    int a[] = {10, 15, 5};
    // for(int i=0;i<3;i++)         for printing 5 10 15
    // {
    //     a[i]=-a[i];
    // }
    // if not used then 15 10 5
    priority_queue<int> p(a, a + 3);
    while (!p.empty())
    {
        cout << p.top() << " ";
        // cout << -p.top() << " ";
        p.pop();
    }
    return 0;
}