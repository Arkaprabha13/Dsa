#include <bits/stdc++.h>
using namespace std;
map<int, string> m;
multimap<int, string> mm;
void add_multi_map(int price, string name)
{
    mm.insert({price, name});
}
void find_multimap(int price)
{
    auto it = mm.equal_range(price);
    for (auto it1 = it.first; it1 != it.second; it1++)
    {
        cout << it1->second << " " << it1->first << endl;
    }
}

//  other functions are same for map and multimap

void add(int price, string name)
{
    m[price] = name;
}
string find(int price)
{
    auto result = m.find(price);
    if (result == m.end())
    {
        return "";
    }
    else
    {
        return result->second;
    }
}
void print_sorted()
{
    for (auto x : m)
    {
        cout << x.first << " " << x.second << endl;
    }
}
void print_greater_sorted(int price)
{
    auto it = m.upper_bound(price);
    while (it != m.end())
    {
        cout << it->second << " " << it->first << endl;
        it++;
    }
}
void print_smaller_sorted(int price)
{
    auto it1 = m.upper_bound(price);
    for (auto it2 = m.begin(); it2 != it1; it2++)
    {
        cout << it2->second << " " << it2->first << endl;
    }
}

int main()
{

    add(100, "roll");
    add(500, "biriyani");
    add(90, "Chola bhature");
    add(110, "lacha paratha chicken");

    print_sorted();
    return 0;
}