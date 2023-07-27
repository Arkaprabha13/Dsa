#include <bits/stdc++.h>
using namespace std;
int get_water(int *a, int n)
{
    int result = 0;
    for (int i = 1; i < n - 1; i++)
    {
        int left_max = a[i];
        for (int j = 0; j < i; j++)
        {
            left_max = max(left_max, a[j]);
        }
        int right_max = a[i];
        for (int j = i + 1; j < n; j++)
        {
            right_max = max(right_max, a[j]);
        }
        result += min(left_max, right_max) - a[i];
    }
    return result;
}
int efficient_get_water(int *a, int n)
{
    int result = 0;
    int left_max[n], right_max[n - 1];
    left_max[0] = a[0], right_max[0] = a[n - 1];

    for (int i = 1; i < n; i++)
    {
        left_max[i] = max(a[i], left_max[i - 1]);
    }
    right_max[n - 1] = a[n - 1];
    for (int i = n - 2; i >= 0; i--)
    {
        right_max[i] = max(a[i], right_max[i + 1]);
    }
    for (int i = 1; i < n - 1; i++)
    {
        result += (min(left_max[i], right_max[i]) - a[i]);
    }
    return result;

    return result;
}
int main()
{
    int n;
    cout << "N-> ";
    cin >> n;
    cout << endl;
    int *a = new int[n]; // Allocate memory for the array

    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    int water = efficient_get_water(a, n);
    cout << "water->" << water << " ";
    return 0;
}
/*       0
         0
  0      0
  0    0 0
  0  0 0 0
  */