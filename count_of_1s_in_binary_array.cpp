#include <bits/stdc++.h>
using namespace std;
int count_ones(int *a, int n)
{
    int low = 0;
    int high = n - 1;
    while (low <= high)
    {
        int mid = (low + high) / 2;
        if (a[mid] == 0)
        {
            low = mid + 1;
        }
        else
        {
            if (mid == 0 || a[mid - 1] == 0)
            {
                return n - mid;
            }
            else
            {
                high = mid - 1;
            }
        }
    }
    return 0;
}
int main()
{
    int arr[] = {0, 0, 1, 1, 1, 1}, n = 6;

    cout << count_ones(arr, n);

    return 0;
}