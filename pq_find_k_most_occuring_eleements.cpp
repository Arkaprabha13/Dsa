#include <bits/stdc++.h>
using namespace std;
struct MYcmp
{
    bool operator()(pair<int, int> p1, pair<int, int> p2)
    {
        if (p1.second == p2.second)
        {
            return p1.first > p2.first;
        }
        else
            return p1.second < p2.second;
    }
};
void most_frequent_element(int arr[], int n, int k)
{
    unordered_map<int, int> m;
    for (int i = 0; i < n; i++)
    {
        m[arr[i]]++;
    }
    vector<pair<int, int>> freq(m.begin(), m.end());
    priority_queue<pair<int, int>, vector<pair<int, int>>, MYcmp> pq(freq.begin(), freq.end());
    for (int i = 0; i < k; i++)
    {
        cout << pq.top().first << " "; // printing 10
        pq.pop();
    }
}
void find_k_freq(int arr[], int n, int k)
{
    unordered_map<int, int> m;
    for (int i = 0; i < n; i++)
    {
        m[arr[i]]++;
    }
    vector<int> freq[n + 1];
    for (auto x : m)
    {
        freq[x.second].push_back(x.first);
    }
    int c = 0;
    for (int i = n; i >= 0; i--)
    {
        for (int x : freq[i])
        {
            cout << x << " ";
            c++;
            if (c == k)
            {
                return;
            }
        }
    }
}
void first_freq(int arr[], int n, int k)
{
    unordered_map<int, int> m;
    for (int i = 0; i < n; i++)
    {
        m[arr[i]]++;
    }
    vector<int> freq[n + 1];
    for (int i = 0; i < n; i++)
    {
        int f = m[arr[i]];
        if (f != -1)
        {
            freq[f].push_back(arr[i]);
            m[arr[i]] = -1;
        }
    }

    int c = 0;
    for (int i = n; i >= 0; i--)
    {
        for (int x : freq[i])
        {
            cout << x << " ";
            c++;
            if (c == k)
            {
                return;
            }
        }
    }
}
int main()
{
    int a[] = {4,3, 1, 4, 4, 5, 2, 6, 1};

    // Value of k and n
    int k = 2, n = 9;
    first_freq(a, n, k);
    return 0;
}

/*

    a[]={10,20,10,20,30,30,10}
    k=2
    m={(10,3),(20,2),(30,2)}
    pq->
        (10,3)
        /   \
    (30,2) (20,2)
*/