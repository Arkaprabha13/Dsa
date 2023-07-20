#include<bits/stdc++.h>
using namespace std;
void print_sorted_array_with_index(int arr[],int n)
{
    vector<pair<int,int>>v;
    for(int i=0;i<n;i++)
    {
        v.push_back({arr[i],i});
    }
    sort(v.begin(),v.end());
    for(auto x:v)
    {
        cout << x.first << "\t"
             << x.second << endl;
    }
}
int main()
{
        int arr[] = { 2, 5, 3, 7, 1 };
    int n = sizeof(arr) / sizeof(arr[0]);
    print_sorted_array_with_index(arr, n);

return 0;
}