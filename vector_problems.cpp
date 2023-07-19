#include <bits/stdc++.h>
using namespace std;
vector<int> getsmaller(int arr[], int n, int k)
{
    vector<int> result;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] < k)
        {
            result.push_back(arr[i]);
        }
    }
    return result;
}
// void my_comparision(pair<int, int> p1, pair<int, int> p2)
// {
//     return p1.second > p2.second;
// }
void print_sorted_by_marks(int roll[], int marks[], int n)
{
    vector<pair<int, int>> v;
    for (int i = 0; i < n; i++)
    {
        v.push_back({roll[i], marks[i]});
    }
    // sort(v.begin(), v.end(), my_comparision);
    sort(v.begin(),v.end(),greater<pair<int,int>>());
    for(int i=0;i<n;i++)
    {
        cout<<v[i].first<<" "<<v[i].second<<endl;
    }
}
int main()
{
    int a[] = {10, 5, 30, 40, 20};
    int n = 5, k = 25;

    vector<int> res = getsmaller(a, n, k);
    for (int x : res)
    {
        cout << x << " ";
    }
    int roll_no[] = { 17, 20, 15, 1, 5 };
    int marks[] = { 80, 75, 93, 78, 84 };
    int m = sizeof(roll_no) / sizeof(roll_no[0]);
cout<<endl;
    print_sorted_by_marks(roll_no, marks, m);
    return 0;
}
