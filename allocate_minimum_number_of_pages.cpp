#include <bits/stdc++.h>
using namespace std;
int sum(int arr[], int b, int e)
{
    int s = 0;
    for (int i = b; i <= e; i++)
        s += arr[i];
    return s;
}

int minPages(int arr[], int n, int k)
{
    if (k == 1)
        return sum(arr, 0, n - 1);
    if (n == 1)
        return arr[0];
    int res = INT_MAX;
    for (int i = 1; i < n; i++)
    {
        res = min(res, max(minPages(arr, i, k - 1), sum(arr, i, n - 1)));
    }
    return res;
}
bool is_feasible(int a[],int n,int k,int ans)
{
    int req=1;int sum=0;
    for(int i=0;i<n;i++)
    {
        if(sum+a[i]>ans)
        {
            req++;
            sum=a[i];
        }
        else
        {
            sum+=a[i];
        }

    }
    return (req==k);
}
int minimum_pages_for_each_student(int a[], int n, int k)
{
    int sum = 0;
    int maxi = 0;
    for (int i = 0; i < n; i++)
    {
        sum += a[i];
        maxi = max(maxi, a[i]);
    }
    int low = maxi;
    int high = sum;
    int result = 0;
    while (low <= high)
    {
        int mid = (low + high) / 2;
        if (is_feasible(a, n, k, mid))
        {
            result = mid; // if feasible go to left side so decrease the high
            high = mid - 1;
        }
        else // if not feasible then go to right side so increment low
        {
            low = mid + 1;
        }
    }
    return result;
}
int main()
{
    int arr[] = {10, 20, 10, 30};
    int n = sizeof(arr) / sizeof(arr[0]);
    int k = 2;

    cout << minimum_pages_for_each_student(arr, n, k);
    return 0;
}