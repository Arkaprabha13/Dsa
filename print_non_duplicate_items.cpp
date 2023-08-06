#include <bits/stdc++.h>
using namespace std;
void print_distinct_elements(int a[], int n)
{
    for (int i = 0; i < n; i++)
    {
        bool flag = false;
        for (int j = 0; j < n; j++)
        {
            if (a[i] == a[j])
            {
                flag = true;
            }
        }
        if (flag == false)
        {
            cout << a[i] << " ";
        }
    }
}
void effcienet_solution(int a[], int n)
{
    unordered_set<int> s;
    for (int i = 0; i < n; i++)
    {
        if (s.find(a[i]) == s.end())
        {
            cout << a[i] << " ";
            s.insert(a[i]);
        }
    }
}
int main()
{
    int arr[] = {7, 2, 9, 4, 3, 2, 10, 4};
    int n = 7;
    effcienet_solution(arr,n);
    return 0;
}