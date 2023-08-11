#include <bits/stdc++.h>
using namespace std;
vector<pair<int, int>> v;
void set(int id, int balance)
{
    for (int i = 0; i < v.size(); i++)
    {
        if (v[i].first == id)
        {
            v[i].second = balance;
            return;
        }
    }
    v.push_back({id, balance});
}
int get(int id)
{
    for (int i = 0; i < v.size(); i++)
    {
        if (v[i].first == id)
        {
            return v[i].second;
        }
    }
    return 0;
}
// efficient
unordered_map<int, int> m;
int getmap(int id)
{
    return m[id];
}
void setmap(int id, int balance)
{
    m[id] = balance;
    return;
}
int main()
{
    return 0;
}