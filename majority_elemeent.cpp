#include <bits/stdc++.h>
using namespace std;
int majority(int a[], int n)
{
    for (int i = 0; i < n; i++)
    {
        int count = 1;
        for (int j = i + 1; j < n; j++)
        {
            if (a[i] == a[j])
            {
                count++;
            }
            if (count > n / 2)
            {
                return i;
            }
        }
        return -1;
    }
}
//  Moore’s Voting Algorithm
int find_majority(int a[], int n)
{

    int res = 0, count = 1;

    for (int i = 1; i < n; i++)
    {
        if (a[res] == a[i])
            count++;
        else
            count--;

        if (count == 0)
        {
            res = i;
            count = 1;
        }
    }

    count = 0;

    for (int i = 0; i < n; i++)
        if (a[res] == a[i])
            count++;

    if (count <= n / 2)
        res = -1;

    return res;
}
int main()
{
    int arr[] = {8, 8, 6, 6, 6, 4, 6}, n = 7;

    cout << find_maj(arr, n);
    return 0;
}