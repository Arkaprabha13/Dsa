#include <bits/stdc++.h>
using namespace std;
int get_square_root(int x)
{
    int low = 1;
    int high = x;
    int ans = -1;
    while (low <= high)
    {
        int mid = (low + high) / 2;
        int middle_sq = mid * mid;
        if (middle_sq == x)
        {
            return mid;
        }
        else if (middle_sq > x)
        {
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
            ans = mid;
        }
    }
    return ans;
}
int main()
{
    cout << get_square_root(10);
    return 0;
}