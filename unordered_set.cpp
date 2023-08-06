#include <bits/stdc++.h>
using namespace std;

int main()
{
    unordered_set<int> s;
    s.insert(10);
    s.insert(100);
    s.insert(1000);
    s.insert(10000);
    s.insert(100000); // duplicates cannot be inserted
    for (int x : s)
    {
        cout << x << " "; // it doesnot maintain any order for the elements
    }
    cout << endl;
    for (auto it = s.begin(); it != s.end(); it++)
    {
        cout << (*it) << " ";
    }
    return 0;
}