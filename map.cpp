#include <bits/stdc++.h>
using namespace std;

int main()
{
    // map<int, int> m;
    // m.insert({10, 20});
    // m[5] = 100;
    // m.insert({3, 30});
    // for (auto x : m)
    // {
    //     cout << x.first << " " << x.second << " next -> ";
    // }
    // cout << endl
    //      << "size of m -> " << m.size();
    // cout << endl
    //      << m[20] << " inserted !!!!! not present" << endl;
    // m[3] = 30000;

    // cout << m[3] << " Updated !!" << endl;
    // m.at(3) = 1010101;
    // cout << m[3] << " Updated !!";
    // for(auto it =m.find(3);it!=m.end();it++)
    // {
    //     cout<<(*it).first<<" "<<(*it).second<<endl;
    // }
    map<int, string> mapi;
    mapi.insert({5, "gfg"});
    mapi.insert({2, "ide"});
    mapi.insert({1, "practice"});
    // map<int,int>::iterator it;
    for (auto itr = mapi.find(2); itr != mapi.end(); itr++) // dont write it -> error
    {
        cout << (*itr).first << " " << (*itr).second << endl;
    }
    if (mapi.count(2) == 0)
    {
        cout << "Not found";
    }
    else
    {
        cout << "found";
    }
    // empty map container
    map<int, int> m;

    // Insert elements using insert() function
    m.insert({10, 100});
    m.insert({30, 300});

    // Inserting using "[]" operator
    m[20] = 200;

    // Donot provide any value with key 40
    // The operator access the key and since
    // it doesnot exists, it will insert defaut
    // value of int
    m[40];

    // Traverseing map
    cout << "The map is : \n";
    cout << "\tKEY\tELEMENT\n";
    for (auto itr = m.begin(); itr != m.end(); itr++)
    {
        cout << '\t' << itr->first
             << '\t' << itr->second << '\n';
    }
    cout << endl;

    // We can also update the value of an existing
    // key-value pair using "[]" operator which
    // is not possible with insert() function
    m[40] = 400;

    // Traverseing map
    cout << "\nThe map is : \n";
    cout << "\tKEY\tELEMENT\n";
    for (auto itr = m.begin(); itr != m.end(); itr++)
    {
        cout << '\t' << itr->first
             << '\t' << itr->second << '\n';
    }

    return 0;
}