#include <bits/stdc++.h>
using namespace std;
set<int> s;
void insert(int x)
{
    s.insert(x);
}
bool search(int x)
{
    return (s.find(x) != s.end());
}
void Delete(int x)
{
    s.erase(x);
}
int get_floor(int x)
{
    auto it = s.lower_bound(x);
    if (it == s.begin())
    {
        if (*it == x)
        {
            return *it;
        }
        else
        {
            return INT_MIN;
        }
    }
    else
    {
        if (it != s.end() && *it == x)
        {
            return *it;
        }
        it--;
        return *it;
    }
}
int get_ceiling(int x)
{
    auto it = s.lower_bound(x);
    if (it == s.end())
    {
        return INT_MAX;
    }
    else
    {
        return *it;
    }
}
int main()
{
    return 0;
}