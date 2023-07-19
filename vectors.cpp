#include <bits/stdc++.h>
using namespace std;

int main()
{
    vector<int> v{10, 5, 20, 15};
    auto it = v.insert(v.begin(), 100);
    v.insert(v.begin() + 2, 200);
    v.insert(v.begin(), 2, 300); // the middle value is for number of values to be inserted
    vector<int> v2;
    v2.insert(v2.begin(), v.begin(), v.begin() + 2);
    for (int x : v)
    {
        cout << x << " ";
    }
    cout << endl;
    for (int x : v2)
    {
        cout << x << " ";
    }
    v.erase(v.begin());
    cout << endl;
    for (int x : v)
    {
        cout << x << " ";
    }
    v.erase(v.begin(), v.end() - 1);
    cout << endl;
    for (int x : v)
    {
        cout << x << " ";
    }
    v.clear();
    for (int x : v)
    {
        cout << x << " ";
    }
    if(v.empty()==true)
    {
        cout<<"\nempty\n";
    }
    else{
        cout<<"\n non empty \n";
    }
    vector<int> v1{10, 5, 20, 15};
    for(int x:v1)
    {
        cout<<x<<" ";
    }
    v1.resize(3);
    cout<<endl;
    for(int x:v1)
    {
        cout<<x<<" ";
    }
    v1.resize(5);
    cout<<endl;
    for(int x:v1)
    {
        cout<<x<<" ";
    }
    v1.resize(7,100);
    cout<<endl;
    for(int x:v1)
    {
        cout<<x<<" ";
    }
    return 0;
}