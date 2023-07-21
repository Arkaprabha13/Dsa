#include <bits/stdc++.h>
using namespace std;
list<int> l;
void insert(int x)
{
    l.push_back(x);
}
void print()
{
    for (int it : l)
    {
        cout << (it) << " ";
    }
}
void replace(int x, vector<int> sequence)
{
    auto it = find(l.begin(), l.end(), x);
    if (it == l.end())
    {
        return;
    }
    it = l.erase(it);
    l.insert(it, sequence.begin(), sequence.end());
}

int main()
{
    insert(3);
    insert(10);
    insert(2);
    insert(10);
    // insert(3);
    print();
    vector<int> v = {20, 30, 40};
    replace(10, v);
    cout << endl;
    print();
    return 0;
}