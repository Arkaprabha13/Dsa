#include <bits/stdc++.h>
using namespace std;

int main()
{
    unordered_map<string, int> m;
    m["gfg"] = 20;
    m["ide"] = 30;
    m.insert({"courses", 15});
    m.insert({"arka", 13});
    for (auto x : m)
    {
        cout<< x.first << " "<<x.second<<"\n";
    }
    if(m.find("ide")!=m.end())
    {
        cout<<"FOUND\n";
    }
    else{
        cout<<"Not found";
    }
    for(auto it=m.begin();it!=m.end();it++)
    {
        cout<<(*it).first<<" "<<(*it).second<<"\n";
    }
    return 0;
}
